
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

const int MAXN = 200050, MAXE = 400050;
int A[MAXN], nid[MAXN], child[MAXN], sign[MAXN], S[MAXN];

int ptr[MAXN], adj[MAXE], nxt[MAXE];

void add(int x, int v) {
  while (x <= MAXN) {
    S[x] += v;
    x += x & -x;
  }
}

int sum(int x) {
  int s = 0;
  while (x > 0) {
    s += S[x];
    x -= x & -x;
  }
  return s;
}

void dfs(int u, int s, int& k, int p = -1) {
  sign[u] = s;
  nid[u] = k;
  ++k;

  for (int z = ptr[u]; ~z; z = nxt[z]) {
    int v = adj[z];
    if (v != p) {
      dfs(v, -s, k, u);
    }
  }
  child[u] = k;
}

int main()
{
  int n, m;
  scanf("%d%d", &n, &m);

  for (int i = 0; i < n; ++i) {
    scanf("%d", &A[i]);
  }

  memset(ptr, ~0, sizeof(ptr));
  for (int i = 0, e = 0; i < n - 1; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    --u; --v;
    nxt[e] = ptr[u]; ptr[u] = e; adj[e] = v; ++e;
    nxt[e] = ptr[v]; ptr[v] = e; adj[e] = u; ++e;
  }

  int id = 1;
  dfs(0, 1, id);
  // for (int i = 0; i < n; ++i) printf("%d %d\n", nid[i], child[i]);

  memset(S, 0, sizeof(S));
  for (int i = 0; i < m; ++i) {
    int typ;
    scanf("%d", &typ);

    if (typ == 1) {
      int x, val;
      scanf("%d%d", &x, &val);
      --x;
      add(nid[x], val * sign[x]);
      add(child[x], -val * sign[x]);
      // for (int j = 0; j < n; ++j) printf("%d ", sum(nid[j])*sign[j]+A[j]);
      // puts("");
    } else {
      int x;
      scanf("%d", &x);
      --x;
      printf("%d\n", sum(nid[x]) * sign[x] + A[x]);
    }
  }

  return 0;
}