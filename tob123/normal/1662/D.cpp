#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define st first
#define nd second
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int N = 1e6 + 5;

void solve() {
  string s, t; cin >> s >> t;
  int x = 0, y = 0;
  for (char c: s)
    x ^= c == 'B';
  for (char c: t)
    y ^= c == 'B';
  if (x != y) {
    cout << "NO\n";
    return;
  }
  string u, v;
  for (char c: s) {
    if (c != 'B') {
      if (sz(u) > 0 && u.back() == c)
        u.pop_back();
      else
        u.push_back(c);
    }
  }
  for (char c: t)
    if (c != 'B') {
      if (sz(v) > 0 && v.back() == c)
        v.pop_back();
      else
        v.push_back(c);
    }
  if (u != v)
    cout << "NO\n";
  else
    cout << "YES\n";
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while (t--) solve();
}