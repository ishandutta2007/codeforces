#include <bits/stdc++.h>
using namespace std;

const int N = 300000 + 1;

int par[N], nxt[N], prv[N], locks[N];
vector<int> keys[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  for (int i = 1; i <= n; ++i) {
    cin >> par[i];
  }

  for (int i = 0; i < k; ++i) {
    int u, v;
    cin >> u >> v;
    nxt[u] = v;
    prv[v] = u;
  }

  int count = 0;
  int root = find(par + 1, par + n + 1, 0) - par;
  for (int i = 1; i <= n; ++i) {
    if (prv[i] == 0) {
      set<int> path;
      for (int j = i; j > 0; j = nxt[j]) {
        if (par[j] && !path.count(par[j])) {
          keys[par[j]].push_back(i);
          ++locks[i];
        }
        path.insert(j);
      }
      count += path.size();
    }
  }

  if (prv[root] || locks[root] || count < n) {
    cout << 0 << "\n";
    exit(0);
  }

  vector<int> ans;
  queue<int> que;
  que.push(root);

  while (!que.empty()) {
    int u = que.front();
    que.pop();

    for (int v = u; v > 0; v = nxt[v]) {
      ans.push_back(v);
      for (auto c : keys[v]) {
        if (--locks[c] == 0) {
          que.push(c);
        }
      }
    }
  }

  if ((int) ans.size() < n) {
    cout << 0 << "\n";
  } else {
    for (auto i : ans) {
      cout << i << " ";
    }
    cout << "\n";
  }
}