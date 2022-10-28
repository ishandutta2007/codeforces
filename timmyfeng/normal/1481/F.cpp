#include <bits/stdc++.h>
using namespace std;

const int N = 100000 + 1;
const int B = 512;

vector<int> adj[N], layer[N], where[N];
int width[N], depth[N], sum[N], height;
bool possible[B][N];

void dfs(int u) {
  layer[depth[u]].push_back(u);
  height = max(height, depth[u] + 1);
  for (auto c : adj[u]) {
    depth[c] = depth[u] + 1;
    dfs(c);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, x;
  cin >> n >> x;

  for (int i = 2; i <= n; ++i) {
    int p;
    cin >> p;
    adj[p].push_back(i);
  }

  dfs(1);

  for (int i = 0; i < height; ++i) {
    width[i] = layer[i].size();
    where[width[i]].push_back(i);
  }
  sort(width, width + height);
  int m = unique(width, width + height) - width;

  possible[0][0] = true;
  for (int i = 0; i < m; ++i) {
    fill(sum, sum + n + 1, 0);
    for (int j = 0; j <= n; ++j) {
      sum[j] = possible[i][j];
      if (j >= width[i]) {
        sum[j] += sum[j - width[i]];
      }
      int k = j - (where[width[i]].size() + 1) * width[i];
      possible[i + 1][j] = (sum[j] - (k >= 0 ? sum[k] : 0) > 0);
    }
  }

  string ans(n, 'b');

  if (possible[m][x]) {
    cout << height << "\n";
    for (int i = m - 1; i >= 0; --i) {
      while (!possible[i][x]) {
        int u = where[width[i]].back();
        for (auto j : layer[u]) {
          ans[j - 1] = 'a';
          --x;
        }
        where[width[i]].pop_back();
      }
    }
    cout << ans << "\n";
    exit(0);
  }

  cout << height + 1 << "\n";
  for (int i = 0; i < height; ++i) {
    if ((int) layer[i].size() <= x) {
      for (auto j : layer[i]) {
        ans[j - 1] = 'a';
        --x;
      }
    } else if ((int) layer[i].size() > n - x) {
      if (x > n - x) {
        for (auto j : layer[i]) {
          if (!adj[j].empty()) {
            ans[j - 1] = 'a';
            --x;
          }
        }
      }

      for (auto j : layer[i]) {
        if (adj[j].empty() && x > 0) {
          ans[j - 1] = 'a';
          --x;
        }
      }
    }
    n -= layer[i].size();
  }
  cout << ans << "\n";
}