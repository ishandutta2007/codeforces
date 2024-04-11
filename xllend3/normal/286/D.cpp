/*
Date: 2014/11/25 10:32:50 Tuesday
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
const int inf=0x3fffffff;
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

const int N=411111,M=111111;
int l,m,n,t,C,tot;
int v[N],ls[N],f[N],ti[N];
struct zcc{int l,r,t;}a[N],b[N];
inline bool cmpl(const zcc &a,const zcc &b){return a.l<b.l;}
inline bool cmpt(const zcc &a,const zcc &b){return a.t<b.t;}
int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}
int main(){
    //ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("CF286D.in","r",stdin);freopen("CF286D.out","w",stdout);
#endif
    scanf("%d%d",&m,&n);
    rep(i,1,n)scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].t),ls[++tot]=a[i].l,ls[++tot]=a[i].r;
    rep(i,1,m)scanf("%d",&v[i]);
    sort(ls+1,ls+1+tot);tot=unique(ls+1,ls+1+tot)-ls-1;
    rep(i,1,n)a[i].l=lower_bound(ls+1,ls+1+tot,a[i].l)-ls,a[i].r=lower_bound(ls+1,ls+1+tot,a[i].r)-ls;
    rep(i,1,2*n)f[i]=i;sort(a+1,a+1+n,cmpt);
    rep(i,1,n){
        for(int j=getf(a[i].l);j<a[i].r;j=getf(j))f[j]=j+1,ti[j]=a[i].t+1;
    }n=tot;tot=0;
    rep(i,1,n-1)if(ti[i]){
        a[++tot].l=ti[i]-1-ls[i+1];a[tot].r=1;
        a[++tot].l=ti[i]-1-ls[i];a[tot].r=-1;
    }
    sort(a+1,a+1+tot,cmpl);a[tot+1].l=a[tot+1].r=inf;
    //rep(i,1,tot+1)printf("%d %d\n",a[i].l,a[i].r);
    int pt=1,li=-inf,cnt=0;
    ll ans=0;
    rep(i,1,m){
        while(a[pt].l<=v[i]){
            ans+=(a[pt].l-li)*cnt;cnt+=a[pt].r;
            li=a[pt].l;++pt;
        }
        printf("%I64d\n",ans+(v[i]-li)*cnt);
    }
    return 0;
}