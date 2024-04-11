#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
const ll mod2=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=19;
int n,m,k,a[N],d[N][N];
ll dp[1<<N][N];

int main() {
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,n+1) scanf("%d",a+i);
	rep(i,0,k) {
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		d[x][y]=c;
	}
	rep(i,0,1<<n) rep(j,1,n+1) dp[i][j]=-(1LL<<59);
	rep(i,1,n+1) dp[1<<(i-1)][i]=a[i];
	rep(i,0,1<<n) rep(j,1,n+1) {
		if (!(i&(1<<(j-1)))) continue;
		rep(x,1,n+1) if (!(i&(1<<(x-1)))) dp[i^(1<<(x-1))][x]=max(dp[i^(1<<(x-1))][x],dp[i][j]+a[x]+d[j][x]);
	}
	ll ans=0;
	rep(i,0,1<<n) if (__builtin_popcount(i)==m) rep(j,1,n+1) ans=max(ans,dp[i][j]);
	printf("%lld",ans);
}