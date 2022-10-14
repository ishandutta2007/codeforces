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
  int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    string ans = "";
    vector<bool> was(n, false);
    for (int i = 0; i < n; i++) {
      if (was[i]) continue;
      for (int j = i + 1; j < n; j++) {
        string k = s[j];
        reverse(k.begin(), k.end());
        if (k == s[i]) {
          was[j] = 1;
          ans += s[i];
          was[i] = 1;
          break;
        }
      }
    }
    string novagodina = "";
    for (int i = 0; i < n; i++) {
      if (was[i] || (int) s[i].length() < (int) novagodina.length()) continue;
      string g = s[i];
      reverse(g.begin(), g.end());
      if (g == s[i]) novagodina = s[i];
    }
    cout << ans.length() * 2 + novagodina.length() << '\n';
    cout << ans << novagodina;
    for (int i = (int) ans.size() - 1; i >= 0; i--) cout << ans[i];
  return 0;   
}