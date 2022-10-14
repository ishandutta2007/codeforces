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
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

int _;
vector<ll> pws;

ll calc(VI a) {
	ll s=0;
	rep(i,0,SZ(pws)) s+=a[i]*pws[i];
	return s;
}

void solve() {
	ll n; scanf("%lld",&n);
	int sz=SZ(pws);
	VI a(sz+1);
	per(i,0,SZ(pws)) {
		int cnt=0;
		while (n>=pws[i]) {
			cnt++;
			n-=pws[i];
		}
		a[i]=cnt;
	}
	int lst=-1;
	rep(i,0,sz) if (a[i]==2) lst=i;
	if (lst==-1) {
		printf("%lld\n", calc(a));
		return;
	}
	rep(i,0,lst) a[i]=0;
	while (a[lst]==2) a[lst]=0,a[lst+1]++,lst++;
	printf("%lld\n", calc(a));
}

int main() {
	pws.pb(1);
	while (pws.back()<(ll)2e18) pws.pb(pws.back()*3);
	for (scanf("%d",&_);_;_--) {
		solve();
	}
	return 0;
}