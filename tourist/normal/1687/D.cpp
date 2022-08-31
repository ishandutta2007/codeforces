/**
 *    author:  tourist
 *    created: 03.06.2022 19:10:58       
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
  int n;
  cin >> n;
  const int M = (int) 2.1e6 + 10;
  vector<int> has(M);
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    has[a[i]] = 1;
  }
  vector<int> nxt(M);
  nxt[M - 1] = -1;
  for (int i = M - 2; i >= 0; i--) {
    nxt[i] = (has[i] ? i : nxt[i + 1]);
  }
  vector<int> prv(M);
  prv[0] = -1;
  for (int i = 1; i < M; i++) {
    prv[i] = (has[i] ? i : prv[i - 1]);
  }
  for (long long k = 1; ; k++) {
    if (a[0] > k * (k + 1)) {
      continue;
    }
    long long add = k * k - a[0];
    long long mx = max(0LL, a[0] - k * k);
    long long mn = k;
    long long x = k;
    while (true) {
      long long num = (x * (x + 1) + 1) - add;
      if (num >= M) {
        break;
      }
      if (nxt[num] != -1) {
        long long diff = max(0LL, x - (nxt[num] - num));
        mx = max(mx, diff);
      }
      x += 1;
    }
    x = k;
    while (true) {
      long long num = (x * (x + 1)) - add;
      if (num >= M) {
        break;
      }
      if (prv[num] != -1) {
        long long diff = num - prv[num];
        mn = min(mn, diff);
      }
      x += 1;
    }
    if (mx <= mn) {
      cout << k * k + mx - a[0] << '\n';
      break;
    }
  }
  return 0;
}