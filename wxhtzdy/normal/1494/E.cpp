#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  map<pair<int, int>, char> ch;
  map<pair<int, int>, bool> was;
  vector<int> cnt(2);
  while (q--) {
    char foo;
    cin >> foo;
    if (foo == '+') {
      int u, v;
      cin >> u >> v;
      char c;
      cin >> c;
      if (was[{v, u}]) cnt[0]++;
      if (was[{v, u}] && ch[{v, u}] == c) cnt[1]++;
      was[{u, v}] = true;
      ch[{u, v}] = c;
    }
    if (foo == '-') {
      int u, v;
      cin >> u >> v;
      if (was[{v, u}]) cnt[0]--;
      if (was[{v, u}] && ch[{v, u}] == ch[{u, v}]) cnt[1]--;
      was[{u, v}] = false;
    }
    if (foo == '?') {
      int k;
      cin >> k;
      if (k % 2 == 0) {
        cout << (cnt[1] > 0 ? "YES" : "NO") << '\n';
      } else {
        cout << (cnt[0] + cnt[1] > 0 ? "YES" : "NO") << '\n';
      }
    }
  }
  return 0;
}