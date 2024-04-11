#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  string s, t;
  cin >> n >> m >> s >> t;

  int a = find(s.begin(), s.end(), '*') - s.begin();
  if (a == n) {
    cout << (s == t ? "YES" : "NO") << "\n";
  } else if (s.size() - 1 <= t.size() && s.substr(0, a) == t.substr(0, a) && s.substr(a + 1) == t.substr(m - (n - 1 - a))) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}