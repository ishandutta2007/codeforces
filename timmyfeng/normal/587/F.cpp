#include <bits/stdc++.h>
using namespace std;

template <class T>
struct fenwick {

  vector<T> tree;
  int n;

  fenwick() {}

  fenwick(int n) : n(n) {
    tree.resize(n + 1);
  }

  void update(int a, T x) {
    for ( ; a <= n; a += a & -a) {
      tree[a] += x;
    }
  }

  T query(int a) {
    T res = 0;
    for ( ; a > 0; a -= a & -a) {
      res += tree[a];
    }
    return res;
  }

  int lower_bound(T k) {
    int res = 0;
    T cur = 0;
    for (int i = __lg(n); i >= 0; --i) {
      if (res + (1 << i) <= n && cur + tree[res + (1 << i)] < k) {
        res += 1 << i;
        cur += tree[res];
      }
    }
    return res + 1;
  }

};

const int N = 100000 + 1;
const int B = 512;
const int A = 26;

int to[N][A], last[N], link[N], prv[N], in[N], out[N], t;
vector<int> words[N], adj[N];
string s[N];

void dfs(int u) {
  in[u] = ++t;
  for (auto c : adj[u]) {
    dfs(c);
  }
  out[u] = t;
}

array<int, 4> queries[N];
long long ans[N], sum[N];
fenwick<int> links;
int matches[N];

void update(int u, int k) {
  links.update(in[u], k);
  links.update(out[u] + 1, -k);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  int m = 1;
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
    int u = 0;
    for (auto j : s[i]) {
      if (to[u][j - 'a'] == 0) {
        to[u][j - 'a'] = m++;
      }
      u = to[u][j - 'a'];
    }
    words[u].push_back(i);
    last[i] = u;
  }

  queue<int> que;
  que.push(0);
  while (!que.empty()) {
    int u = que.front();
    que.pop();

    int p = link[u];
    prv[u] = words[u].empty() ? prv[p] : u;
    if (u != 0) {
      adj[p].push_back(u);
    }

    for (int i = 0; i < A; ++i) {
      if (to[u][i] == 0) {
        to[u][i] = to[link[u]][i];
      } else {
        link[to[u][i]] = (u == 0) ? 0 : to[link[u]][i];
        que.push(to[u][i]);
      }
    }
  }

  dfs(0);

  for (int i = 0; i < q; ++i) {
    int l, r, k;
    cin >> l >> r >> k;
    queries[i] = {--l, --r, --k, i};
  }

  sort(queries, queries + q, [&](array<int, 4> a, array<int, 4> b) {
    if (a[0] / B == b[0] / B) {
      return a[1] < b[1];
    } else {
      return a[0] < b[0];
    }
  });

  for (int i = 0; i < n; ++i) {
    if ((int) s[i].size() < B) {
      continue;
    }

    fill(matches, matches + m, 0);
    fill(sum, sum + n + 1, 0);

    int u = 0;
    for (auto j : s[i]) {
      u = to[u][j - 'a'];
      int v = prv[u];
      while (v != 0) {
        ++matches[v];
        v = prv[link[v]];
      }
    }

    for (int j = 0; j < m; ++j) {
      for (auto k : words[j]) {
        sum[k + 1] += matches[j];
      }
    }

    for (int j = 0; j < n; ++j) {
      sum[j + 1] += sum[j];
    }

    for (int j = 0; j < q; ++j) {
      auto [x, y, z, id] = queries[j];
      if (i == z) {
        ans[id] = sum[y + 1] - sum[x];
      }
    }
  }

  int l = 0, r = -1;
  links = fenwick<int>(m);
  for (int i = 0; i < q; ++i) {
    auto [x, y, z, id] = queries[i];
    if ((int) s[z].size() >= B) {
      continue;
    }

    while (l > x) {
      update(last[--l], 1);
    }
    while (r < y) {
      update(last[++r], 1);
    }
    while (l < x) {
      update(last[l++], -1);
    }
    while (r > y) {
      update(last[r--], -1);
    }

    int u = 0;
    for (auto j : s[z]) {
      u = to[u][j - 'a'];
      ans[id] += links.query(in[u]);
    }
  }

  for (int i = 0; i < q; ++i) {
    cout << ans[i] << "\n";
  }
}