/**
 *    author:  tourist
 *    created: 28.01.2021 19:09:28       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
      int x, y;
      cin >> x >> y;
      --x; --y;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    for (int i = 0; i < n; i++) {
      sort(g[i].begin(), g[i].end());
    }
    set<int> alive;
    for (int i = 0; i < n; i++) {
      alive.insert(i);
    }
    vector<int> p(n);
    vector<int> q(n);
    vector<vector<int>> tree(n);
    vector<vector<int>> star(n);
    vector<int> que;
    vector<pair<int, int>> edges;
    vector<pair<int, int>> mats;
    vector<bool> taken(n, false);
    int done = 0;
    vector<vector<int>> stars;
    vector<int> cur_star;
    while (!alive.empty()) {
      que.clear();
      que.push_back(*alive.begin());
      alive.erase(alive.begin());
      edges.clear();
      for (int b = 0; b < (int) que.size(); b++) {
        int me = que[b];
        auto it = alive.begin();
        int ptr = 0;
        while (it != alive.end()) {
          while (ptr < (int) g[me].size() && g[me][ptr] < *it) {
            ++ptr;
          }
          if (ptr < (int) g[me].size() && g[me][ptr] == *it) {
            ++it;
          } else {
            tree[me].push_back(*it);
            tree[*it].push_back(me);
            edges.emplace_back(me, *it);
            que.push_back(*it);
            it = alive.erase(it);
          }
        }
      }
      if ((int) que.size() == 1) {
        p[que[0]] = done;
        q[que[0]] = done;
        done += 1;
        continue;
      }
      mats.clear();
      for (auto& e : edges) {
        if (!taken[e.first] && !taken[e.second]) {
          taken[e.first] = true;
          taken[e.second] = true;
          mats.push_back(e);
        }
      }
      for (int x : que) {
        if (!taken[x]) {
          int y = tree[x][0];
          assert(taken[y]);
          star[y].push_back(x);
        }
      }
      for (auto& e : mats) {
        int x = e.first;
        int y = e.second;
        if (star[y].empty()) {
          swap(x, y);
        }
        if (star[x].empty()) {
          cur_star.clear();
          cur_star.push_back(y);
          cur_star.push_back(x);
          for (int u : star[y]) {
            cur_star.push_back(u);
          }
          stars.push_back(cur_star);
          continue;
        }
        assert(!star[x].empty() && !star[y].empty());
        for (int rot = 0; rot < 2; rot++) {
          int z = (rot == 0 ? x : y);
          cur_star.clear();
          cur_star.push_back(z);
          for (int u : star[z]) {
            cur_star.push_back(u);
          }
          stars.push_back(cur_star);
        }
      }
    }
    for (auto& s : stars) {
      int sz = (int) s.size();
      for (int i = 0; i < sz; i++) {
        p[s[i]] = done + i;
      }
      q[s[0]] = done + sz - 1;
      for (int i = 1; i < sz; i++) {
        q[s[i]] = done + i - 1;
      }
      done += sz;
    }
    assert(done == n);
    for (int i = 0; i < n; i++) {
      if (i > 0) {
        cout << " ";
      }
      cout << p[i] + 1;
    }
    cout << '\n';
    for (int i = 0; i < n; i++) {
      if (i > 0) {
        cout << " ";
      }
      cout << q[i] + 1;
    }
    cout << '\n';
  }
  return 0;
}