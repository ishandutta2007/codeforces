#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tt;
  cin >> tt;

  while (tt--) {
    string s, t, a, b;
    cin >> s >> t;

    int l = s.size() * t.size() / __gcd(s.size(), t.size());

    while ((int) a.size() < l) {
      a += s;
    }

    while ((int) b.size() < l) {
      b += t;
    }

    if (a == b) {
      cout << a << "\n";
    } else {
      cout << -1 << "\n";
    }
  }
}