/**
 *    author:  milos
 *    created: 23.02.2021 09:30:12       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k, m;
  cin >> n >> k >> m;
  vector<vector<int>> b(m);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    b[x % m].push_back(x);
  }        
  for (int i = 0; i < m; i++) {
    sort(b[i].begin(), b[i].end());
    if ((int) b[i].size() >= k) {
      cout << "Yes" << '\n';
      for (int j = 0; j < (int) k; j++) {
        cout << b[i][j] << " ";
      }
      return 0;
    }
  }
  cout << "No" << '\n';
  return 0;
}