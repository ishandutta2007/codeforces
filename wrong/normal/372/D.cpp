#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;

typedef unsigned uint;
typedef long long Int;

const int INF = 1001001001;
const Int INFLL = 1001001001001001001LL;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }

struct BIT {
  static const int BSZ = 200050;
  int N, B[BSZ];
  BIT(int n = 0) : N(n) {
    memset(B, 0, sizeof(B));
  }
  void add(int x, int v) {
    while (x <= N) {
      B[x] += v;
      x += x & -x;
    }
  }
  int sum(int x) {
    int s = 0;
    while (x > 0) {
      s += B[x];
      x -= x & -x;
    }
    return s;
  }
} B;

const int MAXV = 100050, MAXE = 2 * MAXV;
int ptr[MAXV], adj[MAXE], nxt[MAXE];
int id1[MAXV], id2[MAXV];
int parent[20][MAXV], depth[MAXV];

void dfs(int u, int& id, int p = -1, int d = 0) {
  id1[u] = id++;
  parent[0][u] = p;
  depth[u] = d;
  for (int z = ptr[u]; ~z; z = nxt[z]) {
    int v = adj[z];
    if (v != p) dfs(v, id, u, d + 1);
  }
  id2[u] = id++;
}

int subtree_cnt(int u) {
  return B.sum(id1[u]) - B.sum(id2[u]);
}

int add_to_set(int u) {
  int res = 0, org_u = u;
  if (subtree_cnt(u) > 0) {
    B.add(1, 1);
    B.add(id1[u] + 1, -1);
    return 0;
  }
  for (int i = 19; i >= 0; --i) {
    if (parent[i][u] == -1) {
      continue;
    }
    int v = parent[i][u];
    if (subtree_cnt(v) == 0) {
      u = v;
      res += 1<<i;
    }
  }
  B.add(1, 1);
  B.add(id1[org_u] + 1, -1);
  return u == 0 ? res : res + 1;
}

int remove_from_set(int u) {
  int res = 0;
  B.add(1, -1);
  B.add(id1[u] + 1, 1);
  if (subtree_cnt(u) > 0) {
    return 0;
  }
  for (int i = 19; i >= 0; --i) {
    if (parent[i][u] == -1) {
      continue;
    }
    int v = parent[i][u];
    if (subtree_cnt(v) == 0) {
      u = v;
      res += 1<<i;
    }
  }
  return u == 0 ? res : res + 1;
}

int num_idle_edges(int u, int num) {
  if (subtree_cnt(u) == num) { /* !!!!!!!!!!!!!!!!!! */
    return depth[u];           /* !!!!!!!!!!!!!!!!!! */
  }                            /* !!!!!!!!!!!!!!!!!! */
  for (int i = 19; i >= 0; --i) {
    if (parent[i][u] == -1) {
      continue;
    }
    int v = parent[i][u];
    if (subtree_cnt(v) < num) {
      u = v;
    }
  }
  assert(u != 0);
  u = parent[0][u];
  return depth[u];
}

int main()
{
  int n, k;
  scanf("%d%d", &n, &k);

  memset(ptr, ~0, sizeof(ptr));
  for (int i = 0, e = 0; i < n - 1; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a; --b;
    nxt[e] = ptr[a]; ptr[a] = e; adj[e] = b; ++e;
    nxt[e] = ptr[b]; ptr[b] = e; adj[e] = a; ++e;
  }

  int id = 1;
  dfs(0, id);

  for (int i = 1; i < 20; ++i) {
    for (int j = 0; j < n; ++j) {
      if (parent[i - 1][j] != -1) {
        parent[i][j] = parent[i - 1][parent[i - 1][j]];
      } else {
        parent[i][j] = -1;
      }
    }
  }

  int lo = 1, hi = k + 1;
  while (hi - lo > 1) {
    int mid = (hi + lo) / 2;
    
    B = BIT(2 * n + 10);
    int edges = 0;
    for (int i = 0; i < mid; ++i) {
      edges += add_to_set(i);
    }

    bool ok = edges + 1 - num_idle_edges(mid - 1, mid) <= k;
    for (int i = mid; !ok && i < n; ++i) {
      edges += add_to_set(i);
      edges -= remove_from_set(i - mid);
      ok |= edges + 1 - num_idle_edges(i, mid) <= k;
    }

    if (ok) {
      lo = mid;
    } else {
      hi = mid;
    }
  }

  printf("%d\n", lo);

  return 0;
}