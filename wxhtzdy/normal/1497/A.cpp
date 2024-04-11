/**
 *    author:  milos
 *    created: 17.03.2021 15:35:40       
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
    vector<int> a(n), cnt(105);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      cnt[a[i]]++; 
    }           
    vector<int> ans;
    for (int i = 0; i < 105; i++) {
      if (cnt[i] > 0) {
        ans.push_back(i);
        cnt[i]--;  
      } else {
        break;
      }
    }
    for (int i = 0; i < 105; i++) {
      while (cnt[i] > 0) {
        ans.push_back(i);
        cnt[i]--;
      }
    }
    for (int i = 0; i < n; i++) {
      cout << ans[i] << " ";
    }
    cout << '\n';
  }
  return 0;
}