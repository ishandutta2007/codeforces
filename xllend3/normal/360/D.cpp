/*
Date: 2014/11/21 08:45:21 Friday
Author: xllend3
*/
/*
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<complex>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
#include<stack>
#include<map>
#include<set>
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

const int N=111111,M=111111;
int l,m,n,t,C,p,b,tot;
int a[N],c[N],d[N],f[N];
inline bool cmp(const int &a,const int &b){return a>b;}
int main()
{
    //ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("CF360D.in","r",stdin);//freopen("CF360D.out","w",stdout);
#endif
    scanf("%d%d%d",&n,&m,&p);b=p-1;
    rep(i,1,n)scanf("%d",&a[i]);rep(i,1,m)scanf("%d",&t),b=gcd(b,t);
    for(int i=1;i*i<=p-1;++i)if((p-1)%i==0){
        c[++tot]=i;if(i*i!=p-1)c[++tot]=(p-1)/i;
    }sort(c+1,c+1+tot);
    rep(i,1,n){a[i]=powmod(a[i],b,p);rep(j,1,tot)if(powmod(a[i],c[j],p)==1){d[i]=(p-1)/c[j];break;}}
    sort(d+1,d+1+n,cmp);n=unique(d+1,d+1+n)-d-1;
    int ans=0;
    rep(i,1,n){
        f[i]=(p-1)/d[i];rep(j,1,i-1)if(d[j]%d[i]==0)f[i]-=f[j];ans+=f[i];
    }printf("%d\n",ans);
    return 0;
}