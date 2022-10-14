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
typedef long long ll;
typedef vector<ll> VI;
typedef basic_string<int> BI;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}());
const ll mod=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

ll n,m;
int _;

void solve() {
	scanf("%lld%lld",&n,&m);
	vector<vector<VI>> dp(2, vector<VI>(2, VI(2)));
	dp[0][0][0]=1;
	rep(b,0,62) {
		vector<vector<VI>> new_dp(2, vector<VI>(2, VI(2)));
		int nb=(n>>b&1),mb=(m>>b&1);
		rep(p,0,2) rep(c,0,2) rep(sl,0,2) rep(f,0,2) {
			int np=(nb+p+c)%2;
			int nc=(f+nb+c>1?1:0);
			int nsl=(f<mb||(sl&(f==mb)));
			new_dp[np][nc][nsl]+=dp[p][c][sl];
		}
		swap(dp,new_dp);
	}
	printf("%lld\n",dp[1][0][1]);
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}