/**
 *  author: milos
 *  created: 06.01.2021 20:10:28
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);  
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> l(m), r(m);
  for (int i = 0; i < m; i++) {
    cin >> l[i] >> r[i];
    --l[i], --r[i];
  }         
  int ans = *max_element(a.begin(), a.end()) - *min_element(a.begin(), a.end()), j = -1;
  for (int i = 0; i < n; i++) { 
    vector<int> b = a;
    for (int j = 0; j < m; j++) {
      if (l[j] <= i && i <= r[j]) {
        continue;
      } 
      for (int k = l[j]; k <= r[j]; k++) {
        b[k] -= 1;  
      }
    }
    int my = *max_element(b.begin(), b.end()) - *min_element(b.begin(), b.end());
    if (my > ans) {
      j = i;
      ans = my;
    }
  }
  cout << ans << '\n';
  if (j == -1) {
    cout << 0 << '\n';
    return 0;
  }    
  vector<int> v;
  for (int i = 0; i < m; i++) {
    if (l[i] <= j && j <= r[i]) {
      continue;
    }
    v.push_back(i + 1);
  }
  cout << (int) v.size() << '\n';
  for (int i = 0; i < (int) v.size(); i++) {
    cout << v[i] << " ";
  }
  return 0;
}