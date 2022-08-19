/**
 *    author:  tourist
 *    created: 31.07.2022 17:33:18       
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int N = 200;
  vector<int> g(N);
  g[0] = 0;
  for (int i = 1; i < N; i++) {
    set<int> s;
    for (int j = 1; j < i; j++) {
      int x = g[j - 1];
      int y = g[i - j - 1];
      s.insert(x ^ y);
    }
    while (s.find(g[i]) != s.end()) {
      g[i] += 1;
    }
  }
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int nr = 0, nb = 0;
    for (char c : s) {
      if (c == 'R') {
        nr += 1;
      } else {
        nb += 1;
      }
    }
    if (nr > nb) {
      cout << "Alice" << '\n';
      continue;
    }
    if (nr < nb) {
      cout << "Bob" << '\n';
      continue;
    }
    int x = 0;
    int beg = 0;
    while (beg < n) {
      int end = beg;
      while (end + 1 < n && s[end + 1] != s[end]) {
        end += 1;
      }
      int len = end - beg + 1;
      while (len >= N) {
        len -= 34;
      }
      x ^= g[len];
      beg = end + 1;
    }
    cout << (x == 0 ? "Bob" : "Alice") << '\n';
  }
  return 0;
}