/**
 *    author:  milos
 *    created: 23.02.2021 10:11:56       
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
    vector<int> a(n);
    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      a[i]--;
      pos[a[i]] = i;
    }         
    int j = n;                 
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--) {
      vector<int> tmp;
      while (j > pos[i]) {
        j--;
        tmp.push_back(a[j]);
      }
      reverse(tmp.begin(), tmp.end());
      for (int aa : tmp) {
        ans.push_back(aa);
      }
    }
    while (j > 0) {
      j--;
      ans.push_back(a[j]);
    }
    for (int i = 0; i < n; i++) {
      cout << ans[i] + 1 << " ";  
    }
    cout << '\n';
  }
  return 0;
}