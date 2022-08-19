/**
 *    author:  tourist
 *    created: 27.12.2021 17:36:35       
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
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
      cin >> p[i];
    }
    string s;
    cin >> s;
    vector<int> res(n, -1);
    int ptr = 0;
    for (int r = 0; r <= 1; r++) {
      vector<pair<int, int>> a;
      for (int i = 0; i < n; i++) {
        if ((int) (s[i] - '0') == r) {
          a.emplace_back(p[i], i);
        }
      }
      sort(a.begin(), a.end());
      for (auto& p : a) {
        res[p.second] = ++ptr;
      }
    }
    for (int i = 0; i < n; i++) {
      if (i > 0) {
        cout << " ";
      }
      cout << res[i];
    }
    cout << '\n';
  }
  return 0;
}