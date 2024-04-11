#include <bits/stdc++.h>
using namespace std;

const int N = 700;

bitset<N> adj[N], possible[N][N], visited[N][N];

bool solve(int l, int r, int p) {
  if (l > r) {
    return true;
  }

  if (!visited[l][r][p]) {
    visited[l][r][p] = true;
    for (int i = l; i <= r && !possible[l][r][p]; ++i) {
      if (adj[p][i] && solve(l, i - 1, i) && solve(i + 1, r, i)) {
        possible[l][r][p] = true;
      }
    }
  }
  return possible[l][r][p];
}

int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      adj[i][j] = (__gcd(a[i], a[j]) > 1);
    }
  }

  for (int i = 0; i < n; ++i) {
    if (solve(0, i - 1, i) && solve(i + 1, n - 1, i)) {
      cout << "Yes\n";
      exit(0);
    }
  }

  cout << "No\n";
}