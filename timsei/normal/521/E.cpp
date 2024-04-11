#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int M = N * 2;

int fir[N], ne[M], to[M], cnt, n, m;

vector <int> F[M];

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

struct Edge {
  int x, y;
  void input(void) {
    scanf("%d%d", &x, &y);
  }
}E[M];

int Fff[N];

int getf(int x) {
  return (Fff[x] == x) ? x : Fff[x] = getf(Fff[x]);
}

vector <Edge> rest;

void init(void) {
  for(int i = 1; i <= n; ++ i) Fff[i] = i;
  for(int i = 1; i <= m; ++ i) {
    E[i].input();
    if(getf(E[i].x) == getf(E[i].y)) {
      rest.push_back(E[i]);
      continue;
    }
    link(E[i].x, E[i].y);
    Fff[getf(E[i].x)] = getf(E[i].y);
  }
}

bool vis[N];

int dep[N], fa[N];

void dfs(int x, int f) {
  vis[x] = 1; dep[x] = dep[f] + 1;
  fa[x] = f;
  Foreachson(i, x) {
    int V = to[i];
    if(V == f) continue;
    dfs(V, x);
  }
}

vector <int> This;

vector <int> ans;

vector <int> add(vector <int> a, vector <int> b) {
  for(int i = 0; i < (int) b.size(); ++ i) a.push_back(b[i]);
  return a;
}

int du[N], tim[N];

int LCA(int x, int y) {
  if(dep[x] > dep[y]) swap(x, y);
  while(dep[x] != dep[y]) y = fa[y];
  while(x != y) {
    x = fa[x];
    y = fa[y];
  }
  return x;
}

pair <int, int> calc(int A, int B, int C, int D) {
  int L1 = LCA(A, B), L2 = LCA(C, D);
  while(A != L1) ++ tim[A], A = fa[A];
  while(B != L1) ++ tim[B], B = fa[B];
  while(C != L2) ++ tim[C], C = fa[C];
  while(D != L2) ++ tim[D], D = fa[D];
  for(int i = 1; i <= n; ++ i)
    if(tim[i] == 2) ++ du[i], ++ du[fa[i]];
  vector <int> cxt;
  cxt.clear();
  for(int i = 1; i <= n; ++ i) if(du[i] == 1) cxt.push_back(i);
  return make_pair(cxt[0], cxt[1]);
}

void go(int x, int y) {
  int L = LCA(x, y);
  while(x != L) {
    ans.push_back(x);
    x = fa[x];
  }
  ans.push_back(L);
  vector <int> cxt; cxt.clear();
  while(y != L) cxt.push_back(y), y = fa[y];
  reverse(cxt.begin(), cxt.end());
  ans = add(ans, cxt);
}

void print(vector <int> ans) {
  printf("%d ", (int)ans.size());
  for(int i = 0; i < (int) ans.size(); ++ i) printf("%d ", ans[i]);
  puts("");
}

#define fork(A, B, C, D) go(A, B), go(C, D)

void doit(pair <int, int> tmp, int A, int B) {
  fork(tmp.first, A, B, tmp.second);
  vector <int> res = ans;
  ans.clear();
  fork(tmp.second, A, B, tmp.first);
  reverse(ans.begin(), ans.end());
  if(ans.size() > res.size()) {
    ans = res;
  }
  print(ans);
  ans.clear();  
}

void solve(int x, int y) {
  int A = rest[x].x, B = rest[x].y, C = rest[y].x, D = rest[y].y;
  pair <int, int> tmp = calc(A, B, C, D);
  ans.clear();
  go(tmp.first, tmp.second); print(ans); ans.clear();
  doit(tmp, A, B);
  doit(tmp, C, D);
  exit(0);
}

void add(int x, int y, int z) {
  This.clear();
  if(dep[x] < dep[y]) swap(x, y);
  while(dep[x] != dep[y]) {
    F[x].push_back(z);
    if(F[x].size() >= 2) This.push_back(x);
    x = fa[x];
  }
  while(x != y) {
    F[x].push_back(z);if(F[x].size() >= 2) This.push_back(x);
    F[y].push_back(z);if(F[y].size() >= 2) This.push_back(y);
    x = fa[x]; y = fa[y];
  }
  if(This.size()) {
    puts("YES");
    solve(F[This[0]][0], F[This[0]][1]);
    exit(0);
  }
}

int main(void) {
  scanf("%d%d", &n, &m);
  init();
  for(int i = 1; i <= n; ++ i) if(!vis[i]) dfs(i, 0);
  for(int i = 0; i < (int)rest.size(); ++ i) {
    add(rest[i].x, rest[i].y, i);
  }
  puts("NO");
}