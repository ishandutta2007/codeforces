#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int M = N * 2;

#define Foreachson(i, x) for(int i = fir[x]; i; i = ne[i])

int fir[N], ne[M], to[M], cnt, x, y, n, m, ty, rt, Min[N];

inline void add(int x, int y) {
  ne[++ cnt] = fir[x];
  fir[x] = cnt;
  to[cnt] = y;
}

inline void link(int x, int y) {
  add(x, y);
  add(y, x);
}

void dfs(int x, int f) {
  Min[x] = x;
  if(f)Min[x] = min(Min[x], Min[f]);
  Foreachson(i, x) {
    int V = to[i];
    if(V == f) continue;
    dfs(V, x);
  }
}

int ans = 2e9, last, q;

int main() {
  scanf("%d%d", &n, &q);
  for(int i = 1; i < n; ++ i) scanf("%d%d", &x, &y), link(x, y);
  for(int i = 1; i <= q; ++ i) {
    scanf("%d%d", &ty, &x);
    x = (x + last) % n + 1;
    //puts("");
    //cerr << ty << " "<< x << " " << i <<  endl;
    if(i == 1) {
      rt = x;
      dfs(x, 0);
    }
    if(ty == 1) ans = min(ans, Min[x]);
    else printf("%d\n", last = min(ans, Min[x]));
  }
}