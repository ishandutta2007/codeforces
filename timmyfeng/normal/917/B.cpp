#include <bits/stdc++.h>
using namespace std;

const int A = 26;
const int N = 101;

vector<array<int, 2>> adj[N];
vector<int> order;
bool memo[N][N][A];
bool done[N][N][A];

bool win(int i, int j, int k) {
  if (!done[i][j][k]) {
    for (auto [u, c] : adj[i]) {
      if (c >= k) {
        memo[i][j][k] |= !win(j, u, c);
      }
    }
    done[i][j][k] = true;
  }
  return memo[i][j][k];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  while (m--) {
    char c;
    int u, v;
    cin >> u >> v >> c;
    adj[u].push_back({v, c - 'a'});
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cout << (win(i, j, 0) ? 'A' : 'B');
    }
    cout << "\n";
  }
}