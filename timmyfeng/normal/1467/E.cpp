#include <bits/stdc++.h>
using namespace std;

const int N = 200000 + 1;
const int L = __lg(N) + 1;

int sum[N], par[L][N], in[N], out[N], n, t;
vector<int> adj[N];

void dfs(int u) {
  in[u] = t++;
  for (int i = 1; i <= __lg(n); ++i) {
    par[i][u] = par[i - 1][par[i - 1][u]];
  }

  for (auto c : adj[u]) {
    if (c != par[0][u]) {
      par[0][c] = u;
      dfs(c);
    }
  }
  out[u] = t;
}

bool ancestor(int u, int v) {
  return in[u] <= in[v] && out[v] <= out[u];
}

int child(int u, int v) {
  for (int i = __lg(n); i >= 0; --i) {
    if (!ancestor(par[i][v], u)) {
      v = par[i][v];
    }
  }
  return v;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  map<int, vector<int>> colors;
  for (int i = 1; i <= n; ++i) {
    int a;
    cin >> a;
    colors[a].push_back(i);
  }

  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1);
  out[0] = t;

  int x = 0;
  for (auto &[u, v] : colors) {
    if (v.size() > 1) {
      for (int i = 0; i < (int) v.size(); ++i) {
        int j = (i + 1) % v.size();
        int l = v[i], r = v[j];
        if (ancestor(r, l)) {
          swap(r, l);
        }

        if (ancestor(l, r)) {
          int y = child(l, r);
          ++sum[in[y]], --sum[out[y]];
          --sum[in[r]], ++sum[out[r]];
        } else {
          ++sum[0], --sum[n];
          --sum[in[l]], ++sum[out[l]];
          --sum[in[r]], ++sum[out[r]];
        }
        ++x;
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    sum[i + 1] += sum[i];
  }

  cout << count(sum, sum + n, x) << "\n";
}