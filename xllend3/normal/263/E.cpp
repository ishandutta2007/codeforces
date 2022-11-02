/*
Date: 2014/10/10 07:34:55 Friday
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
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
//*******************************************

const int N=1111,M=111111;
int l,m,n,t,C,k,x;
pii ans;
ll s[N][N],s1[N][N],s2[N][N];
int main()
{
	scanf("%d%d%d",&m,&n,&k);
	rep(i,1,m)rep(j,1,n)scanf("%d",&x),s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+x;
	rep(i,1,m)rep(j,1,n)s1[i][j]=s1[i-1][j-1]+s[i][j]-(i-k>=1&&j-k>=1?s[i-k][j-k]:0);
	rep(i,1,m)rep(j,0,n)s2[i][j]=s2[i-1][j+1]+s[i][j]-(i-k>=1&&j+k<=n?s[i-k][j+k]:0);
	ll Max=-(1ll<<60);
	rep(i,k,m-k+1)rep(j,k,n-k+1){
		ll sum=s2[i+k-1][j]+s2[i-1][j-k]-s1[i+k-1][j-1]-s1[i-1][j+k-1];
		if(sum>Max)Max=sum,ans=mp(i,j);
		//printf("%d %d %d\n",i,j,sum);
	}
	//rep(i,1,m){rep(j,1,n)printf("%d ",s[i][j]);puts("");}puts("");
	//rep(i,1,m){rep(j,1,n)printf("%d ",s1[i][j]);puts("");}puts("");
	//rep(i,1,m){rep(j,1,n)printf("%d ",s2[i][j]);puts("");}puts("");
	printf("%d %d\n",ans.X,ans.Y);
	return 0;
}