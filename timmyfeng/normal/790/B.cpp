#include <bits/stdc++.h>
using namespace std;

const int N = 200000;
const int K = 5;

vector<int> adj[N];

long long count_paths[N][K];
long long sum_paths[N][K];
long long ans;
int k;

void dfs(int u, int p) {
  count_paths[u][0] = 1;
  for (auto c : adj[u]) {
    if (c != p) {
      dfs(c, u);
      for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
          ans += count_paths[u][i] * sum_paths[c][j];
          ans += count_paths[c][j] * sum_paths[u][i];
          ans += (count_paths[u][i] * count_paths[c][j]) * ((i + j) / k + 1);
        }

        if (i > 0) {
          sum_paths[u][i] += sum_paths[c][i - 1];
          count_paths[u][i] += count_paths[c][i - 1];
        } else {
          sum_paths[u][i] += sum_paths[c][k - 1] + count_paths[c][k - 1];
          count_paths[u][i] += count_paths[c][k - 1];
        }
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n >> k;

  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(0, -1);

  cout << ans << "\n";
}