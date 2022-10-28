#include <bits/stdc++.h>
using namespace std;

const int N = 300000;
const int A = 26;

int adj[N][A];
int save[N];
int sub[N];
int depth;

int dfs_multi(vector<int> &u) {
  int res = 1;
  for (int i = 0; i < A; ++i) {
    vector<int> c;
    for (auto v : u) {
      if (adj[v][i] != 0) {
        c.push_back(adj[v][i]);
      }
    }

    if (c.size() == 1u) {
      res += sub[c[0]];
    } else if (c.size() > 1u) {
      res += dfs_multi(c);
    }
  }
  return res;
}

void dfs(int u) {
  vector<int> children;
  sub[u] = 1;
  ++depth;
  for (auto c : adj[u]) {
    if (c != 0) {
      dfs(c);
      sub[u] += sub[c];
      children.push_back(c);
    }
  }
  save[--depth] += sub[u] - dfs_multi(children);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n - 1; ++i) {
    char c;
    int u, v;
    cin >> u >> v >> c;
    adj[u - 1][c - 'a'] = v - 1;
  }

  dfs(0);

  int ans = max_element(save, save + n) - save;
  cout << n - save[ans] << "\n";
  cout << ans + 1 << "\n";
}