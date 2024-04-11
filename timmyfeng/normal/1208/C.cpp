#include <bits/stdc++.h>
using namespace std;

const int N = 1'000;

int ans[N][N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; i += 4) {
    for (int j = 0; j < n; j += 4) {
      for (int ii = 0; ii < 4; ++ii) {
        for (int jj = 0; jj < 4; ++jj) {
          ans[i + ii][j + jj] = i * n + 4 * j + ii * 4 + jj;
        }
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << ans[i][j] << " ";
    }
    cout << "\n";
  }
}