#include <bits/stdc++.h>
using namespace std;

const int N = 2'000;

bool visited[N];
int child[N][2];
int par[N];
int sub[N];
int m;

int query(int a, int b, int c) {
  cout << a + 1 << " " << b + 1 << " " << c + 1 << endl;

  char res;
  cin >> res;
  switch (res) {
    case 'X':
      return -1;
    case 'Y':
      return 1;
    default:
      return 0;
  }
}

int dfs_sub(int u) {
  sub[u] = (child[u][0] == -1);
  for (auto c : child[u]) {
    if (c != -1 && !visited[c]) {
      sub[u] += dfs_sub(c);
    }
  }
  return sub[u];
}

int dfs_find(int u, int n) {
  for (auto c : child[u]) {
    if (c != -1 && !visited[c] && sub[c] * 2 > n) {
      return dfs_find(c, n);
    }
  }
  return u;
}

int leaf(int u) {
  if (child[u][0] == -1) {
    return u;
  }
  return leaf(child[u][0]);
}

void dfs_add(int u, int v) {
  if (visited[u] || child[u][0] == -1) {
    if (par[u] != -1) {
      child[par[u]][(child[par[u]][1] == u)] = m;
      par[m] = par[u];
    }

    child[m][0] = u;
    par[u] = m;

    child[m][1] = v;
    par[v] = m++;
    return;
  }

  int c = dfs_find(u, dfs_sub(u) + 1);
  int o = query(leaf(child[c][0]), leaf(child[c][1]), v);

  visited[c] = true;
  if (o == -1) {
    dfs_add(u, v);
  } else {
    dfs_add(child[c][o], v);
  }
  visited[c] = false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  m = n;

  for (int i = 0; i < 2 * n - 1; ++i) {
    par[i] = -1;
    for (auto j : {0, 1}) {
      child[i][j] = -1;
    }
  }

  for (int i = 1; i < n; ++i) {
    int root = 0;
    while (par[root] != -1) {
      root = par[root];
    }
    dfs_add(root, i);
  }

  cout << -1 << endl;
  for (int i = 0; i < m; ++i) {
    cout << (par[i] != -1 ? par[i] + 1 : -1) << " ";
  }
  cout << endl;
}