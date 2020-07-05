#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <iterator>

using namespace std;

vector<string> getString(string& numString, int position) {
  if (position < numString.size()) {
    vector<string> strVec;
    char c = 'a' + numString[position] - '0' - 1;
    auto init = string(1, c);
    auto vec = getString(numString, position + 1);
    for (const auto& s:vec) {
      strVec.push_back(init + s);
    }
    
    auto twoChars = numString.substr(position, 2);
    if (stoi(twoChars) < 26 && twoChars.size() == 2) {
      char c2 = 'a' + stoi(twoChars) - 1;
      auto init2 = string(1, c2);
      auto vec2 = getString(numString, position + 2);
      for (const auto& s:vec2) {
        strVec.push_back(init2 + s);
      }
    }
    return strVec;
  } else {
    return {""};
  }
}

void findPerm(string& numString) {
  int counter = 0;
  auto&& vec = getString(numString, 0);
  copy(vec.begin(), vec.end(), ostream_iterator<string>(cout, " "));
}

int main() {
  int tc;
  stringstream ss;
  string line;
  fstream fin("alphabet-mapper.txt");

  getline(fin, line);
  ss << line;
  ss >> tc;
  ss.clear();

  for (int i=0; i < tc; ++i) {
    string numString;
    getline(fin, numString);
    findPerm(numString);
  }
}
