/**
 *    author:  wxhtzdy
 *    created: 22.10.2022 05:47:41
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n;
  cin >> n;
  int m = (n + 1) / 2;
  vector<int> a(n);
  for (int i = 0; i < m; i++) {
    cin >> a[i];
  }                                   
  int x;
  cin >> x;
  for (int i = m; i < n; i++) {
    a[i] = x;
  }
  if (x > 0) {
    long long s = accumulate(a.begin(), a.end(), 0LL);
    if (s > 0) {
      cout << n << '\n';
    } else {
      cout << -1 << '\n';
    }
    return 0;
  }          
  long long s = 0;
  vector<bool> can(n + 1);
  for (int i = n - 1; i >= 0; i--) {
    s += a[i];
    if (s > 0) {
      can[n - i] = true;
    }
  }  
  if (can == vector<bool>(n + 1, false)) {
    cout << -1 << '\n';
    return 0;
  }
  vector<long long> pref(n);
  pref[0] = a[0];
  for (int i = 1; i < n; i++) {
    pref[i] = pref[i - 1] + a[i];
  }   
  auto Get = [&](int l, int r) {
    long long res = pref[r];
    if (l > 0) {
      res -= pref[l - 1];
    }
    return res;
  };
  int k = 0;
  while (!can[k]) {
    k++;
  }
  vector<int> v;
  for (int i = 0; i + k <= n; i++) {
    /* if (Get(i, i + k - 1) <= 0) {
      cout << -1 << '\n';
      return 0;
    } */
    int l = k, r = n - i, vv = 0;
    while (l <= r) {
      int mid = l + r >> 1;
      if (Get(i, i + mid - 1) > 0) {
        vv = mid;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }  
    v.push_back(vv);
  }
  int sz = (int) v.size();
  vector<int> mn(sz);
  mn[0] = v[0];
  for (int i = 1; i < sz; i++) {
    mn[i] = min(mn[i - 1], v[i]);
  }
  for (int l = 1; l <= n; l++) {
    if (can[l] && mn[n - l] >= l) {
      cout << l << '\n';
      return 0;
    }
  }
  cout << -1 << '\n';
  return 0;
}