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

const int N=200050,L=25;
int _,n,a[N],b[N],st[N][L],logs[N];

int query(int l,int r) {
	int k=logs[r-l+1];
	return min(st[l][k],st[r-(1<<k)+1][k]);
}

void solve() {
	scanf("%d",&n);
	rep(i,0,n) scanf("%d",a+i);
	rep(i,2,n+1) logs[i]=logs[i>>1]+1;
	rep(i,0,n) b[i]=a[i]-(i+1);
	rep(i,0,n) st[i][0]=b[i];
	rep(j,1,L) rep(i,0,n) if (i+(1<<j)<=n) st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	ll ans=0;
	rep(i,0,n) {
		int l=i,r=n-1,pp=i;
		while (l<=r) {
			int mid=l+r>>1;
			if (query(i,mid)+i>=0) pp=mid,l=mid+1;
			else r=mid-1;
		}
		ans+=(pp-i+1);
	}
	printf("%lld\n",ans);
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}