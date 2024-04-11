#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  string s;
  cin >> n >> s;
  sort(s.begin(), s.end());

  bool ok = (n == 1);
  for (int i = 1; i < n; ++i) {
    ok |= (s[i] == s[i - 1]);
  }

  cout << (ok ? "Yes" : "No") << "\n";
}