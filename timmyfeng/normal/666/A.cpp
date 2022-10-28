#include <bits/stdc++.h>
using namespace std;

const int N = 10000 + 1;

bool possible[N][2];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  int n = s.size();

  for (int i = 0; i < 2; ++i) {
    possible[n][i] = true;
  }

  set<string> ans;
  for (int i = n - 1; i > 4; --i) {
    for (auto j : {2, 3}) {
      if (i + j <= n && possible[i + j][j - 2]) {
        ans.insert(s.substr(i, j));
        possible[i][3 - j] = true;
        if (s.substr(i - j, j) != s.substr(i, j)) {
          possible[i][j - 2] = true;
        }
      }
    }
  }

  cout << ans.size() << "\n";
  for (auto i : ans) {
    cout << i << "\n";
  }
}