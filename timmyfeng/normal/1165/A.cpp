#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  int n, x, y;
  cin >> n >> x >> y >> s;
  reverse(s.begin(), s.end());

  int ans = 0;
  for (int i = 0; i < x; ++i) {
    ans += (s[i] - '0' != (i == y));
  }

  cout << ans << "\n";
}