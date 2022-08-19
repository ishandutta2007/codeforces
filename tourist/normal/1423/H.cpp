/**
 *    author:  tourist
 *    created: 05.10.2020 17:41:39       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q, k;
  cin >> n >> q >> k;
  vector<pair<int, int>> e;
  vector<int> day;
  vector<int> where;
  int cur_day = 0;
  int ptr = 0;
  vector<int> eid;
  vector<int> match;
  for (int i = 0; i < q; i++) {
    int type;
    cin >> type;
    if (type == 1) {
      int x, y;
      cin >> x >> y;
      --x; --y;
      where.push_back((int) eid.size());
      eid.push_back((int) e.size());
      match.push_back(-1);
      e.emplace_back(x, y);
      day.push_back(cur_day);
    }
    if (type == 2) {
      int z;
      cin >> z;
      --z;
      eid.push_back(~z);
      match.push_back(-1);
    }
    if (type == 3) {
      cur_day += 1;
      while (ptr < (int) e.size() && day[ptr] <= cur_day - k) {
        match[where[ptr]] = (int) eid.size();
        eid.push_back(ptr);
        match.push_back(where[ptr]);
        ptr += 1;
      }
    }
  }

  vector< pair<int, int> > ops[123];
  vector<int> p(n);
  vector<int> sz(n);
  for (int i = 0; i < n; i++) {
    p[i] = i;
    sz[i] = 1;
  }

  auto rollback = [&](int level) {
    while (!ops[level].empty()) {
      int i = ops[level].back().first;
      int j = ops[level].back().second;
      if (i >= 0) {
        p[i] = j;
      } else {
        sz[~i] = j;
      }
      ops[level].pop_back();
    }
  };

  auto set_p = [&](int a, int b, int level) {
    ops[level].emplace_back(a, p[a]);
    p[a] = b;
  };

  auto set_sz = [&](int a, int b, int level) {
    ops[level].emplace_back(~a, sz[a]);
    sz[a] = b;
  };

  function<int(int, int)> get = [&](int x, int level) {
    if (x != p[x]) {
      set_p(x, get(p[x], level), level);
    }
    return p[x];
  };

  auto join = [&](int eid, int level) {
    int x = get(e[eid].first, level);
    int y = get(e[eid].second, level);
    if (x != y) {
      if (sz[x] > sz[y]) {
        swap(x, y);
      }
      set_p(x, y, level);
      set_sz(y, sz[y] + sz[x], level);
    }
  };

  function<void(int, int, int)> solve = [&](int L, int R, int level) {
    if (L == R) {
      if (eid[L] < 0) {
        int v = ~eid[L];
        int par = get(v, level);
        cout << sz[par] << '\n';
        rollback(level);
      }
      return;
    }
    int M = (L + R) / 2;
    for (int i = M + 1; i <= R; i++) {
      if (eid[i] >= 0 && (match[i] >= 0 && match[i] < L)) {
        join(eid[i], level);
      }
    }
    solve(L, M, level + 1);
    rollback(level);
    for (int i = L; i <= M; i++) {
      if (eid[i] >= 0 && (match[i] == -1 || match[i] > R)) {
        join(eid[i], level);
      }
    }
    solve(M + 1, R, level + 1);
    rollback(level);
  };
  solve(0, (int) eid.size() - 1, 0);
  return 0;
}