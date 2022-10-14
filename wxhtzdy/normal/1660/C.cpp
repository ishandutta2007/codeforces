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

const int N=200050;
char s[N];
int _,dp[N][2];

void solve() {
	scanf("%s",s);
	int n=strlen(s);
	rep(i,0,26) dp[i][0]=dp[i][1]=-1e9;
	rep(i,0,n) {
		int c=(int)(s[i]-'a');
		int tmp=dp[c][0];
		rep(j,0,26) dp[c][0]=max(dp[c][0],dp[j][1]+1);
		dp[c][0]=max(dp[c][0],1);
		dp[c][1]=max(dp[c][1],tmp+1);
	}
	int ans=n;
	rep(i,0,26) ans=min(ans,n-dp[i][1]);
	printf("%d\n",ans);
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}