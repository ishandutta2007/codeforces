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
int n,k,a[N],cnt[N],L=1,R=0;
ll dp[N][25],tot=0;

void cepajl(int l) {
	while (L<l) {
		cnt[a[L]]--;
		tot-=cnt[a[L++]];
	}
	while (L>l) {
		tot+=cnt[a[--L]];
		cnt[a[L]]++;
	}
}
void cepajr(int r) {
	while (R<r) {
		tot+=cnt[a[++R]];
		cnt[a[R]]++;
	}
	while (R>r) {
		cnt[a[R]]--;
		tot-=cnt[a[R--]];
	}
}

void gao(int l,int r,int tl,int tr,int x) {
	if (l>r) return;
	int md=(l+r)>>1;
	int pos=0;
	ll bst=1e18;
	cepajr(md);
	per(i,tl,min(tr,md)+1) {
		cepajl(i);
		if (bst>tot+dp[i-1][x-1]) {
			bst=tot+dp[i-1][x-1];
			pos=i;
		}
	}
	dp[md][x]=bst;
	gao(l,md-1,tl,pos,x);
	gao(md+1,r,pos,tr,x);
}

int main() {
	scanf("%d%d",&n,&k);
	rep(i,1,n+1) scanf("%d",a+i);
	rep(i,1,n+1) dp[i][0]=1e17;
	rep(i,1,k+1) gao(1,n,1,n,i);
	printf("%lld",dp[n][k]);
	return 0;
}