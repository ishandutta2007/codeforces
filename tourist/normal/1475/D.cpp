/**
 *    author:  tourist
 *    created: 25.01.2021 18:03:48       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    if (sum < m) {
      cout << -1 << '\n';
      continue;
    }
    vector<int> k1;
    vector<int> k2;
    for (int i = 0; i < n; i++) {
      if (b[i] == 1) {
        k1.push_back(a[i]);
      } else {
        k2.push_back(a[i]);
      }
    }
    sort(k1.rbegin(), k1.rend());
    sort(k2.rbegin(), k2.rend());
    int ans = (int) 1e9;
    int n1 = (int) k1.size();
    int n2 = (int) k2.size();
    sum = 0;
    for (int i = 0; i < n2; i++) {
      sum += k2[i];
    }
    int j = 0;
    for (int i = n2; i >= 0; i--) {
      while (j < n1 && sum < m) {
        sum += k1[j];
        j += 1;
      }
      if (sum >= m) {
        ans = min(ans, 2 * i + j);
      }
      if (i > 0) {
        sum -= k2[i - 1];
      }
    }
    cout << ans << '\n';
  }
  return 0;
}