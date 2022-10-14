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

const int N=40500;
int n,_;
ll b[N],ans[N];
void solve() {
	scanf("%d",&n);
	rep(i,0,n) scanf("%lld",b+i);
	ll s=0;
	rep(i,0,n) s+=b[i];
	ll m=n*(n+1)/2;
	if (s%m!=0) {
		puts("NO");
		return;
	}
	s/=m;
	rep(i,0,n) {
		int j=(i-1+n)%n;
		ll d=b[i]-b[j];
		if ((s-d)%n!=0) {
			puts("NO");
			return;
		}
		ans[i]=(s-d)/n;
		if (ans[i]<1) {
			puts("NO");
			return;
		}
	}
	s=ans[0];
	ll tot=ans[0];
	int suc=1;
	rep(i,1,n) s+=ans[i]*(ll)(n-i+1),tot+=ans[i];
	if (b[0]!=s) {
		suc=0;
	}
	rep(i,1,n) {
		s-=ans[i]*(n-1);
		s+=tot-ans[i];
		if (s!=b[i]) suc=0;
	}
	if (!suc) {
		puts("NO");
		return;
	}
	puts("YES");
	rep(i,0,n) printf("%lld ",ans[i]); puts("");
}
int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}