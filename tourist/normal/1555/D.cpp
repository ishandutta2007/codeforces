/**
 *    author:  tourist
 *    created: 30.07.2021 17:40:35       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  vector<vector<int>> pref;
  for (char a : {'a', 'b', 'c'}) {
    for (char b : {'a', 'b', 'c'}) {
      for (char c : {'a', 'b', 'c'}) {
        if (a != b && a != c && b != c) {
          pref.emplace_back(n + 1);
          for (int i = 0; i < n; i++) {
            char d = (i % 3 == 0 ? a : (i % 3 == 1 ? b : c));
            pref.back()[i + 1] = pref.back()[i] + (s[i] != d);
          }
        }
      }
    }
  }
  while (m--) {
    int L, R;
    cin >> L >> R;
    --L; --R;
    int ans = (int) 1e9;
    for (auto& v : pref) {
      ans = min(ans, v[R + 1] - v[L]);
    }
    cout << ans << '\n';
  }
  return 0;
}