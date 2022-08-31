#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

struct fenwick {
  long long fenw[2][N];

  fenwick() {
    for (int i = 0; i < N; i++) {
      fenw[0][i] = fenw[1][i] = 0;
    }
  }

  void modify(int q, int x, int v) {
    while (x < N) {
      fenw[q][x] += v;
      x = (x | (x - 1)) + 1;
    }
  }

  long long find_sum(int q, int x) {
    long long v = 0;
    while (x > 0) {
      v += fenw[q][x];
      x &= x - 1;
    }
    return v;
  }

  long long find_sum(int q, int ll, int rr) {
    return find_sum(q, rr) - find_sum(q, ll - 1);
  }
} tree[2];

vector <int> ev_l[N], ev_r[N];
bool none[N];
int l[N], r[N];


int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", l + i, r + i);
    ev_l[l[i]].push_back(i);
    ev_r[r[i]].push_back(i);
  }
  set <int> all[2];
  for (int i = 1; i <= m; i++) {
    tree[i % 2].modify(0, (i + 1) / 2, 1);
    tree[i % 2].modify(1, (i + 1) / 2, i);
    all[i % 2].insert(i);
  }
  long long ans = 0;
  multiset <int> open_l[2];
  int global = 1;
  for (int rg = 1; rg <= m; rg++) {
    for (int i : ev_l[rg]) {
      // add to open
      open_l[l[i] % 2].insert(l[i]);
    }
    int lg = global;
    if (!open_l[1 - rg % 2].empty()) {
      lg = max(lg, (*(--open_l[1 - rg % 2].end())) + 1);
    }
    int up_bad_parity = rg - 1;
    for (int par = 0; par < 2; par++) {
      if (!open_l[par].empty()) {
        int ll = (*(open_l[par].begin()));
        if (ll % 2 == rg % 2) {
          up_bad_parity = min(up_bad_parity, ll - 1);
        } else {
          up_bad_parity = min(up_bad_parity, -1);
        }
      }
    }
    for (int par = 0; par < 2; par++) {
      int from = lg;
      int to = rg;
      if (par != rg % 2) {
        to = min(to, up_bad_parity);
      }
      while (from <= to && from % 2 != par) {
        from++;
      }
      while (from <= to && to % 2 != par) {
        to--;
      }
      if (from <= to) {
        long long cnt = tree[par].find_sum(0, (from + 1) / 2, (to + 1) / 2);
        long long sum = tree[par].find_sum(1, (from + 1) / 2, (to + 1) / 2);
        ans += (rg + 1) * cnt - sum;
      }
    }
    for (int i : ev_r[rg]) {
      // add to close
      open_l[l[i] % 2].erase(open_l[l[i] % 2].find(l[i]));
      if ((r[i] - l[i] + 1) % 2 == 0) {
        global = max(global, l[i] + 1);
      }
      while (true) {
        auto it = all[1 - rg % 2].lower_bound(l[i]);
        if (it == all[1 - rg % 2].end()) {
          break;
        }
        if ((*it) > r[i]) {
          break;
        }
        int v = (*it);
        tree[v % 2].modify(0, (v + 1) / 2, -1);
        tree[v % 2].modify(1, (v + 1) / 2, -v);
        all[1 - rg % 2].erase(it);
      }
    }
  }
  set <int> help;
  for (int i = 1; i <= m; i++) {
    for (int j : ev_l[i]) {
      help.insert(j);
    }
    none[i] = (help.empty());
    for (int j : ev_r[i]) {
      help.erase(j);
    }
  }
  int cc = 0;
  for (int i = 1; i <= m; i++) {
    if (none[i]) {
      cc++;
      ans -= (long long) cc * (cc + 1) / 2;
    } else {
      cc = 0;
    }
  }
  cout << ans << endl;
  return 0;
}