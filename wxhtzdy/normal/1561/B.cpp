/**
 *    author:  milos
 *    created: 25.08.2021 05:32:37       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int a, b;
    cin >> a >> b;
    vector<int> ans;
    if ((a + b) % 2 == 0) {
      int x = abs(a - b) / 2;
      for (int i = x; i <= a + b - x; i += 2) {
        ans.push_back(i);
      }   
    } else {
      int x = abs(a - b) / 2;
      for (int i = x; i <= a + b - x; i++) {
        ans.push_back(i);
      }
    }
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i] << " ";
    }
    cout << '\n';
  }
  return 0;
}