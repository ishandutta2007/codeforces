#include <bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define rep(i,b,e)for(int i=(b);i<(e);i++)
#define repd(i,b,e)for(int i=(b);i>=(e);i--)
#define each(a,x)for(auto&a:(x))
#define all(x)(x).begin(),(x).end()
#define sz(x)int((x).size())
#define tem template<class t,class...g>
#define D DD()
#define pri(k)tem auto p(t a,ll)->decltype(a.k,z()){D
#define DBP(...)void print(){D.x("{"#__VA_ARGS__,__VA_ARGS__);D,"}";}
#ifdef LOC
#define deb(...)((D,"<",__LINE__,"> ").x(#__VA_ARGS__,__VA_ARGS__),D,"\n")
#else
#define deb(...)
#endif
using namespace std;using namespace rel_ops;using ll=long long;using Vi=vector<int>;
using Pii=pair<int,int>;struct DD{using z=void;z x(...){}tem z p(t a,...){cerr<<a;}
tem DD&operator,(t a){p(a,0);return*this;}pri(first),"(",a.first,", ",a.second,")";}
tem z x(const char*s,t a,g...k){while(*s&&*s!=',')D,*s++;D,": ",a,*s++;x(s,k...);}
pri(print());a.print();}pri(begin()),"[";each(k,a)D,k,", ";D,"]";}};

// ------------------------------------------------------------------------------------------ //

constexpr ll MOD = 1e9+7;
constexpr int MAX_LEN = 1000001;
constexpr int MAX_POW = 21;

ll modInv(ll a, ll m) { return (a == 1 ? 1 : ((a - modInv(m%a, a))*m + 1) / a); }

struct Zp {
	ll x;
	Zp(ll y = 0) : x(y % MOD) {}

	Zp operator+(Zp r) const { return x+r.x; }
	Zp operator-(Zp r) const { return x-r.x; }
	Zp operator*(Zp r) const { return x*r.x; }
	Zp operator/(Zp r) const { return x*modInv(r.x, MOD); }

	Zp inv() { return modInv(x, MOD); }

	Zp pow(ll e) {
		if (!e) return 1;
		Zp t = pow(e/2);
		return t*t * (e % 2 ? x : 1);
	}
};

// ---

Zp dyn[MAX_LEN][MAX_POW], neg[MAX_LEN];

void initDyn() {
	dyn[0][0] = 1;
	rep(i, 1, MAX_POW) dyn[0][1] = 0;
	rep(i, 1, MAX_LEN) rep(j, 0, MAX_POW) dyn[i][j] = (j > 0 ? dyn[i][j-1] : 0) + dyn[i-1][j];

	neg[1] = 1;
	rep(i, 2, MAX_LEN) neg[i] = neg[i-1]*2;
}

void run() {
	ll x, y; cin >> x >> y;
	Zp ret = 1;

	for (ll d = 2; d*d <= x; d++) {
		int times = 0;
		while ((x % d) == 0) {
			x /= d;
			times++;
		}

		ret = ret * dyn[y][times];
	}

	if (x > 1) ret = ret * dyn[y][1];

	ret = ret*neg[y];
	cout << ret.x << endl;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	initDyn();

	int q; cin >> q;
	while (q--) run();

	return 0;
}