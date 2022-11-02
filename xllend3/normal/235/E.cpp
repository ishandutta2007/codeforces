/*
Date: 2014/10/08 08:12:01 Wednesday
Author: xllend3
*/
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
#define X first
#define Y second
#define mp make_pair
#define ph push
#define pb push_back
#define rep(i,a,n) for(int _tmp=n,i=a;i<=_tmp;++i)
#define dep(i,a,n) for(int _tmp=n,i=a;i>=_tmp;--i)
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
using namespace std;
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
int gcd(int a,int b) { return b?gcd(b,a%b):a;}
//*******************************************

const int N=2222,M=111111;
int l,m,n,t,C,mu[N],a,b,c,f[N][N];
typedef unsigned int u32;
u32 count(int x,int y){
    if(f[x][y])return f[x][y];
    u32 ans=0;rep(i,1,x)if(gcd(i,y)==1)ans+=x/i;return f[x][y]=ans;
}
int main()
{
    //ios::sync_with_stdio(false);
    //freopen("CF235E.in","r",stdin);//freopen("CF235E.out","w",stdout);
    scanf("%d%d%d",&a,&b,&c);
    mu[1]=1;rep(i,1,2000)rep(j,2,2000){if(i*j>2000)break;mu[i*j]-=mu[i];}
    u32 ans=0;
    rep(i,1,a)rep(x,1,min(b,c))if(gcd(i,x)==1)ans+=mu[x]*(a/i)*count(b/x,i)*count(c/x,i);
    printf("%u\n",ans%(1<<30));
    return 0;
}