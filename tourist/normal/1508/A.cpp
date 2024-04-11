/**
 *    author:  tourist
 *    created: 16.04.2021 17:36:20       
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
    vector<string> s(3);
    for (int i = 0; i < 3; i++) {
      cin >> s[i];
    }
    string res = "";
    for (char c : {'0', '1'}) {
      vector<int> cnt(3);
      for (int i = 0; i < 3; i++) {
        for (char d : s[i]) {
          if (d == c) {
            cnt[i] += 1;
          }
        }
      }
      vector<int> order(3);
      iota(order.begin(), order.end(), 0);
      sort(order.begin(), order.end(), [&](int i, int j) {
        return cnt[i] > cnt[j];
      });
      if (cnt[order[1]] >= n) {
        int i = 0;
        int j = 0;
        while (i < 2 * n || j < 2 * n) {
          char nxt;
          if ((i < 2 * n && s[order[0]][i] != c) || (j < 2 * n && s[order[1]][j] != c)) {
            nxt = (char) (c ^ '0' ^ '1');
          } else {
            nxt = c;
          }
          res += nxt;
          if (i < 2 * n && s[order[0]][i] == nxt) {
            i += 1;
          }
          if (j < 2 * n && s[order[1]][j] == nxt) {
            j += 1;
          }
        }
        assert((int) res.size() <= 3 * n);
        break;
      }
    }
    assert(res != "");
    cout << res << '\n';
  }
  return 0;
}