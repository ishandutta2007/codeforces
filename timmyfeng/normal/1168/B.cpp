#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  int n = s.size();

  int64_t ans = 0;
  int bound = n;
  for (int i = n - 1; i >= 0; --i) {
    int j = i + 2;
    while (j < bound && (s[i] != s[(i + j) / 2] || s[i] != s[j])) {
      j += 2;
    }
    bound = min(bound, j);
    ans += n - bound;
  }

  cout << ans << "\n";
}