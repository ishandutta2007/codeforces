#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;

int adj[N][2];
char type[N];
int val[N];
int dp[N];
int root;

int calc(int a, int b, char c) {
  if (c == 'A') {
    return a & b;
  } else if (c == 'O') {
    return a | b;
  } else if (c == 'X') {
    return a ^ b;
  }
  return a ^ 1;
}

void dfs_init(int u) {
  if (u == 0)
    return;

  for (int c : adj[u]) {
    dfs_init(c);
  }

  if (type[u] != 'I') {
    val[u] = calc(val[adj[u][0]], val[adj[u][1]], type[u]);
  }
}

void dfs_calc(int u, int p, int s) {
  if (u == 0)
    return;

  if (p == 0) {
    dp[u] = val[u] ^ 1;
  } else if (calc(val[u] ^ 1, val[s], type[p]) != val[p]) {
    dp[u] = dp[p];
  } else {
    dp[u] = val[1];
  }

  for (int i = 0; i < 2; ++i) {
    dfs_calc(adj[u][i], u, adj[u][i ^ 1]);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    string s;
    cin >> s;
    type[i] = s[0];
    if (type[i] == 'I') {
      cin >> val[i];
    } else {
      cin >> adj[i][0];
      if (type[i] != 'N') {
        cin >> adj[i][1];
      }
    }
  }

  dfs_init(1);
  dfs_calc(1, 0, 0);

  for (int i = 1; i <= n; ++i) {
    if (type[i] == 'I') {
      cout << dp[i];
    }
  }
  cout << "\n";
}