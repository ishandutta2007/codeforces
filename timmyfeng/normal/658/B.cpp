#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k, q;
  cin >> n >> k >> q;

  vector<int> t(n);
  for (auto &i : t) {
    cin >> i;
  }

  set<int, greater<int>> online;
  while (q--) {
    int type, id;
    cin >> type >> id;
    if (type == 1) {
      online.insert(t[id - 1]);
    } else {
      bool ans = false;
      auto it = online.begin();
      for (int i = 0; i < k && it != online.end(); ++i) {
        ans |= (*(it++) == t[id - 1]);
      }
      cout << (ans ? "YES" : "NO") << "\n";
    }
  }
}