#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll
#define F first
#define S second

const int N = 2e5 + 10;
const int BB = 100;
const int MX = N / BB + 100;
const int INF = 1e9 + 10;
const ll BINF = 1e18 + 10;

struct line {
  ll k, b;
  line() : k(-INF), b(-BINF) {};
  line(ll _k, ll _b) : k(_k), b(_b) {};
  ll get(int x) {
    return k * 1ll * x + b;
  }
  ll intersect(line l) {
    return (b - l.b) / (l.k - k);
  }
};

ll from[MX][BB + 1];
int Ptr[MX], Sz[MX];
line arr[MX][BB + 1];

void init(int id) {
  Sz[id] = 1;
  from[id][1] = -INF;
  arr[id][1] = line();
  Ptr[id] = 1;
}

void add_line(int id, line nl) {
  while (Sz[id] > 1) {
    if (nl.k == arr[id][Sz[id]].k || arr[id][Sz[id]].intersect(nl) < from[id][Sz[id]]) {
      Sz[id]--;
    }
    else {
      break;
    }
  }
  from[id][Sz[id] + 1] = arr[id][Sz[id]].intersect(nl);
  arr[id][Sz[id] + 1] = nl;
  Sz[id]++;
}

ll get(int id, int x) {
  Ptr[id] = min(Ptr[id], Sz[id]);
  while (Ptr[id] < Sz[id] && arr[id][Ptr[id] + 1].get(x) >= arr[id][Ptr[id]].get(x)) {
    Ptr[id]++;
  }
  return arr[id][Ptr[id]].get(x);
}

vector<int> g[N], order;
int A[N], B[N], sz[N], a[N], b[N];

void dfs(int v, int sumA, int sumB) {
  sz[v] = 1;
  order.pb(v);
  A[SZ(order) - 1] = sumA;
  B[SZ(order) - 1] = abs(sumB);
  for (auto u : g[v]) {
    dfs(u, sumA + a[u], sumB + b[u]);
    sz[v] += sz[u];
  }
}

int mx[N], L[N], R[N], ptr[N];
pair<ll, ll> lines[N];

void rebuild(int block_id) {
  int cur = 0;
  mx[block_id] = -INF;
  for (int i = L[block_id]; i <= R[block_id]; i++) {
    if (A[i] + ptr[block_id] >= 0) {
      lines[cur++] = {B[i], A[i] * 1ll * B[i]};
    }
    else {
      mx[block_id] = max(mx[block_id], A[i]);
      lines[cur++] = {-B[i], -A[i] * 1ll * B[i]};
    }
  }
  sort(lines, lines + cur);
  init(block_id);
  for (int i = 0; i < cur; i++) {
    add_line(block_id, line(lines[i].F, lines[i].S));   
  }
}

int pos[N], need_rebuild[N];
bool block_begin[N], block_end[N];
signed main() {
  ios_base::sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  for (int i = 2; i <= n; i++) {
    int p;
    cin >> p;
    g[p].pb(i);
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  dfs(1, a[1], b[1]);
  for (int i = 0; i < n; i++) {
    pos[order[i]] = i;
  }
  int cnt_blocks = (n + BB - 1) / BB;
  for (int i = 0; i < cnt_blocks; i++) {
    L[i] = BB * i;
    R[i] = min(BB * (i + 1), n) - 1;
    block_begin[L[i]] = true;
    block_end[R[i]] = true;
    ptr[i] = 0;
    rebuild(i);
  }
  int C = 0;
  for (int i = 1; i <= q; i++) {
    int type;
    cin >> type;
    if (type == 1) {
      int v, x;
      cin >> v >> x;
      int l = pos[v], r = pos[v] + sz[v] - 1;
      int fr = l / BB, to = r / BB;
      need_rebuild[fr] = need_rebuild[to] = i;
      while (l <= r && !block_begin[l]) {
        A[l] += x;
        l++;
      }
      while (r >= l && !block_end[r]) {
        A[r] += x;  
        r--;
      }
      if (l <= r) {
        for (int j = l / BB; j <= r / BB; j++) {
          ptr[j] += x;
          if (mx[j] + ptr[j] >= 0) {
            need_rebuild[j] = i;
          }
        }
      }
      for (int j = fr; j <= to; j++) {
        if (need_rebuild[j] == i) {
          C++;
          rebuild(j);
        }
      }
    }
    else {
      int v;
      cin >> v;
      int l = pos[v], r = pos[v] + sz[v] - 1;
      ll ans = 0;     
      while (l <= r && !block_begin[l]) {
        ans = max(ans, abs(A[l] + ptr[l / BB]) * 1ll * B[l]);
        l++;
      }
      while (r >= l && !block_end[r]) {
        ans = max(ans, abs(A[r] + ptr[r / BB]) * 1ll * B[r]);
        r--;
      }
      if (l <= r) {
        for (int j = l / BB; j <= r / BB; j++) {
          ans = max(ans, get(j, ptr[j]));
        }
      }
      cout << ans << '\n';
    }
  }
  cerr << "TIME :: " << clock() * 1.0 / CLOCKS_PER_SEC << '\n';
  cerr << "REBUILDS " << C << '\n';
}