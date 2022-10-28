#include <bits/stdc++.h>
using namespace std;

const int N = 500'000;

vector<array<long long, 2>> dsu[N];
vector<int> adj[N];
long long ans[N];
int par[N];
int dep[N];

struct dat {
  long long sum;
  int cnt, id;
};

vector<dat> dfs(int u) {
  vector<dat> res;
  for (auto c : adj[u]) {
    dep[c] = dep[u] + 1;
    vector<dat> chd = dfs(c);
    if (chd.size() > res.size()) {
      swap(chd, res);
    }

    for (unsigned i = 1; i <= chd.size(); ++i) {
      int i_r = res.size() - i;
      int i_c = chd.size() - i;
      res[i_r].sum += 1LL * chd[i_c].cnt * (dep[u] + 1);
      chd[i_c].sum += 1LL * res[i_r].cnt * (dep[u] + 1);
      dsu[res[i_r].id].push_back({chd[i_c].id, chd[i_c].sum - res[i_r].sum});
      res[i_r].cnt += chd[i_c].cnt;
    }
  }
  res.push_back({dep[u], 1, u});
  return res;
}

void dfs_ans(int u, long long sum) {
  ans[u] = (par[u] == -1 ? 0LL : ans[par[u]]) + sum;
  for (auto [c, w] : dsu[u]) {
    dfs_ans(c, sum + w);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int root = 0;
  for (int i = 0; i < n; ++i) {
    cin >> par[i];
    if (--par[i] == -1) {
      root = i;
    } else {
      adj[par[i]].push_back(i);
    }
  }

  vector<dat> res = dfs(root);
  reverse(res.begin(), res.end());
  for (auto i : res) {
    dfs_ans(i.id, i.sum);
  }

  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}