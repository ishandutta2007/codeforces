/**
 *  author: milos
 *  created: 12.01.2021 00:30:29
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, d;
  cin >> n >> m >> d;
  vector<int> a(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i];
  }
  int sum = 0;
  for (int i = 0; i < m; i++) {
    sum += a[i];
  }    
  int mx = (d - 1) * (m + 1);
  if (sum + mx < n || sum > n) {
    cout << "NO" << '\n';
    return 0;  
  }
  cout << "YES" << '\n';
  int need = n - sum;
  vector<int> ans(n, 0);
  vector<int> b;
  while (need > 0) {
    int x = min(need, d - 1);
    b.push_back(x);
    need -= x;
  }
  while ((int) b.size() < m + 1) {
    b.push_back(0);
  }
  for (int i = 0; i < m + (int) b.size(); i++) {
    if (i % 2 == 0) {
      for (int j = 0; j < b[i / 2]; j++) {
        cout << 0 << " ";
      }
      continue;
    }
    for (int j = 0; j < a[i / 2]; j++) {
      cout << (i + 1) / 2 << " ";  
    }
  }
  cout << '\n';
  return 0;
}