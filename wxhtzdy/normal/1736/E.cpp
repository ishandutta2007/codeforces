#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef basic_string<int> BI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}());
const ll mod=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=505;
const ll inf=1e9;
int n,a[N],id[N];
ll dp[2][N][N],pref[N][N]; // dp(pos,# of swaps)

int main() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",a+i);
	rep(i,0,n+1) rep(j,0,n+1) dp[0][i][j]=-inf;
	dp[0][0][0]=0;
	rep(i,1,n+1) {
		rep(j,0,n+1) rep(k,0,n+1) dp[i&1][j][k]=-inf;
		rep(j,0,n+1) rep(k,0,n+1) pref[j][k]=-inf;
		rep(j,0,n+1) rep(k,0,n+1) pref[j][k]=dp[(i-1)&1][j][k];
		rep(j,0,n+1) rep(k,1,n+1) pref[j][k]=max(pref[j][k],pref[j][k-1]);
		rep(j,0,n+1) rep(k,0,n+1) {
			if (j+1<=i) dp[i&1][j+1][k]=max(dp[i&1][j+1][k],dp[(i-1)&1][j][k]+a[k]);
		}
		rep(j,0,i+1) rep(k,i,n+1) {
			int ops=k-i;
			if (j<ops) continue;
			dp[i&1][j][k]=max(dp[i&1][j][k],pref[j-ops][k-1]+a[k]);
		}
	}
	ll ans=0;
	rep(i,0,n+1) rep(j,0,n+1) ans=max(ans,dp[n&1][i][j]);
	printf("%lld",ans);
}