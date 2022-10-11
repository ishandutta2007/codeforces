#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define gcd(x,y) __gcd((x),(y))

#ifndef ONLINE_JUDGE
  #define db(x) cerr << #x << " == " << x << endl
  #define dbs(x) cerr << x << endl
  #define _ << ", " <<
#else
  #define db(x)
  #define dbs(x)
#endif

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

struct PersistentSegtree {
  vector<int> lc, rc, st;

  PersistentSegtree() { create(); }

  int create() {
    lc.push_back(0);
    rc.push_back(0);
    st.push_back(INF);
    return st.size()-1;
  }

  int update(int p, int l, int r, int i, int v) {
    int rt = create();

    if (l == r) { st[rt] = v; return rt; }

    int mid = (l+r)/2;
    if (i <= mid) {
      int u = update(lc[p], l, mid, i, v);
      lc[rt] = u;
      rc[rt] = rc[p];
    } else {
      int u = update(rc[p], mid+1, r, i, v);
      lc[rt] = lc[p];
      rc[rt] = u;
    }

    st[rt] = min(st[lc[rt]], st[rc[rt]]);

    return rt;
  }

  int query(int p, int l, int r, int i, int j) {
    if (l > j or r < i) return INF;
    if (i <= l and r <= j) return st[p];
    int m = (l+r)/2;
    return min(query(lc[p], l, m, i, j), query(rc[p], m+1, r, i, j));
  }
} tree;

int n, r, a[N], x, y, m, last;
int remap[N], tin[N], tout[N], depth[N], cnt, vis[N];
int root[N], max_depth;
vector<int> adj[N], ins[N];

void dfs(int u, int d) {
  if (vis[u]) return;
  vis[u] = 1;

  int x = ++cnt;
  remap[u] = x;
  depth[x] = d;
  ins[d].push_back(u);

  max_depth = max(max_depth, d);

  tin[x] = cnt;
  for (int v : adj[u]) dfs(v, d+1);
  tout[x] = cnt;
}

void create_tree() {
  for (int i = 0; i <= max_depth; i++) {
    for (int x : ins[i])
      root[i] = tree.update(root[i], 1, n, tin[remap[x]], a[x]);
    root[i+1] = root[i];
  }
}

int query(int x, int k) {
  x = remap[x];
  int d = min(max_depth, depth[x]+k);
  return tree.query(root[d], 1, n, tin[x], tout[x]);
}

int main() {
  scanf("%d%d", &n, &r);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n-1; i++) {
    scanf("%d%d", &x, &y);
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  dfs(r, 0);
  create_tree();

  /*
  for (int i = 0; i < tree.st.size(); i++)
    db(i _ tree.lc[i] _ tree.rc[i] _ tree.st[i]);
    */

  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &x, &y);
    x = (x+last)%n + 1;
    y = (y+last)%n;
    //db(x _ y);

    last = query(x, y);
    printf("%d\n", last);
  }

  return 0;
}