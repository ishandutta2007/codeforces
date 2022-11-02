/*
Date: 2014/12/30 12:12:44 Tuesday
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
int l,m,n,t,C;
pii E[N];
vector<int>a[N],b[N];
int vis1[N],vis2[N],res[N];
void dfs(int x,vector<int>*a,int *vis){
    if(vis[x])return;vis[x]=1;
    rep(i,0,SZ(a[x])-1)dfs(a[x][i],a,vis);
}
int main(){
    //ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("CF241E.in","r",stdin);//freopen("CF241E.out","w",stdout);
#endif
    scanf("%d%d",&n,&m);rep(i,1,m)scanf("%d%d",&E[i].X,&E[i].Y),a[E[i].X].pb(E[i].Y),b[E[i].Y].pb(E[i].X);
    dfs(1,a,vis1);dfs(n,b,vis2);
    rep(_,1,n+n)rep(i,1,m)if(vis1[E[i].X]&&vis2[E[i].Y])
        MIN(res[E[i].Y],res[E[i].X]+2),MIN(res[E[i].X],res[E[i].Y]-1);
    rep(i,1,m)if(vis1[E[i].X]&&vis2[E[i].Y])
        if(res[E[i].Y]-res[E[i].X]!=1&&res[E[i].Y]-res[E[i].X]!=2){puts("No");return 0;}
    puts("Yes");
    rep(i,1,m)printf("%d\n",min(max(res[E[i].Y]-res[E[i].X],1),2));
    return 0;
}