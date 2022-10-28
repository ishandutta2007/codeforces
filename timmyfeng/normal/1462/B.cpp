#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;

    bool ok = false;
    for (int i = 0; i <= 4; ++i) {
      string t = s.substr(0, 4 - i) + s.substr(n - i);
      ok |= (t == "2020");
    }

    cout << (ok ? "YES" : "NO") << "\n";
  }
}