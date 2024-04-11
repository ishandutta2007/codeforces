/*
Date: 2014/11/26 09:24:19 Wednesday
Author: xllend3
*/
#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
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

const int N=111111,M=11111111;
int l,m,n,t,C,tot(1),ans;
int vh[N],di[N],b[N],pre[N],his[N],dis[N],v1[N];
struct zcc{int v,nxt,flw;}a[M];
int sap(int n){
    int u=1,now,aug=inf,flow=0;rep(i,1,n)di[i]=b[i];vh[0]=n;CLR(dis);
    while(dis[1]<n){
        for(now=di[u];now;now=a[now].nxt)if(a[now].flw&&dis[u]==dis[a[now].v]+1)break;
        di[u]=now;his[u]=aug;
        if(now){
            MIN(aug,a[now].flw);pre[u=a[now].v]=now;
            if(u==n){
                do{a[pre[u]].flw-=aug;a[pre[u]^1].flw+=aug;u=a[pre[u]^1].v;}while(u-1);
                flow+=aug;aug=inf;
            }
        }else{
            if(--vh[dis[u]]==0)break;dis[u]=n+1;
            for(now=b[u];now;now=a[now].nxt)if(a[now].flw)MIN(dis[u],dis[a[now].v]+1);di[u]=b[u];
            ++vh[dis[u]];if(u-1){u=a[pre[u]^1].v;aug=his[u];}
        }
    }return flow;
}
void add(int x,int y,int z){
    a[++tot].v=y;a[tot].nxt=b[x];a[tot].flw=z;b[x]=tot;
    a[++tot].v=x;a[tot].nxt=b[y];a[tot].flw=0;b[y]=tot;
}
int main(){
    //ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("CF311E.in","r",stdin);//freopen("CF311E.out","w",stdout);
#endif
    scanf("%d%d%d",&n,&m,&t);rep(i,1,n)scanf("%d",&v1[i]);
    rep(i,1,n){
        scanf("%d",&l);
        if(v1[i])add(1,i+1,l),add(i+1,1+m+n+1,0);
        else add(1,i+1,0),add(i+1,1+m+n+1,l);
    }
    rep(i,1,m){
        int a1,a2,a3,an;
        scanf("%d%d%d",&a1,&a2,&an);ans+=a2;
        rep(_,1,an){
            scanf("%d",&a3);
            if(a1)add(1+n+i,1+a3,inf);else add(1+a3,1+n+i,inf);
        }
        scanf("%d",&a3);
        if(a1)add(1,1+n+i,a2+a3*t);else add(1+n+i,1+m+n+1,a2+a3*t);
    }
    printf("%d\n",ans-sap(1+m+n+1));
    return 0;
}