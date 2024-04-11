#include <bits/stdc++.h>
using namespace std;

const int N = 500000 + 1;

set<array<int, 2>> goal[N];
vector<int> group[N];
set<int> adj[N];
int color[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].insert(v);
    adj[v].insert(u);
  }

  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    goal[u].insert({u, v});
    goal[v].insert({v, u});
  }

  vector<int> leaves;
  for (int i = 1; i <= n; ++i) {
    group[i] = {i};
    color[i] = i;
    if (adj[i].size() == 1) {
      leaves.push_back(i);
    }
  }

  vector<array<int, 4>> ans;
  while (!leaves.empty()) {
    int a = leaves.back();
    leaves.pop_back();
    if (adj[a].empty()) {
      continue;
    }

    int b = *adj[a].begin();
    adj[a].erase(b);
    adj[b].erase(a);
    if (adj[b].size() == 1) {
      leaves.push_back(b);
    }

    int c, d;
    if (goal[color[a]].count({a, b}) == 0) {
      c = (*goal[color[a]].begin())[0];
      d = (*goal[color[a]].begin())[1];
      ans.push_back({a, b, c, d});
    } else {
      c = a, d = b;
    }
    goal[color[c]].erase({c, d});
    goal[color[d]].erase({d, c});

    c = color[c], d = color[d];
    if (group[c].size() > group[d].size()) {
      swap(c, d);
    }

    for (auto e : group[c]) {
      color[e] = d;
    }
    group[d].insert(group[d].end(), group[c].begin(), group[c].end());
    goal[d].insert(goal[c].begin(), goal[c].end());
    group[c].clear();
    goal[c].clear();
  }

  cout << ans.size() << "\n";
  for (auto [a, b, c, d] : ans) {
    cout << a << " " << b << " " << c << " " << d << "\n";
  }
}