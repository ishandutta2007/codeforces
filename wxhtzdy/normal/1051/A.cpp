#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

bool Ok(string s) {
  bool a = false, b = false, c = false;
  for (char t : s) {
    if (t >= 'A' && t <= 'Z') a = true;
    if (t >= 'a' && t <= 'z') b = true;
    if (t >= '0' && t <= '9') c = true;
  }
  return a && b && c;
}

void solve() {
  string s;
  cin >> s;
  if (Ok(s)) {
    cout << s << '\n';
    return;
  }
  int n = (int) s.size();
  for (int i = 0; i < n; i++) {
    string ns = s;
    ns[i] = 'a';
    if (Ok(ns)) {
      cout << ns << '\n';
      return;
    }
    ns[i] = 'A';
    if (Ok(ns)) {
      cout << ns << '\n';
      return;
    }
    ns[i] = '1';
    if (Ok(ns)) {
      cout << ns << '\n';
      return;
    }
  }
  for (int i = 0; i < n - 1; i++) {
    string ns = s;
    ns[i] = 'a';
    ns[i + 1] = 'A';
    if (Ok(ns)) {
      cout << ns << '\n';
      return;
    }
    ns[i] = 'a';
    ns[i + 1] = '1';
    if (Ok(ns)) {
      cout << ns << '\n';
      return;
    }
    ns[i] = 'A';
    ns[i + 1] = '1';
    if (Ok(ns)) {
      cout << ns << '\n';
      return;
    }
  }
  s[0] = 'A';
  s[1] = 'a';
  s[2] = '1';
  cout << s << '\n';
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}