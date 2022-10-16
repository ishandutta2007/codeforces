#include <bits/stdc++.h>

using namespace std;

#define eprintf( ... ) fprintf(stderr, __VA_ARGS__)

const int INF = 998244353;
const int maxn = 2e5 + 5;

mt19937 rnd(2226701);

inline int qpow(int x, int y){
  int ret = 1;
  for(; y; y >>= 1){
    if(y & 1)
      ret = 1ll * ret * x % INF;
    x = 1ll * x * x % INF;
  }
  return ret;
}

class Treap{
public:
  class Data{
  public:
    int ls, rs, key, siz, val, mn;
    Data(int val_ = 0): val(val_), mn(val_), siz(1), key(rnd()), ls(0), rs(0){}
  } dat[maxn];

  int rt;
  
  Treap(){
    dat[0] = Data(0), dat[0].siz = 0, dat[0].mn = 0x3f3f3f3f;
    for(int i = 1; i < maxn; ++i)
      dat[i] = Data(i), merge(rt, rt, i);
    return;
  }
  
  inline void pushUp(int u){
    dat[u].siz = dat[dat[u].ls].siz + 1 + dat[dat[u].rs].siz;
    dat[u].mn = dat[u].ls ? dat[dat[u].ls].mn : u;
    return;
  }
  
  inline void split(int u, int &x, int &y, int k){
    if(!u){
      x = y = 0;
      return;
    }
    if(dat[dat[u].ls].siz + 1 <= k)
      split(dat[u].rs, dat[u].rs, y, k - dat[dat[u].ls].siz - 1), x = u;
    else
      split(dat[u].ls, x, dat[u].ls, k), y = u;
    pushUp(u);
    return;
  }

  inline void merge(int &u, int x, int y){
    if(!x || !y){
      u = (x ^ y);
      return;
    }
    if(dat[x].key < dat[y].key)
      merge(dat[y].ls, x, dat[y].ls), u = y;
    else
      merge(dat[x].rs, dat[x].rs, y), u = x;
    pushUp(u);
    return;
  }
} trp;

set<int> S;

inline void insert(int x, int y){
  int u, v, w, a, b;
  trp.split(trp.rt, u, v, x - 1);
  trp.split(v, v, w, 1);
  trp.split(u, a, b, y - 1);
  S.insert(trp.dat[b].mn);
  trp.merge(u, a, v);
  trp.merge(u, u, b);
  trp.merge(trp.rt, u, w);
  return;
}

inline void reinsert(int x, int y){
  int u, v, a, b, c;
  trp.split(trp.rt, u, v, x);
  trp.split(u, a, b, y - 1);
  trp.split(b, b, c, 1);
  trp.merge(u, a, c);
  trp.merge(trp.rt, u, b);
  trp.merge(trp.rt, trp.rt, v);
  return;
}

int n, m;
int qx[maxn], qy[maxn], fac[maxn * 2], ifac[maxn * 2];

inline int binom(int x, int y){ return 1ll * fac[x] * ifac[y] % INF * ifac[x - y] % INF; }

inline void solve(){
  scanf("%d%d", &n, &m);
  S.clear();
  for(int i = 0; i < m; ++i){
    scanf("%d%d", qx + i, qy + i);
    insert(qx[i], qy[i]);
  }

  int sum = S.size();
  
  printf("%d\n", binom(n + (n - sum - 1), n));
  
  for(int i = m - 1; i >= 0; --i)
    reinsert(qx[i], qy[i]);
  return;
}

int main(){
  //freopen("D.in", "r", stdin);
  
  fac[0] = 1; for(int i = 1; i < maxn * 2; ++i) fac[i] = 1ll * fac[i - 1] * i % INF;
  ifac[maxn * 2 - 1] = qpow(fac[maxn * 2 - 1], INF - 2); for(int i = maxn * 2 - 2; i >= 0; --i) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % INF;

  int T;
  for(scanf("%d", &T); T--; solve());
  return 0;
}