#include <bits/stdc++.h>
using namespace std;

const int maxn = 500000 + 5;
int n;
string s[maxn], ans[maxn];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> s[i];
  ans[n - 1] = s[n - 1];
  for (int i = n - 1; i >= 1; --i) {
    if (s[i - 1] <= ans[i]) { ans[i - 1] = s[i - 1]; continue; }
    for (int j = 0; j < ans[i].length(); ++j) {
      if (ans[i][j] == s[i - 1][j]) ans[i - 1] += s[i - 1][j];
      else break;
    }
  }
  for (int i = 0; i < n; ++i) cout << ans[i] << '\n';
  return 0;
}