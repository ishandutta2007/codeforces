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
const ll mod=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=300050;
int _,n,h[N];

bool check(ll x,ll d) {
	ll one=(d+1)/2,two=d/2;
	rep(i,0,n) if ((x-h[i])&1) one--;
	if (one<0) return false;
	two+=one/2;
	rep(i,0,n) two-=(x-h[i])/2;
	return two>=0;
}

ll solve(ll x) {
	ll l=0,r=1e18,ans;
	while (l<=r) {
		ll m=l+r>>1;
		if (check(x,m)) ans=m,r=m-1; else l=m+1;
	}
	return ans;
}

int main() {
	for (scanf("%d",&_);_;_--) {
		scanf("%d",&n);
		int mx=0;
		rep(i,0,n) scanf("%d",&h[i]),mx=max(mx,h[i]);
		printf("%lld\n",min(solve(mx),solve(mx+1)));
	}
	return 0;
}