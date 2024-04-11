/**
 *    author:  wxhtzdy
 *    created: 23.08.2022 10:58:47
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n;
  cin >> n;
  n = (1 << n);
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<vector<long long>> mx(4 * n);
  vector<vector<long long>> sum(4 * n);
  vector<vector<long long>> pref(4 * n);
  vector<vector<long long>> suff(4 * n);
  function<void(int, int, int)> Dfs = [&](int v, int L, int R) {
    if (L == R) {
      mx[v].resize(1);
      sum[v].resize(1);
      pref[v].resize(1);
      suff[v].resize(1);
      mx[v][0] = max(0, a[L]);
      sum[v][0] = a[L];
      pref[v][0] = max(0, a[L]);
      suff[v][0] = max(0, a[L]);
      return;
    }
    int mid = L + R >> 1;
    Dfs(v * 2, L, mid);
    Dfs(v * 2 + 1, mid + 1, R);
    int sz = (int) mx[v * 2].size();
    mx[v].resize(sz * 2);
    sum[v].resize(sz * 2);
    pref[v].resize(sz * 2);
    suff[v].resize(sz * 2);
    for (int i = 0; i < sz; i++) {
      mx[v][i] = max({mx[v * 2][i], mx[v * 2 + 1][i], suff[v * 2][i] + pref[v * 2 + 1][i]});
      mx[v][i + sz] = max({mx[v * 2][i], mx[v * 2 + 1][i], pref[v * 2][i] + suff[v * 2 + 1][i]});
      sum[v][i] = sum[v][i + sz] = sum[v * 2][i] + sum[v * 2 + 1][i];
      pref[v][i] = max(pref[v * 2][i], sum[v * 2][i] + pref[v * 2 + 1][i]);
      pref[v][i + sz] = max(pref[v * 2 + 1][i], sum[v * 2 + 1][i] + pref[v * 2][i]);
      suff[v][i] = max(suff[v * 2 + 1][i], sum[v * 2 + 1][i] + suff[v * 2][i]);
      suff[v][i + sz] = max(suff[v * 2][i], sum[v * 2][i] + suff[v * 2 + 1][i]);
    }
  };
  Dfs(1, 0, n - 1);
  int q;
  cin >> q;
  int xr = 0;
  while (q--) {
    int x;
    cin >> x;
    xr ^= (1 << x);
    cout << mx[1][xr] << '\n';       
  }                                                 
  return 0;
}