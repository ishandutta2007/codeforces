/**
 *  author: milos
 *  created: 05.01.2021 04:58:53
**/
#include <bits/stdc++.h>
          
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;      
  vector<string> s(n);
  unordered_map<string, int> cnt;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    cnt[s[i]] += 1;
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    cnt[s[i]] -= 1;
    for (int j = i + 1; j < n; j++) {
      cnt[s[j]] -= 1;
      string c = "";
      for (int t = 0; t < k; t++) {
        if (s[i][t] == s[j][t]) {
          c += s[i][t];
        } else {
          if (s[i][t] != 'S' && s[j][t] != 'S') {
            c += 'S';
          } else {
            if (s[i][t] != 'E' && s[j][t] != 'E') {
              c += 'E';
            } else {
              c += 'T';
            }
          }
        }
      }
      ans += cnt[c];
    }  
    for (int j = i + 1; j < n; j++) {
      cnt[s[j]] += 1;
    }
  }
  cout << ans << '\n';     
  return 0;
}