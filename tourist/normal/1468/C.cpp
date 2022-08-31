/**
 *    author:  tourist
 *    created: 25.12.2020 14:50:43       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  vector<int> m;
  set<int> t;
  set<pair<int, int>> c;
  while (tt--) {
    int op;
    cin >> op;
    if (op == 1) {
      int x;
      cin >> x;
      m.push_back(x);
      t.emplace((int) m.size() - 1);
      c.emplace(~x, (int) m.size() - 1);
    } else {
      int i = (op == 2 ? *t.begin() : c.begin()->second);
      t.erase(i);
      c.erase(make_pair(~m[i], i));
      cout << i + 1 << '\n';
    }

  }
  return 0;
}