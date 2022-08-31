/**
 *    author:  tourist
 *    created: 05.10.2020 17:29:35       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, s, d;
  cin >> n >> s >> d;
  const int N = 1024;
  vector<bitset<N>> a(s);
  for (int i = 0; i < s; i++) {
    int foo;
    cin >> foo;
    while (foo--) {
      int j;
      cin >> j;
      --j;
      a[i][j] = 1;
    }
  }
  int half = 2 * s / 3;
  vector<pair<long long, int>> v(1 << half);
  for (int t = 0; t < (1 << half); t++) {
    bitset<N> x;
    for (int i = 0; i < half; i++) {
      if (t & (1 << i)) {
        x ^= a[i];
      }
    }
    long long h = 0;
    unsigned long long* z = (unsigned long long *)&x;
    for (int i = 0; i < N / 64; i++) {
      h = h * 239017239 + z[i];
    }
    v[t] = make_pair(h, __builtin_popcount(t));
  }
  sort(v.begin(), v.end());
  while (d--) {
    int foo;
    cin >> foo;
    bitset<N> y;
    while (foo--) {
      int j;
      cin >> j;
      --j;
      y[j] = 1;
    }
    int ans = 42;
    for (int t = 0; t < (1 << (s - half)); t++) {
      bitset<N> x = y;
      for (int i = half; i < s; i++) {
        if (t & (1 << (i - half))) {
          x ^= a[i];
        }
      }
      long long h = 0;
      unsigned long long* z = (unsigned long long *)&x;
      for (int i = 0; i < N / 64; i++) {
        h = h * 239017239 + z[i];
      }
      auto it = lower_bound(v.begin(), v.end(), make_pair(h, -1));
      if (it != v.end() && it->first == h) {
        ans = min(ans, it->second + __builtin_popcount(t));
      }
    }
    cout << (ans == 42 ? -1 : ans) << '\n';
  }
  return 0;
}