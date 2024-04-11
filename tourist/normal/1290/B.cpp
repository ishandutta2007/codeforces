/**
 *    author:  tourist
 *    created: 02.02.2020 17:12:43       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int len = (int) s.size();
  vector<int> nxt(len + 1);
  for (int i = len - 2; i >= 0; i--) {
    if (s[i] != s[i + 1]) {
      nxt[i] = i + 1;
    } else {
      nxt[i] = nxt[i + 1];
    }
  }
  vector<vector<int>> txn(len + 1, vector<int>(26, len));
  for (int i = len - 1; i >= 0; i--) {
    txn[i] = txn[i + 1];
    txn[i][(char) (s[i] - 'a')] = i;
  }
  int tt;
  cin >> tt;
  while (tt--) {
    int from, to;
    cin >> from >> to;
    --from; --to;
    if (to - from + 1 == 1) {
      cout << "Yes" << '\n';
      continue;
    }
    if (nxt[from] > to) {
      cout << "No" << '\n';
      continue;
    }
    if (s[from] != s[to]) {
      cout << "Yes" << '\n';
      continue;
    }
    int cnt = 0;
    for (int c = 0; c < 26; c++) {
      cnt += (txn[from][c] <= to);
    }
    if (cnt >= 3) {
      cout << "Yes" << '\n';
      continue;
    }
    cout << "No" << '\n';
  }
  return 0;
}