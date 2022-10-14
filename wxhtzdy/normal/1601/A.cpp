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

const int N=2010000;
int _,n,cnt[55];
ll a[N];
void solve() {
	scanf("%d",&n);
	rep(i,0,n) scanf("%lld",a+i);
	rep(i,0,31) cnt[i]=0;
	rep(i,0,n) rep(j,0,30) if (a[i]&(1LL<<j)) cnt[j]++;
	VI ans;
	rep(i,1,n+1) {
		bool ok=true;
		rep(j,0,31) if (cnt[j]%i!=0) ok=false;
		if (ok) ans.pb(i);
	}
	for (int x:ans) printf("%d ",x);
	printf("\n");
}
int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}