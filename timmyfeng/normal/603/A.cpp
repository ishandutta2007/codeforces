#include <bits/stdc++.h>
using namespace std;

int maxi[2][3];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  string s;
  cin >> n >> s;

  for (int i : s) {
    i -= '0';
    for (int j = 2; j >= 0; --j) {
      maxi[i][j] = max({maxi[i][j], maxi[1 - i][j] + 1, (j == 0 ? 0 : maxi[i][j - 1] + 1)});
    }
  }

  int ans = 0;
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j <= 2; ++j) {
      ans = max(ans, maxi[i][j]);
    }
  }

  cout << ans << "\n";
}