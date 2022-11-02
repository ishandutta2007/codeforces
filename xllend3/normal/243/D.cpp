/*
Date: 2015/01/04 08:17:16 Sunday
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
const int inf=0x7fffffff;
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

const int N=1111111,M=11111111;
int l,m,n,t,C,X,Y;
struct zcc{int x,y,l,v;
}a[N];
struct Node{int lc,rc,v;
}T[M];int tot,root;
inline bool cmp(const zcc &a,const zcc &b){return a.l<b.l;}
int que(int x,int l,int r,int L,int R){
    if(!x)return 0;if(l==L&&r==R)return T[x].v;int mid=l+r>>1;
    int ans=inf;if(L<=mid)MIN(ans,que(T[x].lc,l,mid,L,min(R,mid)));
    if(R>mid)MIN(ans,que(T[x].rc,mid+1,r,max(mid+1,L),R));return max(ans,T[x].v);
}
void modi(int &x,int l,int r,int L,int R,int v){
    if(!x)x=++tot;if(l==L&&r==R){MAX(T[x].v,v);return;}int mid=l+r>>1;
    if(L<=mid)modi(T[x].lc,l,mid,L,min(R,mid),v);if(R>mid)modi(T[x].rc,mid+1,r,max(mid+1,L),R,v);
    MAX(T[x].v,min(T[T[x].lc].v,T[T[x].rc].v));
}
int main(){
    //ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("CF243D.in","r",stdin);freopen("CF243D.out","w",stdout);
#endif
    scanf("%d%d%d",&n,&X,&Y);
    rep(i,1,n)rep(j,1,n)scanf("%d",&a[(i-1)*n+j].v);
    rep(i,1,n)rep(j,1,n){
        int p=(i-1)*n+j;a[p].x=inf;a[p].y=-inf;a[p].l=inf;
        rep(I,i,i+1)rep(J,j,j+1)MIN(a[p].l,I*X+J*Y),MAX(a[p].y,J*X-I*Y-1),MIN(a[p].x,J*X-I*Y);
    }m=n*n;sort(a+1,a+1+m,cmp);
    //rep(i,1,m)printf("%d %d %d %d\n",a[i].x,a[i].y,a[i].l,a[i].v);
    ll ans=0;
    rep(i,1,m){
        int tmp=que(root,-inf,inf,a[i].x,a[i].y);
        //printf("%d %d %d\n",i,tmp,a[i].v);
        if(tmp<a[i].v){
            ans+=a[i].v-tmp;
            modi(root,-inf,inf,a[i].x,a[i].y,a[i].v);
        }
    }printf("%I64d\n",ans);
    return 0;
}