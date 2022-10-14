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

const int N=100050;
int n,a[N],f[N];
ll pref[N];

void modify(int x,int v) {
	for (int i=x;i<N;i+=i&-i) f[i]+=v;
}
int get(int x) {
	int s=0;
	for (int i=x;i>0;i-=i&-i) s+=f[i];
	return s;
}

int main() {
	scanf("%d",&n);
	rep(i,1,n+1) {
		scanf("%d",a+i);
		pref[i]=pref[i-1]+a[i];
	}
	bool ok=true;
	rep(i,1,n) {
		ok&=(pref[i]>=pref[0]&&pref[i]<=pref[n]);
	}
	if (!ok||pref[n]<pref[0]) {
		printf("-1");
		return 0;
	}
	vector<ll> v;
	rep(i,1,n) v.pb(pref[i]);
	sort(all(v));
	v.erase(unique(all(v)),v.end());
	ll ans=0;
	rep(i,1,n) {
		int idx=lower_bound(all(v),pref[i])-v.begin()+1;
		ans+=get(N-1)-get(idx);
		modify(idx,+1);
	}
	printf("%lld",ans);
}