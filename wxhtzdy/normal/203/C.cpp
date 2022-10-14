/**
 *    author:  milos
 *    created: 07.06.2021 20:46:37       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int a, b;
  cin >> a >> b;           
  vector<int> r(n);
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;  
    r[i] = x * a + b * y;
  }
  vector<int> ord(n);
  iota(ord.begin(), ord.end(), 0);
  sort(ord.begin(), ord.end(), [&](int i, int j) {
    return r[i] < r[j];  
  });
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    if (r[ord[i]] <= m) {
      ans.push_back(ord[i]);
      m -= r[ord[i]]; 
    }
  }
  cout << ans.size() << '\n';
  for (int i : ans) {
    cout << i + 1 << " ";  
  }
  cout << '\n';
  return 0;
}