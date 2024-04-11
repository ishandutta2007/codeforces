/*
Date: 2014/10/27 14:59:33 Monday
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
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<lf,lf> pff;
typedef complex<double> CD;
const int inf=0x20202020;
const int mod=1000000009;
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
int l,m,n,t,C,f[N][2][32][32][32];
inline void p(int &x,const int &y){x+=y;if(x>mod)x-=mod;}
int main()
{
	//ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("CF268D.in","r",stdin);//freopen("CF268D.out","w",stdout);
#endif
	scanf("%d%d",&n,&m);
	f[1][1][1][1][1]=4;
	rep(i,1,n-1)rep(u,0,1)rep(j,1,m)rep(k,1,m)rep(l,1,m)if(f[i][u][j][k][l]){
		//printf("%d %d %d %d %d %d\n",i,u,j,k,l,f[i][u][j][k][l]);
		int J=min(j+1,m),K=min(k+1,m),L=min(l+1,m);
		p(f[i+1][u][J][K][L],f[i][u][j][k][l]);
		p(f[i+1][j<m][K][L][u?1:m],f[i][u][j][k][l]);
		p(f[i+1][k<m][L][u?1:m][J],f[i][u][j][k][l]);
		p(f[i+1][l<m][u?1:m][J][K],f[i][u][j][k][l]);
	}
	int ans=0;
	rep(u,0,1)rep(j,1,m)rep(k,1,m)rep(l,1,m)if(j<m||k<m||l<m||u)p(ans,f[n][u][j][k][l]);
	printf("%d\n",ans);
	return 0;
}