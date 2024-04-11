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

const int N=500050;
const int md=1e9+7;
const ll inf=1e18;
int n,l[N],r[N];
VI qs[N];

struct info {
	ll s,ways;
}dp[N],f[N];
info comb(info a,info b) {
	info res;
	res.s=min(a.s,b.s);
	res.ways=0;
	if (res.s==a.s) res.ways+=a.ways;
	if (res.s==b.s) res.ways+=b.ways;
	res.ways%=md;
	return res;
}

void modify(int x,info v) {
	for (int i=x+1;i<N;i+=i&-i) f[i]=comb(f[i],v);
}
info query(int x) {
	info res={inf,0};
	for (int i=x+1;i>0;i-=i&-i) res=comb(res,f[i]);
	return res;
}

int main() {
	scanf("%d",&n);
	rep(i,0,n) scanf("%d%d",r+i,l+i);
	VI v(1,0);
	rep(i,0,n) {
		v.pb(l[i]);
		v.pb(r[i]);
	}
	sort(all(v));
	v.erase(unique(all(v)),v.end());
	rep(i,0,n) {
		l[i]=lower_bound(all(v),l[i])-v.begin();
		r[i]=lower_bound(all(v),r[i])-v.begin();
	}
	rep(i,0,N) f[i]={inf,0};
	modify(0,{0,1});
	rep(i,0,n) qs[r[i]].pb(i);
	rep(i,0,SZ(v)) {
		info f={inf,0};
		for (int j:qs[i]) {
			dp[j]=query(l[j]);
			dp[j].s+=v[l[j]];
			f=comb(f,dp[j]);
		}
		if (f.s!=inf) f.s-=v[i];
		modify(i,f);
	}
	int mx=0;
	rep(i,0,n) mx=max(mx,l[i]);
	info ans={inf,0};
	rep(i,0,n) if (r[i]>mx) ans=comb(ans,dp[i]);
	printf("%lld",ans.ways);
}