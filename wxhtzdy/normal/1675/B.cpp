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
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=35;
int n,a[N],dp[N][N],_;
VI vec[N];

void solve() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",&a[i]);
	rep(i,0,n+1) vec[i].clear();
	rep(i,1,n+1) {
		int x=a[i];
		while (x>0) {
			vec[i].pb(x);
			x/=2;
		}
		vec[i].pb(x);
	}
	vec[0].pb(-1);
	dp[0][0]=0;
	rep(i,1,n+1) {
		rep(x,0,SZ(vec[i])) {
			dp[i][x]=100005;
			rep(y,0,SZ(vec[i-1])) {
				if (vec[i][x]>vec[i-1][y]) {
					dp[i][x]=min(dp[i][x],dp[i-1][y]+x);
				}
			}
		}
	}
	int ans=10005;
	rep(i,0,vec[n].size()) ans=min(ans,dp[n][i]);
	printf("%i\n",(ans==10005?-1:ans));
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}