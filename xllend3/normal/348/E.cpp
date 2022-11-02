/*
Date: 2014/12/30 13:04:51 Tuesday
Author: xllend3
*/
#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define mp make_pair
#define ph push
#define pb push_back
#define REP(i,a,n) for(int _tmp=n,i=a;i<=_tmp;++i)
#define DEP(i,a,n) for(int _tmp=n,i=a;i>=_tmp;--i)
#define rep(i,a,n) for(int i=(a);i<=(n);++i)
#define dep(i,a,n) for(int i=(a);i>=(n);--i)
#define ALL(x,S) for(__typeof((S).end()) x=S.begin();x!=S.end();x++)
#define eps 1e-8
#define pi 3.1415926535897
#define sqr(x) ((x)*(x))
#define MAX(a,b) a=max(a,b)
#define MIN(a,b) a=min(a,b)
#define SZ(x) ((int)(x).size())
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define CLR(a) memset(a,0,sizeof(a))
#define POSIN(x,y) (1<=(x)&&(x)<=n&&1<=(y)&&(y)<=m)
#define all(x) (x).begin(),(x).end()
#define COUT(S,x) cout<<fixed<<setprecision(x)<<S<<endl
typedef long long ll;
typedef double lf;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<lf,lf> pff;
typedef complex<double> CD;
const int inf=0x20202020;
const int mod=1000000007;
template<class T> inline void read(T&x){bool fu=0;char c;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x=-x;};
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z){read(x);read(y);read(z);}
template<class T> inline void read(T&x,T&y,T&z,T&q){read(x);read(y);read(z);read(q);}
const int DX[]={1,0,-1,0},DY[]={0,1,0,-1};
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
//*******************************************

const int N=111111,M=111111;
int l,m,n,t,C,x,y,z,tot;
int v[N],dis[N],fa[N],bz[N][22],dep[N],val[N],dfsx[N];
vector<pii>a[N];
int dfs(int x,int f){
    fa[x]=f;dep[x]=dep[f]+1;dfsx[++tot]=x;
    rep(i,0,SZ(a[x])-1)if(a[x][i].X!=f)dis[a[x][i].X]=dis[x]+a[x][i].Y,dfs(a[x][i].X,x);
}
int lca(int x,int y){
    if(dep[x]>dep[y])swap(x,y);
    dep(i,20,0)if(dep[bz[y][i]]>=dep[x])y=bz[y][i];
    if(x==y)return x;
    dep(i,20,0)if(bz[x][i]!=bz[y][i])x=bz[x][i],y=bz[y][i];
    return fa[x];
}
int main(){
    //ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("CF348E.in","r",stdin);freopen("CF348E.out","w",stdout);
#endif
    scanf("%d%d",&n,&m);rep(i,1,m)scanf("%d",&t),v[t]=1;
    rep(i,2,n)scanf("%d%d%d",&x,&y,&z),a[x].pb(mp(y,z)),a[y].pb(mp(x,z));
    CLR(dis);x=1;dfs(1,0);rep(i,1,n)if(v[i]&&dis[i]>dis[x])x=i;
    tot=0;CLR(dis);y=x;dfs(x,0);rep(i,1,n)if(v[i]&&dis[i]>dis[y])y=i;
    rep(i,1,n)bz[i][0]=fa[i];rep(j,1,20)rep(i,1,n)bz[i][j]=bz[bz[i][j-1]][j-1];
    rep(i,1,n)if(v[i]){
        int p=lca(i,y);
        if(dis[p]-dis[x]>dis[y]-dis[p])val[i]++;
        else if(dis[p]-dis[x]<dis[y]-dis[p])val[i]++,val[y]++,val[fa[p]]--,val[p]--;
        else val[i]++,val[fa[p]]--;
    }dep(_,n,1){
        int i=dfsx[_];
        val[fa[i]]+=val[i];
    }int ans=0,cnt=0;
    rep(i,1,n)if(!v[i])MAX(ans,val[i]);
    rep(i,1,n)if(!v[i]&&val[i]==ans)++cnt;
    printf("%d %d\n",ans,cnt);
    return 0;
}