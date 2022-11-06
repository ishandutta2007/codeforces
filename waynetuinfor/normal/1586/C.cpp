#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, M;
  cin >> N >> M;
  vector<string> grid(N);
  for (int i = 0; i < N; ++i) {
    cin >> grid[i];
  }
  vector<bool> bad(M);
  for (int i = 0; i + 1 < N; ++i) {
    for (int j = 1; j < M; ++j) {
      if (grid[i][j] == 'X' && grid[i + 1][j - 1] == 'X') {
        bad[j - 1] = true;
      }
    }
  }
  vector<int> sum(M + 1);
  for (int i = 0; i < M; ++i) {
    sum[i + 1] = sum[i] + bad[i];
  }
  int Q;
  cin >> Q;
  while (Q--) {
    int l, r;
    cin >> l >> r;
    if (l == r) {
      cout << "YES\n";
      continue;
    }
    if (sum[l - 1] == sum[r - 1]) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}