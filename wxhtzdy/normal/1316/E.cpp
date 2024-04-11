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

const int N=101000;
int n,p,k,o[N],a[N],s[N][7];
ll dp[N][1<<8];

int main() {
	scanf("%d%d%d",&n,&p,&k);
	rep(i,0,n) scanf("%d",a+i),o[i]=i;
	rep(i,0,n) rep(j,0,p) scanf("%d",&s[i][j]);
	sort(o,o+n,[&](int i,int j) {
		return a[i]>a[j];
	});
	memset(dp,0xc0,sizeof(dp));
	dp[0][0]=0;	
 	rep(i,0,n) rep(j,0,1<<p) {
 		dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
 		if (k>i-__builtin_popcount(j)) dp[i+1][j]=max(dp[i+1][j],dp[i][j]+a[o[i]]);
 		rep(x,0,p) if (!(j&(1<<x)))
 			dp[i+1][j|(1<<x)]=max(dp[i+1][j|(1<<x)],dp[i][j]+s[o[i]][x]);
 	}
	printf("%lld",dp[n][(1<<p)-1]);
}