#include <bits/stdc++.h>
using namespace std;

const int N = 50;

vector<int> adj[N];
double choose[N][N];
double prob[N][N];
int sub[N], n;

void dfs(int u, int p = -1) {
  vector<double> prv = {1.0};
  sub[u] = 1;

  for (auto c : adj[u]) {
    if (c != p) {
      dfs(c, u);
      sub[u] += sub[c];
      int s = sub[c] - 1;

      vector<double> nxt(prv.size() + sub[c]);
      for (int i = 0; i < (int) prv.size(); ++i) {
        for (int j = 0; j <= s; ++j) {
          for (int k = j; k <= s; ++k) {
            nxt[i + j] += 0.5 * prv[i] * choose[s][j] * prob[c][k] / (s - j + 1);
          }
        }
        for (int j = 0; j <= s; ++j) {
          nxt[i + j + 1] += prv[i] * choose[s][j] * prob[c][j];
        }
      }

      swap(nxt, prv);
    }
  }

  for (int i = 0; i < sub[u]; ++i) {
    prob[u][i] = prv[i] / choose[sub[u] - 1][i];
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cout << fixed << setprecision(8);

  for (int i = 0; i < N; ++i) {
    choose[i][0] = choose[i][i] = 1.0;
    for (int j = 1; j < i; ++j) {
      choose[i][j] = choose[i - 1][j - 1] + choose[i - 1][j];
    }
  }

  cin >> n;

  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 0; i < n; ++i) {
    dfs(i);
    cout << prob[i][0] << "\n";
  }
}