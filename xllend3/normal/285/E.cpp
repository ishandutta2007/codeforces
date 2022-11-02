/*
Date: 2014/11/18 18:13:59 Tuesday
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

const int N=1111,M=111111;
int l,m,n,t,C;
ll f[N][N][2][2],g[N],jc[N],inv[N];
void add(ll &x,ll y){x=(x+y)%mod;}
int main()
{
	//ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("CF285E.in","r",stdin);//freopen("CF285E.out","w",stdout);
#endif
	scanf("%d%d",&n,&m);
	jc[0]=inv[0]=1;rep(i,1,n)jc[i]=jc[i-1]*i%mod,inv[i]=powmod(jc[i],mod-2);
	f[0][0][0][1]=1;
	rep(i,1,n)rep(j,0,i)rep(k,0,1){
		if(i==n)add(f[i][j][k][0],f[i-1][j][0][k]+f[i-1][j][1][k]);
		else add(f[i][j][k][1],f[i-1][j][0][k]+f[i-1][j][1][k]);
		add(f[i][j][k][0],f[i-1][j-1][1][k]);
		if(j&&i!=n)add(f[i][j][k][0],f[i-1][j-1][0][k]);
		if(j&&i!=n)add(f[i][j][k][1],f[i-1][j-1][1][k]);
	}rep(i,0,n)rep(j,0,1)rep(k,0,1)add(g[i],f[n][i][j][k]);
	rep(i,0,n)g[i]=g[i]*jc[n-i]%mod;
	//rep(i,0,n)rep(j,0,i)rep(k,0,1)rep(p,0,1)printf("%d %d %d %d %d\n",i,j,k,p,f[i][j][k][p]);
	//rep(i,0,n)printf("%d %d\n",i,g[i]);
	dep(i,n,0)rep(j,i+1,n)g[i]=(g[i]-g[j]*jc[j]%mod*inv[i]%mod*inv[j-i]%mod)%mod;
	printf("%d\n",(g[m]+mod)%mod);
	return 0;
}