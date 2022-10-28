#include <bits/stdc++.h>
using namespace std;

const long long OO = 1e15;
const int N = 2e5 + 1;

vector<int> adj[N];
long long dp[N][2];
long long t[N];
int h[N];

void dfs(int u, int p) {
  long long sum = int(adj[u].size()) * t[u];
  vector<long long> chd = {0};
  int negative = 0;
  int positive = 0;

  for (int c : adj[u]) {
    if (c != p) {
      dfs(c, u);
      if (h[c] == h[u]) {
        sum += dp[c][1];
        chd.push_back(dp[c][1] - dp[c][0]);
      } else {
        sum += dp[c][(h[c] < h[u])];
        if (h[c] < h[u]) {
          ++negative;
        } else {
          ++positive;
        }
      }
    }
  }

  sort(chd.rbegin(), chd.rend() - 1);
  for (int i = 1; i < int(chd.size()); ++i) {
    chd[i] += chd[i - 1];
  }

  for (int k = 0; k < 2; ++k) {
    if (k == 0) {
      negative += (p > 0);
    } else {
      positive += (p > 0);
    }

    dp[u][k] = OO;
    for (int i = 0; i < int(chd.size()); ++i) {
      int j = int(chd.size()) - i - 1;
      dp[u][k] = min(dp[u][k], sum - chd[i] - min(positive + i, negative + j) * t[u]);  
    }

    if (k == 0) {
      negative -= (p > 0);
    } else {
      positive -= (p > 0);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 1; i <= n; ++i) {
    cin >> t[i];
  }

  for (int i = 1; i <= n; ++i) {
    cin >> h[i];
  }

  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1, 0);
  cout << dp[1][0] << "\n";
}