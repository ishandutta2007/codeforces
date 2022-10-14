/**
 *    author:  wxhtzdy
 *    created: 08.07.2022 18:19:30
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
    int d = 2;
    vector<bool> used(n + 1);
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
      if (!used[i]) {
        ans.push_back(i);
        int x = 2 * i;
        while (x <= n) {
          if (!used[x]) {
            used[x] = true;
            ans.push_back(x);
          }
          x *= 2;
        }                
      }
    }
    cout << d << '\n';
    for (int i = 0; i < (int) ans.size(); i++) {
      if (i > 0) {
        cout << " ";
      }                   
      cout << ans[i];
    }
    cout << '\n';
  }                                                                    
  return 0;
}