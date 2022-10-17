#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  string s;
  cin >> s;
  vector<int> vec;
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] != '+') {
      vec.push_back(s[i] - '0');
    }
  }
  sort(vec.begin(), vec.end());
  for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
    if (it == vec.end() - 1) {
      cout << *it << endl;
    } else {
      cout << *it << '+';
    }
  }
  return 0;
}