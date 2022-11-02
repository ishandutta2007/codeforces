/*
Date: 2015/05/13 12:04:25 Wednesday
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

const int N=1111111,M=5000;
int l,t;
ll p,m,n,f[M+9][M+9],v[N],jc[N],dc[N];
vector<ll>g0,g1;
int main(){
	//ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("christmas.in","r",stdin);//freopen("christmas.out","w",stdout);
#endif
	scanf("%lld%lld%lld",&n,&m,&p);
	rep(i,1,n)scanf("%lld",&v[i]);
	f[1][1]=1;
	jc[0]=1;rep(i,1,m)jc[i]=jc[i-1]*i%p;
	dc[0]=1;rep(i,1,m)dc[i]=dc[i-1]*(m-i+1)%p;
	rep(i,2,M)rep(j,1,M)f[i][j]=(f[i-1][j-1]+f[i-1][j]*(j-1))%p;
	g0.pb(1);
	rep(i,1,n){
		g1.clear();
		rep(j,0,v[i])g1.pb(f[v[i]][j]*g0[0]%p*dc[j]%p);
		rep(j,1,v[i])if(j<=v[i-1])g1[j]=((g1[j]-f[v[i]][j]*g0[j]%p*jc[j])%p+p)%p;
		rep(j,1,v[i])g1[0]=(g1[0]+g1[j])%p;
		g0=g1;
		//rep(j,0,v[i])printf("%d %d %lld\n",i,j,g[i][j]);
	}
	printf("%d\n",g1[0]);
	return 0;
}