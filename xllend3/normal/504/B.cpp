/*
Date: 2015/01/12 16:52:42 Monday
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

const int N=222222,M=2111111;
int l,m,n,t,C;
int a[N],b[N];
struct zcc{
    int v;
}T[M];
void creat(int x,int l,int r){
    if(l==r){T[x].v=1;return;}int mid=l+r>>1;
    creat(x<<1,l,mid);creat((x<<1)+1,mid+1,r);T[x].v=T[x<<1].v+T[(x<<1)+1].v;
}
int que(int x,int l,int r,int v){
    if(l==r)return l;int mid=l+r>>1;
    if(T[x<<1].v>=v)return que(x<<1,l,mid,v);else return que((x<<1)+1,mid+1,r,v-T[x<<1].v);
}
void modi(int x,int l,int r,int v){
    T[x].v--;if(l==r)return;int mid=l+r>>1;
    if(v<=mid)modi(x<<1,l,mid,v);else modi((x<<1)+1,mid+1,r,v);
}
int Pa[N],Pb[N];
void modi(int *P,int x,int k){for(int i=x;i<=n;i+=i&-i)P[i]+=k;}
int que(int *P,int x){int ans=0;for(int i=x;i;i-=i&-i)ans+=P[i];return ans;}
int main(){
    //ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("B.in","r",stdin);//freopen("B.out","w",stdout);
#endif
    scanf("%d",&n);
    rep(i,1,n)scanf("%d",&a[i]);rep(i,1,n)scanf("%d",&b[i]);
    rep(i,1,n){
        modi(Pa,a[i]+1,1);a[i]-=que(Pa,a[i]);
        modi(Pb,b[i]+1,1);b[i]-=que(Pb,b[i]);
    }
    rep(i,1,n)a[i]+=b[i];
    dep(i,n,1)if(a[i]>=n-i+1)a[i]-=n-i+1,a[i-1]++;
    creat(1,0,n-1);
    rep(i,1,n){
        a[i]=que(1,0,n-1,a[i]+1);modi(1,0,n-1,a[i]);
    }
    rep(i,1,n)printf("%d%c",a[i],i==n?'\n':' ');
    return 0;
}