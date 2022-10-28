#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b, l, r;
  cin >> a >> b >> l >> r;
  --l;

  int ans = r - l;
  for (auto k : {0, 1}) {
    string s;
    for (int i = 0; i < 4; ++i) {
      set<char> used;
      for (int j = 1; j <= min(a, int(s.size())); ++j) {
        used.insert(s[int(s.size()) - j]);
      }

      char c = 'a';
      for (int j = 0; j < a; ++j) {
        while (used.count(c) != 0) {
          ++c;
        }
        s += c;
        ++c;
      }

      s += max(int('a'), s.back() - k);
      for (int j = 1; j < b; ++j) {
        s += s.back();
      }
    }
    int m = s.size();

    if (r - l >= m) {
      l = 0;
      r = m - 1;
    }

    set<char> seen;
    for (int i = l; i % m != r % m; ++i) {
      seen.insert(s[i % m]);
    }
    ans = min(ans, int(seen.size()));
  }
  cout << ans << "\n";
}