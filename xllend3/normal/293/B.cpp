/*
Date: 2014/10/10 08:26:19 Friday
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

const int N=11,M=111111;
int l,m,n,t,C;
int a[N][N],inv[N],jc[N],b[N][N],vis[N][N],clo[N];
ll ans;
void check(int mx){
	//rep(i,1,m){rep(j,1,n)printf("%d ",b[i][j]);puts("");}
	CLR(clo);int cnt1=0;
	rep(i,1,m)rep(j,1,n)clo[a[i][j]]=b[i][j];
	rep(i,1,m)rep(j,1,n)if(a[i][j]&&clo[a[i][j]]!=b[i][j])return;
	rep(i,1,t)if(clo[i])++cnt1;
	CLR(clo);
	rep(i,1,m)rep(j,1,n)if(a[i][j])clo[b[i][j]]=a[i][j]+1;
	rep(i,1,m)rep(j,1,n)if(a[i][j]&&clo[b[i][j]]!=a[i][j]+1)return;
	//puts("OK");
	ans=(ans+1ll*jc[t-cnt1]*inv[t-mx])%mod;
}
void dfs(int x,int y,int mx){
	if(y>n){dfs(x+1,1,mx);return;}
	if(x>m){check(mx);return;}
	int tmp=vis[x-1][y]|vis[x][y-1];
	rep(i,1,mx)if(!(tmp&(1<<i))){
		b[x][y]=i;vis[x][y]=tmp|(1<<i);dfs(x,y+1,mx);
	}if(mx<t&&!(tmp&(1<<mx+1))){
		b[x][y]=mx+1;vis[x][y]=tmp|(1<<mx+1);dfs(x,y+1,mx+1);
	}
}
int main()
{
	scanf("%d%d%d",&m,&n,&t);
	if(m+n-1>t){puts("0");return 0;}
	rep(i,1,m)rep(j,1,n)scanf("%d",&a[i][j]);
	jc[0]=1;rep(i,1,t)jc[i]=jc[i-1]*i;
	rep(i,0,t)inv[i]=powmod(jc[i],mod-2);
	dfs(1,1,0);
	printf("%lld\n",ans);
	return 0;
}