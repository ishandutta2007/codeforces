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

#define y0 ahdusagdas

ll x0,y0,ax,ay,bx,by,xs,ys,t;

ll dist(ll x1,ll y1,ll x2,ll y2) {
	return abs(x1-x2)+abs(y1-y2);
}

int main() {
	scanf("%lld%lld%lld%lld%lld%lld",&x0,&y0,&ax,&ay,&bx,&by);
	scanf("%lld%lld%lld",&xs,&ys,&t);
	vector<pair<ll,ll>> p(1,mp(x0,y0));
	while (p.back().fi<=3e16&&p.back().second<=3e16) {
		p.pb(mp(p.back().fi*ax+bx,p.back().se*ay+by));
	}
	int k=SZ(p);
	int ans=0;
	rep(i,0,k) rep(j,i,k) {
		ll f=min(dist(xs,ys,p[i].fi,p[i].se),dist(xs,ys,p[j].fi,p[j].se));
		f+=dist(p[i].fi,p[i].se,p[j].fi,p[j].se);
		if (f<=t) ans=max(ans,j-i+1);
	}
	printf("%d\n",ans);
}