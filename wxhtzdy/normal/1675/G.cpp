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

const int N=251;
int n,m,a[N],dp[2*N][N],pref[2][2*N][N];

int main() {
	scanf("%d%d",&n,&m);
	rep(i,1,n+1) scanf("%d",a+i);
	reverse(a+1,a+n+1);
	dp[m][0]=0;
	rep(i,0,2) rep(j,0,2*m+1) rep(x,0,m+1) pref[i][j][x]=1e7;
	rep(i,0,m+1) pref[0][m][i]=0;
	rep(i,1,n+1) {
		int cur=(i%2);
		int prv=1-cur;
		rep(x,0,2*m+1) rep(y,0,m+1) pref[cur][x][y]=1e7,dp[x][y]=1e7;
		rep(b,0,2*m+1) rep(db,-m,m+1) {
			int nb=b+db,na=a[i]+db;
			if (nb<0||nb>2*m||na<0||na>m) continue;
			dp[nb][na]=min(dp[nb][na],pref[prv][b][na]+abs(nb-m));
			pref[cur][nb][na]=min(pref[cur][nb][na],dp[nb][na]);
		}
		rep(b,0,2*m+1) rep(x,1,m+1) pref[cur][b][x]=min(pref[cur][b][x],pref[cur][b][x-1]);
	}
	int ans=1e9;
	rep(i,0,m+1) ans=min(ans,dp[m][i]);
	printf("%d",ans);
}