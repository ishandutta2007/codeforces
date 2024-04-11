/**
 *  author: milos
 *  created: 31.12.2020 01:58:07
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<long long> a(n);
    const int N = 60;
    vector<int> cnt(N, 0);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      for (long long j = 0; j < N; j++) {
        cnt[j] += a[i] >> j & 1;
      }
    }
    const int mod = 1e9 + 7;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      long long x = 0, y = 0;
      for (long long j = 0; j < N; j++) {
        long long z = (long long) 1 << j;
        if (z >= mod) {
          z %= mod;
        }
        if (a[i] >> j & 1) {
          x += z * n;
          y += z * cnt[j];
        } else {
          x += z * cnt[j];
        }
        if (x >= mod) {
          x %= mod;
        }
        if (y >= mod) {
          y %= mod;
        }
      }
      ans += x * y;
      if (ans >= mod) {
        ans %= mod;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}