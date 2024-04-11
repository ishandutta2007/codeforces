#include <bits/stdc++.h>
using namespace std;

const int M = (119 << 23) + 1;
const int N = 4001;
const int K = 76;

int add(int a, int b) {
  a += b;
  if (a >= M) {
    a -= M;
  }
  return a;
}

int mul(int a, int b) {
  return 1LL * a * b % M;
}

vector<int> adj1[N];
vector<int> adj2[N];
int cnt1[N];
int cnt2[N];

int dp_no[K][N];
int dp[K][N];
bool dead[N];
int sub[N];

int cnk[K][K];
int k;

void dfs_sub(int u, int p, vector<int>* adj) {
  for (int i = 0; i <= k; ++i) {
    dp[i][u] = 0;
    dp_no[i][u] = 0;
  }

  sub[u] = 1;
  for (int c : adj[u]) {
    if (c != p && !dead[c]) {
      dfs_sub(c, u, adj);
      sub[u] += sub[c];
    }
  }
}

int dfs_find(int u, int p, int n, vector<int>* adj) {
  for (int c : adj[u]) {
    if (c != p && !dead[c] && sub[c] > n / 2) {
      return dfs_find(c, u, n, adj);
    }
  }
  return u;
}

void dfs_dp(int u, int p, int i, int centroid, vector<int>* adj) {
  for (int c : adj[u]) {
    if (!dead[c]) {
      dp[i][c] = add(dp[i][c], dp[i - 1][u]);
      if (c != centroid) {
        dp_no[i][c] = add(dp_no[i][c], dp_no[i - 1][u]);
      }
      if (c != p) {
        dfs_dp(c, u, i, centroid, adj);
      }
    }
  }
}

void dfs_calc(int u, int p, vector<int>* adj, int* res) {
  for (int i = 0; i <= k; ++i) {
    for (int j = 0; i + j <= k; ++j) {
      res[i + j] = add(res[i + j], mul(dp_no[i][u], dp[j][u]));
    }
  }

  for (int c : adj[u]) {
    if (c != p && !dead[c]) {
      dfs_calc(c, u, adj, res);
    }
  }
}

void solve(int u, vector<int>* adj, int* res) {
  dfs_sub(u, 0, adj);
  u = dfs_find(u, 0, sub[u], adj);

  dp[0][u] = 1;
  dp_no[0][u] = 1;
  for (int i = 1; i <= k; ++i) {
    dfs_dp(u, 0, i, u, adj);
  }

  dfs_calc(u, 0, adj, res);

  dead[u] = true;
  for (int c : adj[u]) {
    if (!dead[c]) {
      solve(c, adj, res);
    }
  }
  dead[u] = false;
}

void read(int n, vector<int>* adj) {
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cnk[0][0] = 1;
  for (int i = 0; i < K - 1; ++i) {
    for (int j = 0; j <= i; ++j) {
      cnk[i + 1][j] = add(cnk[i + 1][j], cnk[i][j]);
      cnk[i + 1][j + 1] = add(cnk[i + 1][j + 1], cnk[i][j]);
    }
  }

  int n1, n2;
  cin >> n1 >> n2 >> k;

  read(n1, adj1);
  read(n2, adj2);

  solve(1, adj1, cnt1);
  solve(1, adj2, cnt2);

  int ans = 0;
  for (int i = 0; i <= k; ++i) {
    ans = add(ans, mul(cnk[k][i], mul(cnt1[i], cnt2[k - i])));
  }
  cout << ans << "\n";
}