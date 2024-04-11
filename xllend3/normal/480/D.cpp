/*
Date: 2014/10/19 16:55:32 Sunday
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
int l,m,n,t,C,f[N][N],DP[N][N];
struct zcc{int l,r,w,s,v;}a[N];
vector<int>vec[N];
int dfs(int x,int y,int dep){
	MIN(y,a[x].s);
	if(y<0)return 0;
	if(f[x][y])return f[x][y];
	int *dp=DP[dep];
	rep(i,max(a[x].l-1,0),a[x].r)dp[i]=0;
	rep(_,a[x].l,a[x].r){
		if(_!=a[x].l)MAX(dp[_],dp[_-1]);
		rep(i,0,SZ(vec[_])-1)if(vec[_][i]!=x&&a[vec[_][i]].r<=a[x].r)
			MAX(dp[a[vec[_][i]].r],dp[a[vec[_][i]].l]+dfs(vec[_][i],y-a[vec[_][i]].w,dep+1));
	}
	return f[x][y]=dp[a[x].r]+a[x].v;
}
inline bool cmp(const int &x,const int &y){return a[x].l<a[y].l;}
int main()
{
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%d%d%d%d%d",&a[i].l,&a[i].r,&a[i].w,&a[i].s,&a[i].v);
	rep(i,1,n)vec[a[i].l].pb(i);
	a[0].l=0;a[0].r=2*n;a[0].s=m;a[0].v=0;
	printf("%d\n",dfs(0,m,0));
	//rep(i,0,n)rep(j,0,m)printf("%d %d %d\n",i,j,f[i][j]);
	//rep(i,1,n){printf("%d:",i);rep(j,0,SZ(vec[i])-1)printf("%d ",vec[i][j]);puts("");}
	return 0;
}