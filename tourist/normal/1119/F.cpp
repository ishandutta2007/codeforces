/**
 *    author:  tourist
 *    created: 06.04.2019 13:16:09       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<pair<int, int>>> graph(n);
  long long total = 0;
  for (int i = 0; i < n - 1; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    x--; y--;
    graph[x].emplace_back(y, z);
    graph[y].emplace_back(x, z);
    total += z;
  }
  vector<vector<int>> at_deg(n);
  vector<int> deg(n);
  for (int i = 0; i < n; i++) {
    deg[i] = (int) graph[i].size();
    at_deg[deg[i]].push_back(i);
  }
  vector<vector<pair<int, int>>> g(n);
  vector<int> alive(n, 0);
  vector<multiset<int>> extra_small(n);
  vector<multiset<int>> extra_big(n);
  vector<long long> sum_extra_big(n, 0);
  vector<long long> res(n, 0);
  set<int> lovers;
  long long saved = total;
  vector<int> was(n, -1);
  for (int dd = n - 1; dd >= 1; dd--) {
    auto BalanceOver = [&](int v) {
      while ((int) extra_big[v].size() > dd) {
        auto it = extra_big[v].begin();
        sum_extra_big[v] -= *it;
        extra_small[v].insert(*it);
        extra_big[v].erase(it);
      }
    };
    auto BalanceUnder = [&](int v) {
      while ((int) extra_big[v].size() < dd && !extra_small[v].empty()) {
        auto it = prev(extra_small[v].end());
        sum_extra_big[v] += *it;
        extra_big[v].insert(*it);
        extra_small[v].erase(it);
      }
    };
    auto Add = [&](int x, int y) {
      extra_big[x].insert(y);
      sum_extra_big[x] += y;
      BalanceOver(x);
    };
    auto Remove = [&](int x, int y) {
      auto it = extra_small[x].find(y);
      if (it != extra_small[x].end()) {
        extra_small[x].erase(it);
      } else {
        it = extra_big[x].find(y);
        assert(it != extra_big[x].end());
        extra_big[x].erase(it);
        sum_extra_big[x] -= y;
        BalanceUnder(x);
      }
    };
    for (int v : lovers) {
      BalanceOver(v);
    }
    function<pair<long long, long long>(int, int)> dfs = [&](int v, int pr) -> pair<long long, long long> {
      was[v] = dd;
      vector<long long> saveable;
      long long overall = 0;
      long long total_saveable = 0;
      int up_cost = 0;
      for (auto& p : g[v]) {
        int to = p.first;
        int cost = p.second;
        if (to == pr) {
          up_cost = cost;
          continue;
        }
        auto z = dfs(to, v);
        overall += z.first;
        if (z.second > z.first) {
          saveable.push_back(z.second - z.first);
          total_saveable += z.second - z.first;
        }
      }
      sort(saveable.begin(), saveable.end());
      int cnt = (int) saveable.size() + (int) extra_big[v].size();
      long long val = overall + total_saveable + sum_extra_big[v];
      int i = 0;
      auto it = extra_big[v].begin();
      long long tmp0 = -1;
      long long tmp1 = -1;
      for (int rot = 0; rot < 2; rot++) {
        while (cnt > dd - rot) {
          if (it == extra_big[v].end() || (i < (int) saveable.size() && saveable[i] < *it)) {
            val -= saveable[i];
            ++i;
          } else {
            val -= *it;
            ++it;
          }
          cnt--;
        }
        if (rot == 0) {
          tmp0 = val;
        } else {
          tmp1 = val;
        }
      }
      return make_pair(tmp0, tmp1 + up_cost);
    };
    long long dp = 0;
    for (int v : lovers) {
      if (was[v] == dd) {
        continue;
      }
      auto p = dfs(v, -1);
      dp += p.first;
    }
    res[dd] = total - (saved + dp);
    for (int v : at_deg[dd]) {
      for (auto& p : graph[v]) {
        int u = p.first;
        int cost = p.second;
        if (alive[u]) {
          g[v].emplace_back(u, cost);
          g[u].emplace_back(v, cost);
          Remove(u, cost);
        } else {
          Add(v, cost);
          saved -= cost;
        }
      }
      alive[v] = 1;
      lovers.insert(v);
    }
  }
  res[0] = total;
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << res[i];
  }
  cout << '\n';
  return 0;
}