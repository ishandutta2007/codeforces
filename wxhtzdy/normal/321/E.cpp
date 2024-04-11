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

const int N=4010;
int n,k,a[N][N];
ll b[N][N],s[N][N],dp[N][N];

bool is(char c) { return c>='0'&&c<='9'; }
int read() {
	char c;
	while (!is(c=getchar()));
	return c-'0';
}

void gao(int l,int r,int pl,int pr,int x) {
	if (l>r) return;
	int md=(l+r)>>1;
	ll bst=1e18;
	int opt=0;
	rep(j,pl,min(md,pr)+1) {
		if (dp[j-1][x-1]+s[j][md]<bst) bst=dp[j-1][x-1]+s[j][md],opt=j;
	}
	dp[md][x]=bst;
	gao(l,md-1,pl,opt,x);
	gao(md+1,r,opt,pr,x);
}

int main() {
	scanf("%d%d",&n,&k);
	rep(i,1,n+1) rep(j,1,n+1) a[i][j]=read();
	rep(i,1,n+1) per(j,1,i+1) b[i][j]=b[i][j+1]+a[i][j];
	rep(i,1,n+1) rep(j,i,n+1) s[i][j]=s[i][j-1]+b[j][i];
	rep(i,1,n+1) dp[i][0]=1e17;
	rep(i,1,k+1) gao(1,n,1,n,i);
	printf("%lld\n",dp[n][k]);
}