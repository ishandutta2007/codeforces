#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    string s;
    cin >> n >> k >> s;

    vector<set<char>> pos(k);
    for (int i = 0; i < n; ++i) {
      pos[i % k].insert(s[i]);
    }

    bool ok = true;
    int bal = 0;
    int ext = 0;
    for (auto i : pos) {
      if (i.count('1') > 0 && i.count('0') > 0) {
        ok = false;
      } else if (i.count('1') > 0) {
        ++bal;
      } else if (i.count('0') > 0) {
        --bal;
      } else {
        ++ext;
      }
    }

    cout << (ok && abs(bal) <= ext ? "YES" : "NO") << "\n";
  }
}