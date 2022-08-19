/**
 *    author:  tourist
 *    created: 28.11.2021 17:38:41       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int M = (int) 1e6 + 10;
  vector<bool> pr(M, true);
  pr[0] = pr[1] = false;
  for (int i = 2; i < M; i++) {
    if (pr[i]) {
      for (int j = i + i; j < M; j += i) {
        pr[j] = false;
      }
    }
  }
  int tt;
  cin >> tt;
  while (tt--) {
    int n, e;
    cin >> n >> e;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> L(n);
    vector<int> R(n);
    for (int z = 0; z < e; z++) {
      int i = z;
      int cc = 0;
      while (i < n) {
        if (a[i] > 1) {
          L[i] = cc + 1;
          cc = 0;
        } else {
          cc += 1;
        }
        i += e;
      }
      cc = 0;
      i -= e;
      while (i >= 0) {
        if (a[i] > 1) {
          R[i] = cc + 1;
          cc = 0;
        } else {
          cc += 1;
        }
        i -= e;
      }
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      if (pr[a[i]]) {
        ans += L[i] * 1LL * R[i] - 1;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}