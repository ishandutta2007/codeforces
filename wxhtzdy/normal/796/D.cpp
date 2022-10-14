#include <bits/stdc++.h>

using ll = long long;

const int nmax = 300005;

struct node {
  int cur, from;
};

std::vector<std::pair<int, int>> g[nmax];
std::queue<node> que;
bool was[nmax];

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, k, d;
  std::cin >> n >> k >> d;
  for(int i = 0; i < k; i++) {
    int u;
    std::cin >> u;
    que.push({u, 0});
  }
  for(int i = 0; i < n - 1; i++) {
    int u, v;
    std::cin >> u >> v;
    g[u].push_back({v, i});
    g[v].push_back({u, i});
  }
  std::set<int> ids;
  while (!que.empty()) {
    node r = que.front();
    que.pop();
    if (was[r.cur]) continue;
    else was[r.cur] = true;
    for(auto edge : g[r.cur]) {
      if (edge.first != r.from) {
        if (was[edge.first]) {
          ids.insert(edge.second);
        } else {
          que.push({edge.first, r.cur});
        }
      }
    }
  }
  std::cout << ids.size() << '\n';
  for(int i : ids) std::cout << i + 1 << " ";
  return 0;
}