/**
 *    author:  wxhtzdy
 *    created: 16.08.2022 16:44:54
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }      
    vector<int> win;
    vector<vector<int>> qs(n);
    int idx = 0;
    for (int i = 1; i < n; i++) {
      if (a[i] > a[idx]) {
        idx = i;        
      }
      win.push_back(idx);
      qs[idx].push_back(i);
    }
    while (q--) {
      int i, k;
      cin >> i >> k;
      --i; 
      int wins = lower_bound(qs[i].begin(), qs[i].end(), k + 1) - qs[i].begin();
      if (i == idx) {
        wins += max(0, k - (n - 1));     
      }
      cout << wins << '\n';
    }
  }                                                                    
  return 0;
}