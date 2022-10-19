#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int M = N * 2;

#define int long long

int fir[N], ne[M], to[M], cnt, S[N], dep[N], n, x, y;

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

int ans, res;

void dfs(int x, int f) {
  dep[x] = dep[f] + 1;
  ans += dep[x];
  Foreachson(i, x) {
    int V = to[i];
    if(V == f) continue;
    dfs(V, x);
    S[x] += S[V];
  }
  ++ S[x];
}

void dfs2(int x, int f, int now) {
  res += now;
  Foreachson(i, x) {
    int V = to[i];
    if(V == f) continue;
    dfs2(V, x, now - S[V] + (n - S[V]));
  }
}

main() {
  cin >> n;
  for(int i = 1; i < n; ++ i) {
    scanf("%lld%lld", &x, &y);
    link(x, y);
  }
  dep[0] = -1;
  dfs(1, 0);
  dfs2(1, 0, ans);
  ans = 0;
  //cerr << res << endl;
  res = res / 2;
  for(int i = 1; i <= n; ++ i) ans += (dep[i] & 1);
  res += ans * (n - ans);
  res /= 2;
  //res /= 2;
  cout << res << endl;
}