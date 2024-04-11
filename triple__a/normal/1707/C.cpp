// #pragma comment(linker, "/STACK:102400000,102400000")
#pragma GCC optimize("O3")
#pragma GCC optimize("O2")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize("trapv")
#include<bits/stdc++.h>
// #include <bits/extc++.h>
#define int long long
// #define double long double
// #define i128 long long
// #define double long double
using namespace std;
 
#define rep(i,n) for (int i=0;i<(int)(n);++i)
#define rep1(i,n) for (int i=1;i<=(int)(n);++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second
 
typedef long long ll;
typedef unsigned long long ull;
// typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 


int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
const int mod=998244353;
const double EPS=1e-9;
// const double pi=acos(-1);
const int INF=1e18;
const int N=500007;
const int M=1000007;
mt19937 rng(1234);
typedef bitset<1000> bs1;
typedef bitset<3000> bs2;
using S=pii;
using F=int;

int n,q;
int par[N];
int fnd(int u){
  if (par[u]==u) return u;
  return par[u]=fnd(par[u]);
}

void unite(int u,int v){
  int pu=fnd(u), pv=fnd(v);
  par[pu]=pv;
}

vi g[N];
int dfn[N],fend[N],f[N][20],m,dep[N];
int C[N],cnt;

int lowbit(int u){return u&-u;}
void update(int u,int w){
  for (int i=u;i<=n+10;i+=lowbit(i)) C[i]+=w;
}
int query(int u){
  int ans=0;
  for (int i=u;i;i-=lowbit(i)) ans+=C[i];
  return ans;
}
void dfs(int u,int v){
  f[u][0]=v;
  ++cnt, dfn[u]=cnt;
  for (auto c:g[u]){
    if (c==v) continue;
    dep[c]=dep[u]+1;
    dfs(c,u);
  }
  fend[u]=cnt;
}
int lca(int u,int v){
  if (dep[u]<dep[v]) swap(u,v);
  int diff=dep[u]-dep[v]-1;
  for (int i=17;i>-1;--i){
    if (diff>>i&1) u=f[u][i];
  }
  if (f[u][0]==v) return u;
  u=f[u][0];
  for (int i=17;i>-1;--i){
    if (f[u][i]!=f[v][i]) u=f[u][i], v=f[v][i];
  } 
  assert(u!=v);
  assert(f[u][0]==f[v][0]);
  return u;
}
signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cout.precision(15);
  cin>>n>>m;
  rep1(i,n) par[i]=i;
  vector<pii> left;
  rep(i,m){
    int u,v;
    cin>>u>>v;
    if (fnd(u)==fnd(v)) left.pb({u,v});
    else unite(u,v), g[u].pb(v), g[v].pb(u); 
  }
  dfs(1,-1);
  // rep1(i,n) cout<<dfn[i]<<" "<<fend[i]<<endl;
  rep(_,17) rep1(i,n) f[i][_+1]=f[f[i][_]][_];
  int ans=0;
  for (auto [u,v]:left){
    int aaa=lca(u,v);
    if (f[aaa][0]!=u) swap(u,v);
    // cerr<<u<<" "<<v<<" "<<aaa<<endl;
    // cerr<<u<<" "<<v<<" "<<dfn[u]<<" "<<dfn[v]<<" "<<fend[u]<<" "<<fend[v]<<endl;
    update(dfn[v],1), update(fend[v]+1,-1), ans++;
    if (f[aaa][0]!=u) update(dfn[u],1), update(fend[u]+1,-1);
    else update(dfn[aaa],-1), update(fend[aaa]+1,1), ans--;
  }
  // cout<<ans<<endl;
  for (int i=1;i<=n;++i){
    // cout<<i<<" "<<query(dfn[i])<<endl;
    if (query(dfn[i])==ans) cout<<1;
    else cout<<0;
  }
  return 0;
}
/*
5 3
1 2
1 3
4 5
1 4
1 5
2 3

01100
10000
10000
00001
00010

00101
00100
11000
00001
10010
*/