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

template<int MOD, int RT> struct mint {
	static const int mod = MOD;
	static constexpr mint rt() { return RT; } // primitive root for FFT
	int v; explicit operator int() const { return v; } // explicit -> don't silently convert to int
	mint():v(0) {}
	mint(ll _v) { v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);
		if (v < 0) v += MOD; }
	bool operator==(const mint& o) const {
		return v == o.v; }
	friend bool operator!=(const mint& a, const mint& b) {
		return !(a == b); }
	friend bool operator<(const mint& a, const mint& b) {
		return a.v < b.v; }

	mint& operator+=(const mint& o) {
		if ((v += o.v) >= MOD) v -= MOD;
		return *this; }
	mint& operator-=(const mint& o) {
		if ((v -= o.v) < 0) v += MOD;
		return *this; }
	mint& operator*=(const mint& o) {
		v = int((ll)v*o.v%MOD); return *this; }
	mint& operator/=(const mint& o) { return (*this) *= inv(o); }
	friend mint pow(mint a, ll p) {
		mint ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans; }
	friend mint inv(const mint& a) { assert(a.v != 0);
		return pow(a,MOD-2); }

	mint operator-() const { return mint(-v); }
	mint& operator++() { return *this += 1; }
	mint& operator--() { return *this -= 1; }
	friend mint operator+(mint a, const mint& b) { return a += b; }
	friend mint operator-(mint a, const mint& b) { return a -= b; }
	friend mint operator*(mint a, const mint& b) { return a *= b; }
	friend mint operator/(mint a, const mint& b) { return a /= b; }
};

const int MOD=998244353;
using mi = mint<MOD,5>; // 5 is primitive root for both common mods

namespace simp {
	vector<mi> fac,ifac,invn;
	void check(int x) {
		if (fac.empty()) {
			fac={mi(1),mi(1)};
			ifac={mi(1),mi(1)};
			invn={mi(0),mi(1)};
		}
		while (SZ(fac)<=x) {
			int n=SZ(fac),m=SZ(fac)*2;
			fac.resize(m);
			ifac.resize(m);
			invn.resize(m);
			for (int i=n;i<m;i++) {
				fac[i]=fac[i-1]*mi(i);
				invn[i]=mi(MOD-MOD/i)*invn[MOD%i];
				ifac[i]=ifac[i-1]*invn[i];
			}
		}
	}
	mi gfac(int x) {
		check(x); return fac[x];
	}
	mi ginv(int x) {
		check(x); return invn[x];
	}
	mi gifac(int x) {
		check(x); return ifac[x];
	}
	mi binom(int n,int m) {
		if (m < 0 || m > n) return mi(0);
		return gfac(n)*gifac(m)*gifac(n - m);
	}
}

const int N=200050;
const int M=20;
int d,n,m,l[N],p[M];
mi dp[1<<M],pref[M][N];

mi get(int i,int l,int r) {
	return l==0?pref[i][r]:pref[i][r]/pref[i][l-1];
}

int main() {
	scanf("%d%d%d",&d,&n,&m);
	rep(i,0,n) scanf("%d",l+i);
	rep(i,0,m) scanf("%d",p+i);
	sort(l,l+n);
	sort(p,p+m);
	rep(i,0,m) {
		pref[i][0]=abs(p[i]-l[0]);
		rep(j,1,n) pref[i][j]=pref[i][j-1]*abs(p[i]-l[j]);
	}
	rep(mask,1,1<<m) {
		VI v;
		rep(i,0,m) if (mask>>i&1) v.pb(i);
		dp[mask]=1;
		rep(i,0,SZ(v)) {
			int x=p[v[i]],xl=(i==0?-1e9:p[v[i-1]]),xr=(i==SZ(v)-1?1e9:p[v[i+1]]);
			int l=0,r=n-1,ql=-1,qr=-1;
			while (l<=r) {
				int mid=l+r>>1;
				if (abs(x-::l[mid])<=abs(xl-::l[mid])) ql=mid,r=mid-1;
				else l=mid+1;
			}
			l=0,r=n-1;
			while (l<=r) {
				int mid=l+r>>1;
				if (abs(x-::l[mid])<abs(xr-::l[mid])) qr=mid,l=mid+1;
				else r=mid-1;
			}
			if (abs(xl-::l[ql])<abs(x-::l[ql])||abs(xr-::l[ql])<=abs(x-::l[ql])) continue;
			//printf("!! %d %d %d\n",v[i],ql,qr);
			dp[mask]*=get(v[i],ql,qr);
		}
		if (__builtin_popcount(mask)&1) dp[mask]*=-1;
	}
//	rep(i,0,1<<m) printf("- %d\n",dp[i]); puts("");
	rep(i,0,m) rep(j,0,1<<m) if (!(j>>i&1)) dp[j]+=dp[j^(1<<i)];
	rep(j,0,1<<m) if (__builtin_popcount(j)&1) dp[j]*=-1;
//	rep(i,0,1<<m) printf("- %d\n",dp[i]); puts("");
	rep(i,0,m) rep(j,0,1<<m) if (j>>i&1) dp[j]+=dp[j^(1<<i)];
	int q;
	scanf("%d",&q);
	while (q--) {
		int x;
		scanf("%d",&x);
		vector<PII> dd;
		rep(i,0,m) dd.pb(mp(abs(x-p[i]),i));
		sort(all(dd)); reverse(all(dd));
		mi res=pow((mi)d+1,n+1);
		int mask=(1<<m)-1;
		rep(i,0,m) {
			int id=dd[i].second;
			res-=(dp[mask]-dp[mask^(1<<id)])*dd[i].first;
			mask^=(1<<id);
		}
		printf("%d\n",res);
	}
}