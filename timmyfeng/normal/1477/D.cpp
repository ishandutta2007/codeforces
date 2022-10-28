#include <bits/stdc++.h>
using namespace std;

const int N = 500000;

set<int> pairs[N], group[N], remain;
int p[N], q[N];
bool head[N];

void dfs(int u, int p = -1) {
  int c = -1, v = -1;
  group[u].clear();
  head[u] = false;
  remain.erase(u);

  while (true) {
    auto it = remain.upper_bound(c);
    if (it == remain.end()) {
      break;
    }

    c = *it;
    if (pairs[u].count(c) == 0) {
      dfs(c, u);
      if (head[c]) {
        v = c;
      } else {
        head[u] = true;
        group[u].insert(c);
      }
    }
  }

  if (!head[u] && p == -1) {
    if (v == -1) {
      head[u] = true;
    } else {
      group[v].insert(u);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    fill(pairs, pairs + n, set<int>());

    while (m--) {
      int l, r;
      cin >> l >> r;
      --l, --r;
      pairs[l].insert(r);
      pairs[r].insert(l);
    }

    remain.clear();
    for (int i = 0; i < n; ++i) {
      remain.insert(i);
    }

    for (int i = 0; i < n; ++i) {
      if (remain.count(i) > 0) {
        dfs(i);
      }
    }

    int k = 1;
    for (int i = 0; i < n; ++i) {
      if (head[i]) {
        p[i] = k + group[i].size();
        q[i] = k++;
        for (auto j : group[i]) {
          p[j] = k - 1;
          q[j] = k++;
        }
      }
    }

    for (int i = 0; i < n; ++i) {
      cout << p[i] << " ";
    }
    cout << "\n";

    for (int i = 0; i < n; ++i) {
      cout << q[i] << " ";
    }
    cout << "\n";
  }
}