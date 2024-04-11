/**
 *    author:  milos
 *    created: 21.02.2021 14:35:43       
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
  }
  vector<int> id(n);
  iota(id.begin(), id.end(), 0);
  sort(id.begin(), id.end(), [&](int i, int j){
    return a[i] < a[j];  
  });             
  vector<int> mn(n), mx(n);
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      mn[id[i]] = a[id[i + 1]] - a[id[i]];
    } else {
      if (i == n - 1) {
        mn[id[i]] = a[id[i]] - a[id[i - 1]];
      } else {
        mn[id[i]] = min(a[id[i + 1]] - a[id[i]], a[id[i]] - a[id[i - 1]]);
      }
    }
    mx[id[i]] = max(a[id[i]] - a[id[0]], a[id[n - 1]] - a[id[i]]);
  }
  for (int i = 0; i < n; i++) {
    cout << mn[i] << " " << mx[i] << '\n';
  }
  return 0;
}