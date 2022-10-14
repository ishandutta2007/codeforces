/**
 *    author:  wxhtzdy
 *    created: 16.09.2022 19:02:41
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n;
  cin >> n;                 
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] %= 3;
  }        
  vector<vector<int>> c(3);
  for (int i = 0; i < n; i++) {
    c[a[i]].push_back(i);
  }   
  if ((int) c[0].size() <= n / 2) {
    cout << 0 << '\n';
    string ans = string(n, '1');   
    for (int i : c[0]) {
      ans[i] = '0';
    }                        
    int need = n / 2 - c[0].size();
    for (int i = 0; i < n; i++) {
      if (a[i] != 0 && need > 0) {
        ans[i] = '0';
        need--;
      }
    }
    cout << ans << '\n';
  } else {
    cout << 2 << '\n';
    string ans = string(n, '1');
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) {
      return a[i] < a[j];
    });
    for (int i = 0; i < n / 2; i++) {
      ans[order[i]] = '0';
    }
    cout << ans << '\n';
  }
  return 0;
}