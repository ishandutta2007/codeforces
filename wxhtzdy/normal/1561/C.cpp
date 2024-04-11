/**
 *    author:  milos
 *    created: 25.08.2021 05:44:30       
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
    vector<int> k(n);
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++) {
      cin >> k[i];
      a[i].resize(k[i]);         
      for (int j = 0; j < k[i]; j++) {
        cin >> a[i][j];
      }
    }
    vector<int> mx(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < k[i]; j++) {
        mx[i] = max(mx[i], a[i][j] - j);
      }
    }
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) {
      return mx[i] < mx[j];
    });
    long long ans = 0, sum = 0;
    for (int i = 0; i < n; i++) {
      ans = max(ans, mx[ord[i]] - sum + 1);
      sum += k[ord[i]];
    }
    cout << ans << '\n';
  }
  return 0;
}