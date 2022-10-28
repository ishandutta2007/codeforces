#include <bits/stdc++.h>
using namespace std;

const int N = 400000;

int second[N];
int first[N];
int sub[N];

vector<int> adj[N];
bool ans[N];
int n;

int get(int c) {
  return sub[c] <= n / 2 ? max(sub[c], first[c]) : first[c];
}

void update(int u, int c) {
  int x = get(c);
  if (x > first[u]) {
    second[u] = first[u];
    first[u] = x;
  } else if (x > second[u]) {
    second[u] = x;
  }
}

void dfs_pull(int u, int p = -1) {
  sub[u] = 1;
  for (auto c : adj[u]) {
    if (c != p) {
      dfs_pull(c, u);
      update(u, c);
      sub[u] += sub[c];
    }
  }
}

void dfs_push(int u, int p = -1) {
  ans[u] = true;
  for (auto c : adj[u]) {
    ans[u] &= sub[c] - first[c] <= n / 2;
  }

  for (auto c : adj[u]) {
    if (c != p) {
      if (first[u] == get(c)) {
        swap(first[u], second[u]);
      }
      sub[u] -= sub[c];
      sub[c] += sub[u];
      update(c, u);

      dfs_push(c, u);

      sub[c] -= sub[u];
      sub[u] += sub[c];
      if (second[u] > first[u]) {
        swap(first[u], second[u]);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs_pull(0);
  dfs_push(0);

  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}