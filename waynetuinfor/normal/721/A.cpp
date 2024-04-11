#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> v;
  int cnt = 0;
  int len = 0;
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] == 'W') {
      if (len > 0) {v.push_back(len); len = 0; cnt++;}
    } else {
      len++;
    }
  }
  if (len > 0) {v.push_back(len); cnt++;}
  cout << cnt << endl;
  for (int i = 0; i < v.size(); ++i) cout << v[i] << ' ';
  return 0;
}