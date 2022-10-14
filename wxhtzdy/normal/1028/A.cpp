/**      
 *    author:  milos
 *    created: 14.02.2021 19:31:16       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  int sz = 0;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    int cnt = 0;
    for (int j = 0; j < m; j++) {
      cnt += s[i][j] == 'B';   
    }
    if (cnt > 0) {
      sz = cnt;
    }
  }    
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m ;j++) {
      if (s[i][j] == 'B') {
        cout << i + sz / 2 + 1 << " " << j + sz / 2 + 1;
        return 0;
      }
    }
  }
  return 0;
}