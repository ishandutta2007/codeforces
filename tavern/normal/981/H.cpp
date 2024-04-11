#include <bits/stdc++.h>

using namespace std;

#define eprintf( ... ) fprintf(stderr, __VA_ARGS__)
#define FOR(i, x, y) for(int i = (int)(x); i < (int)(y); ++i)
#define PB push_back

const int maxn = 1e5 + 5;
const int INF = 998244353;
const int gR = 3;
const int SIZ = 524288;
int btf[SIZ];
int A[SIZ], B[SIZ], C[SIZ], W[SIZ], IW[SIZ], T[SIZ];

inline int qpow(int x, int y){
  int ret = 1;
  for(; y; y >>= 1){
    if(y & 1)
      ret = 1ll * ret * x % INF;
    x = 1ll * x * x % INF;
  }
  return ret;
}

inline void prepare(int siz){
  memset(A, 0, sizeof(int) * siz);
  memset(B, 0, sizeof(int) * siz);
  FOR(i, 0, siz)
    btf[i] = (btf[i >> 1] >> 1) + (i & 1) * (siz >> 1);
  int cur = qpow(gR, (INF - 1) / siz);
  W[0] = 1; FOR(i, 1, siz) W[i] = 1ll * W[i - 1] * cur % INF;
  cur = qpow(gR, INF - 1 - (INF - 1) / siz);
  IW[0] = 1; FOR(i, 1, siz) IW[i] = 1ll * IW[i - 1] * cur % INF;
  return; 
}

inline void ntt(int *vec, int siz, int INTT = 1){
  FOR(i, 0, siz) if(i < btf[i])
    swap(vec[i], vec[btf[i]]);
  for(int step = 1; step < siz; step <<= 1){
    FOR(i, 0, step)
      T[i] = (~INTT ? W[siz / (step << 1) * i] : IW[siz / (step << 1) * i]);
    for(int i = 0; i < siz; i += step << 1){
      int *p1 = vec + i, *p2 = vec + i + step, *p3 = T;
      for(int j = 0; j < step; ++j, ++p1, ++p2, ++p3){
	int u = *p1, v = 1ll * (*p2) * (*p3) % INF;
	*p1 = (u + v - (u + v >= INF ? INF : 0));
	*p2 = (u - v + (u - v <    0 ? INF : 0));
      }
    }
  }
	
  if(!~INTT){
    int iv = qpow(siz, INF - 2);
    FOR(i, 0, siz)
      vec[i] = 1ll * vec[i] * iv % INF; 
  }
  return;
}

class Poly: public vector<int>{
public:
  inline Poly(int n_ = 1){ clear(); resize(n_); return; }
	
  inline Poly &operator *= (const Poly &O){
    int siz = 1;
    for(; siz < size() + O.size() - 1; siz <<= 1);
    if(1ll * size() * O.size() <= 4096){
      memset(C, 0, siz * sizeof(int));
      FOR(i, 0, size()) FOR(j, 0, O.size())
	(C[i + j] += 1ll * at(i) * O[j] % INF) %= INF;
      resize(siz);
      FOR(i, 0, siz)
	at(i) = C[i];
      return *this;
    }

    prepare(siz);
    FOR(i, 0, size())
      A[i] = at(i);
    FOR(i, 0, O.size())
      B[i] = O[i];
    ntt(A, siz);
    ntt(B, siz);
		
    FOR(i, 0, siz)
      C[i] = 1ll * A[i] * B[i] % INF;
    ntt(C, siz, -1);
		
    resize(siz);
    FOR(i, 0, siz)
      at(i) = C[i];
    return *this;
  }

  inline Poly operator * (const Poly &O){ Poly R = *this; R *= O; return R; }
} P[maxn];

int n, k, ans;
int f[maxn], g[maxn], siz[maxn], fac[maxn], ifac[maxn];
vector<int> tree[maxn];

inline Poly conquer(int l, int r, vector<int> &vec){
  //eprintf("l = %d r = %d\n", l, r);
  Poly R;
  if(l > r){
    R = Poly(1);
    R[0] = 1;
    return R;
  }
  if(l == r){
    R = Poly(2);
    R[0] = 1, R[1] = vec[l];
    return R;
  }
  int md = l + r >> 1;
  return conquer(l, md, vec) * conquer(md + 1, r, vec);
}

inline int binom(int x, int y){ return 1ll * fac[x] * ifac[y] % INF * ifac[x - y] % INF;}

inline void dfs(int u, int p){
  siz[u] = 1;
  vector<int> vec;
  for(int i = 0; i < tree[u].size(); ++i){
    int v = tree[u][i];
    if(v == p)
      continue;
    dfs(v, u);
    (g[u] += g[v]) %= INF;
    siz[u] += siz[v];
    vec.PB(siz[v]);
  }

  P[u] = conquer(0, vec.size() - 1, vec);
  for(int i = 0; i < min((int)P[u].size(), k + 1); ++i)
    (f[u] += 1ll * P[u][i] * binom(k, i) % INF * fac[i] % INF) %= INF;
  (g[u] += f[u]) %= INF;
  return;
}

inline void calc1(int u, int p, int sum){
  (ans += 1ll * sum * f[u] % INF) %= INF;

  for(int i = 0; i < tree[u].size(); ++i){
    int v = tree[u][i];
    if(v == p)
      continue;
    calc1(v, u, (((sum + g[u]) % INF + INF - g[v]) % INF + INF - f[u]) % INF);
  }

  return;
}

inline bool cmp(const int &u, const int &v){ return siz[u] < siz[v]; }

inline void calc2(int u, int p){
  sort(tree[u].begin(), tree[u].end(), cmp);
  int lst = -1, sum = 0; Poly Q;
  for(int it = 0; it < tree[u].size(); ++it){
    int v = tree[u][it];
    if(v == p)
      continue;
    if(siz[v] != lst){
      Q = P[u];
      for(int i = Q.size() - 1; i >= 0; --i)
	(Q[i] += 1ll * Q[i - 1] * (n - siz[u]) % INF) %= INF;
      Q[0] = 1;
      for(int i = 1; i < Q.size(); ++i)
	(Q[i] += INF - 1ll * Q[i - 1] * siz[v] % INF) %= INF;
      sum = 0;
      for(int i = 0; i < min((int)Q.size(), k + 1); ++i)
	(sum += 1ll * Q[i] * binom(k, i) % INF * fac[i] % INF) %= INF;
      lst = siz[v];
    }
    (ans += 1ll * g[v] * sum % INF) %= INF;
  }
  
  for(int it = 0; it < tree[u].size(); ++it){
    int v = tree[u][it];
    if(v == p)
      continue;
    calc2(v, u);
  }
  return;
}

int main(){
  //freopen("981H.in", "r", stdin);
  scanf("%d%d", &n, &k);

  if(k == 1){
    printf("%lld\n", (1ll * n * (n - 1) / 2) % INF);
    return 0;
  }
  
  fac[0] = 1; for(int i = 1; i < maxn; ++i) fac[i] = 1ll * fac[i - 1] * i % INF;
  ifac[maxn - 1] = qpow(fac[maxn - 1], INF - 2); for(int i = maxn - 2; i >= 0; --i) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % INF;
  
  for(int i = 1; i < n; ++i){
    int u, v; scanf("%d%d", &u, &v); --u, --v;
    tree[u].PB(v), tree[v].PB(u);
  }
  
  dfs(0, -1);
  
  calc1(0, -1, 0);
  ans = 1ll * ans * ((INF + 1) / 2) % INF;
  calc2(0, -1);

  printf("%d\n", ans);
  return 0;
}