#include <algorithm>
#include <utility>
#include <vector>
#include <iostream>
#include <array>
#include <numeric>
#include <memory>
#include <random>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;
using vi = vector<int>;

int N;
string s;

string solve() {
  cin >> N;
  cin >> s;
  if (s.size() == 1 || s[0] == s[1]) {
    return string(1, s[0]) + s[0];
  }
  int pos = 0;
  while (pos < N - 1) {
    if (s[pos] < s[pos + 1]) {
      break;
    }
    pos++;
  }
  string ans = s.substr(0, pos + 1);
  while (pos >= 0) {
    ans += s[pos];
    pos--;
  }
  return ans;
}

int main() {
  int T;
  cin >> T;
  for (int i = 1; i <= T; ++i) {
    auto ans = solve();
    cout << ans << endl;
  }
}