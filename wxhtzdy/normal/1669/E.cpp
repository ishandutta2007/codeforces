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
    vector<string> s(n);
    vector<vector<int>> cnt(26, vector<int>(26));
    for (int i = 0; i < n; i++) {
      cin >> s[i];
      int x = (int) (s[i][0] - 'a');
      int y = (int) (s[i][1] - 'a');
      cnt[x][y] += 1;
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      for (char x = 'a'; x <= 'k'; x++) {
        for (char y = 'a'; y <= 'k'; y++) {
          int cc = 0;
          if (s[i][0] != x) {
            cc += 1;
          }
          if (s[i][1] != y) {
            cc += 1;
          }
          if (cc == 1) {
            ans += cnt[x - 'a'][y - 'a'];
          }
        }
      }
    }
    cout << ans / 2 << '\n';
  }                                                                    
  return 0;
}