/**
 *    author:  tourist
 *    created: 03.09.2017 13:50:22       
**/

// HackerRank University CodeSprint, problem "Counting On a Tree", modified

#include <bits/stdc++.h>

using namespace std;

struct Query {
  int a;
  int b;
  int coeff;
  int id;
};

int BLOCK;

inline bool cmp(Query &x, Query &y) {
  int X = x.a / BLOCK;
  int Y = y.a / BLOCK;
  if (X != Y) {
    return X < Y;
  }
  return x.b < y.b;
}

const int N = 100010;
const int LOG = 20;

vector <int> order;
int entry[N], brexit[N];
int pv[N];
int pr[N][LOG];
Query qs[16 * N];
long long result[N];
int in_a[N], in_b[N];
int label[N];
vector <int> g[N];
int depth[N];
pair <int, int> ev[N];
int type[N];

void dfs(int v, int pr) {
  entry[v] = order.size();
  order.push_back(v);
  int sz = g[v].size();
  for (int j = 0; j < sz; j++) {
    int u = g[v][j];
    if (u != pr) {
      pv[u] = v;
      depth[u] = depth[v] + 1;
      dfs(u, v);
    }
  }
  brexit[v] = order.size();
  order.push_back(~v);
}

inline bool anc(int x, int y) {
  return (entry[x] <= entry[y] && brexit[y] <= brexit[x]);
}

inline int lca(int x, int y) {
  if (anc(x, y)) {
    return x;
  }
  for (int j = LOG - 1; j >= 0; j--) {
    if (!anc(pr[x][j], y)) {
      x = pr[x][j];
    }
  }
  return pr[x][0];
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", type + i);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &ev[i].first);
    ev[i].second = i;
  }
  sort(ev, ev + n);
  int cur_label = 0;
  for (int i = 0; i < n; i++) {
    if (i > 0 && ev[i].first != ev[i - 1].first) {
      cur_label++;
    }
    label[ev[i].second] = cur_label;
  }
  for (int i = 0; i < n - 1; i++) {
    int foo, bar;
    scanf("%d %d", &foo, &bar);
    foo--; bar--;
    g[foo].push_back(bar);
    g[bar].push_back(foo);
  }
  int tt;
  scanf("%d", &tt);
  pv[0] = 0;
  depth[0] = 0;
  dfs(0, -1);
  for (int i = 0; i < n; i++) {
    pr[i][0] = pv[i];
  }
  for (int j = 1; j < LOG; j++) {
    for (int i = 0; i < n; i++) {
      pr[i][j] = pr[pr[i][j - 1]][j - 1];
    }
  }
  int cnt = 0;
  for (int i = 0; i < tt; i++) {
    int w, x, y, z;
    scanf("%d %d", &w, &x);
    y = w; z = x;
    w--; x--; y--; z--;
    vector < pair <int, int> > a, b;
    {
      int LCA = lca(w, x);
      a.push_back(make_pair(w, 1));
      a.push_back(make_pair(x, 1));
      a.push_back(make_pair(LCA, -1));
      if (LCA != 0) {
        a.push_back(make_pair(pv[LCA], -1));
      }
    }
    {
      int LCA = lca(y, z);
      b.push_back(make_pair(y, 1));
      b.push_back(make_pair(z, 1));
      b.push_back(make_pair(LCA, -1));
      if (LCA != 0) {
        b.push_back(make_pair(pv[LCA], -1));
      }
    }
    for (int ia = 0; ia < (int) a.size(); ia++) {
      for (int ib = 0; ib < (int) b.size(); ib++) {
        Query &q = qs[cnt++];
        q.a = entry[a[ia].first];
        q.b = entry[b[ib].first];
        q.coeff = a[ia].second * b[ib].second;
        q.id = i;
//        result[i] -= q.coeff * (depth[lca(order[q.a], order[q.b])] + 1);
//        cerr << "query " << q.a << " " << q.b << " " << q.coeff << " " << q.id << " -> " << result[i] << endl;
      }
    }
  }
  BLOCK = (int) (1 + sqrt(order.size()));
  sort(qs, qs + cnt, cmp);
  long long sum = 0;
  int x = -1, y = -1;
  for (int id = 0; id < cnt; id++) {
    Query &q = qs[id];
    while (x < q.a) {
      x++;
      if (type[order[x] >= 0 ? order[x] : ~order[x]] == 0) {
        if (order[x] >= 0) {
          sum += in_b[label[order[x]]];
          in_a[label[order[x]]]++;
        } else {
          sum -= in_b[label[~order[x]]];
          in_a[label[~order[x]]]--;
        }
      }
    }
    while (y < q.b) {
      y++;
      if (type[order[y] >= 0 ? order[y] : ~order[y]] == 1) {
        if (order[y] >= 0) {
          sum += in_a[label[order[y]]];
          in_b[label[order[y]]]++;
        } else {
          sum -= in_a[label[~order[y]]];
          in_b[label[~order[y]]]--;
        }
      }
    }
    while (x > q.a) {
      if (type[order[x] >= 0 ? order[x] : ~order[x]] == 0) {
        if (order[x] >= 0) {
          sum -= in_b[label[order[x]]];
          in_a[label[order[x]]]--;
        } else {
          sum += in_b[label[~order[x]]];
          in_a[label[~order[x]]]++;
        }
      }
      x--;
    }
    while (y > q.b) {
      if (type[order[y] >= 0 ? order[y] : ~order[y]] == 1) {
        if (order[y] >= 0) {
          sum -= in_a[label[order[y]]];
          in_b[label[order[y]]]--;
        } else {
          sum += in_a[label[~order[y]]];
          in_b[label[~order[y]]]++;
        }
      }
      y--;
    }
    result[q.id] += q.coeff * sum;
  }
  for (int i = 0; i < tt; i++) {
    printf("%lld\n", result[i]);
  }
  return 0;
}