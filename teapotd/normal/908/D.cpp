#include <bits/stdc++.h>
#ifdef LOC
#define deb _deb
#else
#define deb(...)
#endif
#define x  first
#define y second
#define mp make_pair
#define pb push_back
#define sz(x)int((x).size())
#define each(a,x)for(auto&a:(x))
#define all(x)(x).begin(),(x).end()
#define rep(i,b,e)for(int i=(b);i<(e);i++)
#define tem template<class t,class u,class...w>
#define DBP(...)void print(...){DD(#__VA_ARGS__,__VA_ARGS__);}
#define pri(y)tem auto operator<<(t&o,u a)->decltype(y(a),o){return o<<
#define _deb(...)(DD("#, "#__VA_ARGS__,__LINE__,__VA_ARGS__),cerr<<'\n')
using ll=long long;pri(a.print)"{",a.print(),o<<"}";}using namespace std;void DD(...){}using Pii=pair<int
,int>;tem void DD(t s,u a,w...k){while(*s&&*s!=',')cerr<<*s++;cerr<<": "<<a<<*s++;DD(s,k...);}pri(all)"["
,[&](){for(auto i : a)o<<i<<", ";}(),o<<"]";}using  Vi=vector<int>;pri(get<1>) "("<<a.x<<", "<<a.y<<")";}
//-----------------------------------------------------------------------------------------------------//

constexpr ll MOD = 1e9+7;

ll modInv(ll a, ll m) {
	return (a == 1 ? 1 :
		((a - modInv(m%a, a))*m + 1) / a);
}

ll umod(ll a, ll m) {
	a %= m; return (a >= 0 ? a : a+m);
}

struct Zp {
	ll x;
	Zp(ll y = 0) : x(umod(y, MOD)) {}

	Zp operator+(Zp r) const { return x+r.x; }
	Zp operator-(Zp r) const { return x-r.x; }
	Zp operator*(Zp r) const { return x*r.x; }
	Zp operator/(Zp r) const {
		return x*r.inv().x;
	}

	Zp inv() const { return modInv(x, MOD); }

	Zp pow(ll e) const {
		if (!e) return 1;
		Zp t = pow(e/2);
		return t*t * (e & 1 ? x : 1);
	}

	void print(...) { cerr << x; }
};

// ---

ll k;
Zp pa, pb;
Zp dyn[2001][2001];

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	cin >> k >> pa.x >> pb.x;
	pa = Zp(pa.x);
	pb = Zp(pb.x);

	Zp div = pa+pb;
	pa = pa/div;
	pb = pb/div;

	for (ll a = k*2; a >= 0; a--) {
		for (ll b = k*2; b >= 0; b--) {
			if (b >= k) {
				dyn[a][b] = b;
			} else if (a+b >= k) {
				dyn[a][b] = pb * (Zp(a+b)/(Zp(1)-pa) + pa/((Zp(1)-pa)*(Zp(1)-pa)));
			} else {
				dyn[a][b] = dyn[a+1][b]*pa + dyn[a][a+b]*pb;
			}
		}
	}

	rep(a, 0, k*2+1) rep(b, 0, k*2+1) deb(a, b, dyn[a][b]);
	cout << dyn[1][0].x << endl;
	return 0;
}