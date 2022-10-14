/**
 *    author:  milos
 *    created: 31.07.2020 12:01:59      
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 100050;

vector<vector<int>> g(N);

int main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    while (true) {
      bool ok = 0;
      for (int i = 1; i < n; i++) {
        if (s[i] == 'P' && s[i - 1] == 'A') {
          ok = 1;
          s[i] = 'A';
          i++;
        }
      }
      if (ok) ans++;
      else break;
    }
    cout << ans << '\n';
  }
  return 0;   
}