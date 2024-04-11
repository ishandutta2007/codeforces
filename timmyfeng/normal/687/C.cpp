#include <bits/stdc++.h>
using namespace std;

const int N = 500 + 1;

bool possible[N][N][N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, p;
  cin >> n >> p;

  possible[0][0][0] = true;

  for (int i = 0; i < n; ++i) {
    int c;
    cin >> c;

    for (int j = 0; j <= p; ++j) {
      for (int k = 0; k <= p; ++k) {
        if (possible[i][j][k]) {
          possible[i + 1][j][k] = true;
          if (j + c <= p) {
            possible[i + 1][j + c][k] = true;
          }
          if (k + c <= p) {
            possible[i + 1][j][k + c] = true;
          }
        }
      }
    }
  }

  vector<int> ans;
  for (int i = 0; i <= p; ++i) {
    if (possible[n][i][p - i]) {
      ans.push_back(i);
    }
  }

  cout << ans.size() << "\n";
  for (auto i : ans) {
    cout << i << " ";
  }
  cout << "\n";
}