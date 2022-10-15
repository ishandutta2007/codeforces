// Author: wlzhouzhuan
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fir first
#define sec second
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define mset(s, t) memset(s, t, sizeof(s))
#define mcpy(s, t) memcpy(s, t, sizeof(t))
#define SZ(x) (int(x.size()))
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }
int read() {
  int x = 0, f = 0; char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template<typename T> void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
  print(x), putchar(let);
}

const int N = 500005;
const int mod = 998244353;
int sa[N], rk[N], n, k;

int fac[N], ifac[N];
int qpow(int a, int b = mod - 2) {
  int res = 1;
  while (b) {
    if (b & 1) res = 1ll * res * a % mod;
    a = 1ll * a * a % mod, b >>= 1;
  }
  return res;
}
void init(int n) {
  fac[0] = 1;
  rep(i, 1, n) fac[i] = 1ll * fac[i - 1] * i % mod;
  ifac[n] = qpow(fac[n]);
  per(i, n, 1) ifac[i - 1] = 1ll * ifac[i] * i % mod;
}
inline int C(int n, int m) {
  if (n < m || m < 0) return 0;
  return 1ll * fac[n] * ifac[n - m] % mod * ifac[m] % mod;
}

int main() {
  init(N - 5);
  n = read(), k = read();
  rep(i, 1, n) {
    sa[i] = read() + 1, rk[sa[i]] = i;
  }
  int cnt = 0;
  rep(i, 1, n - 1) {
    if (rk[sa[i] + 1] > rk[sa[i + 1] + 1]) {
      cnt++;
    }
  }
  int ans = 0;
  rep(i, 0, cnt) {
    int coef = 1ll * C(cnt, i) * C(n + k - i - 1, n - i) % mod;
    if (i & 1) ans = (ans - coef + mod) % mod;
    else ans = (ans + coef) % mod; 
  }
  printf("%d\n", ans);
  return 0; 
}
/*
#define N 111
map<vector<int>,int>Map;
int a[N],id[N],p[N];
int n,k;

void dfs(int u){
  if(u==n+1){
    rep(i,1,n)id[i]=i;
    auto make=[&](int x){
      string t="";
      for(int i=x;i<=n;i++)t+=char(a[i]+'A');
      return t;
    };
    sort(id+1,id+n+1,[&](int x,int y){
      return make(x)<make(y);
    });
    vector<int>kk;
    for(int i=1;i<=n;i++)kk.pb(id[i]);
    Map[kk]++;
    return;
  }
  for(int i=1;i<=k;i++){
    a[u]=i;
    dfs(u+1);
  }
}
int main() {
  n=read(),k=read();
  dfs(1);
  for(auto v:Map){
    printf("[");
    for(int i=0;i<n;i++)p[v.fir[i]-1]=i;
    for(int i=0;i<n;i++)printf("%d ",v.fir[i]-1);
    printf("] = %d\n",v.sec); 
  }
}
*/

// n=4: 1,5,15,35,70 -> C(k,4)
// n=5: 1,6,21,56,126  -> C(k,5)
// n=6: 1,7,28,84 -> C(k,6)