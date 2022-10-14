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

const int N=101000;
int _,n,m,a[N];
ll ps[N],dp[N][605];
ll get(int l,int r) {
	if (!l) return ps[r];
	return ps[r]-ps[l-1];
}
void solve() {
	scanf("%d",&n);
	m=min((int)sqrt(n*2)*3+5,600);
	rep(i,0,n) scanf("%d",a+i);
	ps[0]=a[0]; rep(i,1,n) ps[i]=ps[i-1]+a[i];
	rep(i,0,n+1) rep(j,1,m) dp[i][j]=-1;
	rep(i,0,n) dp[i][1]=a[i];
	per(i,0,n) per(j,1,m) {
		if (j==1) {
			dp[i][j]=max(dp[i+1][j],(ll)a[i]);
			continue;
		}
		int x=i+j-1;
		if (x>=n) continue;
		ll sum=get(i,x);
		dp[i][j]=dp[i+1][j];
		if (sum<dp[x+1][j-1]) dp[i][j]=max(dp[i][j],sum);
	}
	int ans=0;
	rep(j,1,m) if (dp[0][j]!=-1) ans=max(ans,j);
	printf("%d\n",+ans);
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}