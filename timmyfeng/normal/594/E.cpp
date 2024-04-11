#include <bits/stdc++.h>
using namespace std;

string reversed(string s) {
  reverse(s.begin(), s.end());
  return s;
}

string min(string s) {
  return min(s, reversed(s));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int o;
  string s;
  cin >> s >> o;
  int n = s.size();
  s = reversed(s) + "#" + s;

  vector<array<int, 2>> lyndon = {{0, 0}};
  for (int i = 0; i < n; ) {
    int j = i + 1, k = i;
    while (j < n && s[j] >= s[k]) {
      if (s[j] > s[k]) {
        k = i;
      } else {
        ++k;
      }
      ++j;
    }
    while (i <= k) {
      i += j - k;
    }
    lyndon.push_back({i, j - k});
  }

  vector<int> z(s.size());
  for (int i = 1, l = 0, r = 0; i < (int) s.size(); ++i) {
    z[i] = (i >= r) ? 0 : min(r - i, z[i - l]);
    for ( ; i + z[i] < (int) s.size() && s[i + z[i]] == s[z[i]]; ++z[i]);
    if (i + z[i] > r) {
      l = i, r = i + z[i];
    }
  }

  string prefix;
  while (lyndon.size() > 1 && o > 2) {
    int i = 0, p = 0;
    while (p == 0 || (p == 1 && lyndon.back()[1] == 1)) {
      i = lyndon.back()[0], p = lyndon.back()[1];;
      lyndon.pop_back();
      prefix += s.substr(lyndon.back()[0], i - lyndon.back()[0]);
    }
    --o;
  }

  int m = lyndon.back()[0];
  string suffix = min(s.substr(0, m));
  if (o == 2) {
    for (int i = 0; i < min(2, (int) lyndon.size() - 1); ++i) {
      int j = lyndon[lyndon.size() - 2 - i][0];
      suffix = min(suffix, s.substr(j, m - j) + min(s.substr(0, j)));
    }

    int j = 1;
    for (int i = 2; i < m; ++i) {
      int d = i - j, c = 2 * n + 1 - i;
      if (z[c] < d) {
        if (s[z[c]] < s[c + z[c]]) {
          j = i;
        }
      } else {
        if (s[d + z[d]] < s[z[d]]) {
          j = i;
        }
      }
    }

    suffix = min(suffix, reversed(s.substr(j, m - j)) + s.substr(0, j));
  }

  cout << prefix << suffix << "\n";
}