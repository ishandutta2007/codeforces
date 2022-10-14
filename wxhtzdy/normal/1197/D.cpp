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

const int N=300050;
int n,m,k,a[N];
ll dp[N][20][3];

int main() {
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,n+1) scanf("%d",a+i);
	rep(i,0,n+1) rep(j,0,m) rep(p,0,3) dp[i][j][p]=-1e18;
	dp[0][0][0]=0;
	rep(i,1,n+1) rep(j,0,m) {
		dp[i][j][0]=max(dp[i][j][0],dp[i-1][j][0]);
		dp[i][j][2]=max(dp[i][j][2],dp[i-1][j][2]);
		dp[i][j][2]=max(dp[i][j][2],dp[i-1][j][1]);
		dp[i][(j+1)%m][1]=max(dp[i][(j+1)%m][1],dp[i-1][j][1]+a[i]-(j==0?k:0));
		dp[i][(j+1)%m][1]=max(dp[i][(j+1)%m][1],dp[i-1][j][0]+a[i]-(j==0?k:0));
	}
	ll ans=0;
	rep(i,0,m) rep(j,0,3) ans=max(ans,dp[n][i][j]);
	printf("%lld",ans);
}