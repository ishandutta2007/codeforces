#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int M = 2e5 + 5;
const int SZ = N * 25;

int n, m, q, x, y, z, val, sz, ch[SZ][2], S[SZ], rt[N], fir[N], ne[M], to[M], cnt, dep[N];

vector <int> T[N];

void add(int x, int y) {
  ne[++ cnt] = fir[x];
  fir[x] = cnt;
  to[cnt] = y;
}

void link(int x, int y) {
  add(x, y);
  add(y, x);
}

#define Foreachson(i, x) for(int i = fir[x]; i; i = ne[i])

#define lc ch[x][0]
#define rc ch[x][1]

void up(int x) {
  S[0] = 0;
  S[x] = S[lc] + S[rc];
}

void add(int &x, int l, int r, int val) {
  ++ sz;
  ch[sz][0] = ch[x][0];
  ch[sz][1] = ch[x][1];
  S[sz] = S[x];
  x = sz;
  if(l == r) {
    S[x] = 1;
    return;
  }
  int mid = (l + r) >> 1;
  if(val > mid) add(rc, mid + 1, r, val);
  else add(lc, l, mid, val);
  up(x);
  //cerr << x << " " << S[x] << endl;
}

int st[N][20];

void dfs(int x, int f) {
  dep[x] = dep[f] + 1;
  st[x][0] = f;
  for(int i = 1; i < 20; ++ i)
    st[x][i] = st[st[x][i - 1]][i - 1];
  rt[x] = rt[f];
  for(int i = 0; i < (int) T[x].size(); ++ i)
    add(rt[x], 1, m, T[x][i]);
  Foreachson(i, x) {
    int V = to[i];
    if(V == f) continue;
    dfs(V, x);
  }
  //cerr << x <<" " << S[rt[x]] << endl;
}

int LCA(int x, int y) {
  if(dep[x] > dep[y]) swap(x, y);
  for(int i = 19; i >= 0; -- i)
    if(dep[st[y][i]] >= dep[x])
      y = st[y][i];
  if(x == y) return x;
  for(int i = 19; i >= 0; -- i)
    if(st[x][i] != st[y][i]) {
      x = st[x][i], y = st[y][i];
    }
  return st[x][0];
}

void query(int a, int b, int c, int d, int l, int r, int val) {
  if(l == r) {
    if(S[a] + S[b] - S[c] - S[d])
    printf("%d ", l);
    return;
  }
  int mid = (l + r) >> 1;
  int All = S[ch[a][0]] + S[ch[b][0]] - S[ch[c][0]] - S[ch[d][0]];
  if(All >= val)
    return (void)query(ch[a][0], ch[b][0], ch[c][0], ch[d][0], l, mid, val);
  query(ch[a][0], ch[b][0], ch[c][0], ch[d][0], l, mid, All);
  query(ch[a][1], ch[b][1], ch[c][1], ch[d][1], mid + 1, r, val - All);
}

int main() {
  scanf("%d%d%d", &n, &m, &q);
  for(int i = 1; i < n; ++ i) {
    scanf("%d%d", &x, &y);
    link(x, y);
  }
  for(int i = 1; i <= m; ++ i) {
    scanf("%d", &x);
    T[x].push_back(i);
  }
  dfs(1, 0);
  //cerr << "HERE" << endl;
  for(; q --;) {
    scanf("%d%d%d", &x, &y, &z);
    int L = LCA(x, y);
    //cerr << x <<" " << y <<" " << z <<" " << L << endl;
    int now = st[L][0];
    int All = S[rt[x]] + S[rt[y]] - S[rt[L]] - S[rt[now]];
    z = min(z, All);
    printf("%d ", z);
    if(z) query(rt[x], rt[y], rt[L], rt[now], 1, m, z);
    puts("");
  }
}