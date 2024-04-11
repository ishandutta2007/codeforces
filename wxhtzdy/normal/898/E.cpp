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

const int N=201000;
int n;
ll a[N];
bool is_square(int n) {
	int x=sqrt(n);
	return x*x==n;
}
int main() {
	vector<ll> v; v.pb(-1e18);
	rep(i,0,500000) v.pb((ll)i*i);
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%lld",a+i);
	int cnt=0;
	rep(i,1,n+1) if (is_square(a[i])) cnt++;
	if (cnt==n/2) {
		puts("0");
		return 0;
	}
	if (cnt<n/2) {
		vector<ll> mn;
		rep(i,1,n+1) {
			auto it=lower_bound(all(v),a[i]);
			mn.pb(min(*it-a[i],a[i]-*prev(it)));
		}
		sort(all(mn));
		ll ans=0;
		rep(i,0,n/2) ans+=mn[i];
		printf("%lld",ans);
	} else {
		vector<ll> mn;
		rep(i,1,n+1) {
			if (a[i]<=2) mn.pb(2-a[i]);
			else mn.pb(is_square(a[i])?1:0);
		}
		sort(all(mn));
		ll ans=0;
		rep(i,0,n/2) ans+=mn[i];
		printf("%lld",ans);
	}
}