/**
 *  author: milos
 *  created: 28.12.2020 16:15:56
**/
#include <bits/stdc++.h>

using namespace std;

int Solve(int x,int y){
  int ans=1;
  while(y>1){
    ans++;
    y/=x;
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    if (n == 3) {
      cout << "2" << '\n';
      cout << "3 2" << '\n';
      cout << "3 2" << '\n';
    } else {
      if (n == 4) {
        cout << "3" << '\n';
        cout << "3 4" << '\n';
        cout << "4 2" << '\n';
        cout << "4 2" << '\n';
        continue;
      }
      if (n <= 16) {
        vector<pair<int, int>> ans;
        for (int i = 3; i < n; i++) {
          if (i == 4) {
            continue;
          }
          ans.push_back({i, n});
        }
        int k = n;          
        while (n > 1) {
          ans.push_back({k, 4});
          n = (n + 3) / 4;
        }    
        for (int i = 0; i < 2; i++) {
          ans.push_back({4, 2});
        }
        cout << ans.size() << '\n';
        for (auto c : ans) {
          cout << c.first << " " << c.second << '\n';
        }
      } else {   
        vector<pair<int, int>> ans;
        for (int i = 3; i < n; i++) {
          if (i == 16) {
            continue;
          }
          ans.push_back({i, n});
        }
        int k = n;          
        while (n > 1) {
          ans.push_back({k, 16});
          n = (n + 15) / 16;
        }    
        for (int i = 0; i < 4; i++) {
          ans.push_back({16, 2});
        }
        cout << ans.size() << '\n';
        for (auto c : ans) {
          cout << c.first << " " << c.second << '\n';
        }
      } 
    }
  }
  return 0;
}