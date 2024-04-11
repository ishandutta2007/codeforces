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
#define _deb(...)(DD("#, "#__VA_ARGS__,__LINE__,__VA_ARGS__),cerr<<endl)
using ll=long long;pri(a.print)"{",a.print(),o<<"}";}using namespace std;void DD(...){}using Pii=pair<int
,int>;tem void DD(t s,u a,w...k){while(*s&&*s!=',')cerr<<*s++;cerr<<": "<<a<<*s++;DD(s,k...);}pri(all)"["
,[&](){for(auto i : a)o<<i<<", ";}(),o<<"]";}using  Vi=vector<int>;pri(get<1>) "("<<a.x<<", "<<a.y<<")";}
//-----------------------------------------------------------------------------------------------------//

constexpr int MOD = 998244353;

ll modInv(ll a, ll m) {
	if (a == 1) return 1;
	return ((a - modInv(m%a, a))*m + 1) / a;
}

ll umod(ll a, ll m) {
	a %= m; return (a >= 0 ? a : a+m);
}

struct Zp {
	ll x;
	Zp(ll y = 0) {
		x = (y < 0 || y >= MOD ? umod(y, MOD) : y);
	}

	Zp operator-()     const { return MOD-x; }
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

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);
	ll n; cin >> n;

	const Zp three = Zp(3), one = Zp(1), neg = Zp(-1);

	Zp ret = 0;
	Zp count = n;

	rep(i, 1, n+1) {
		Zp m = three.pow(n*(n-i))*three.pow(i);
		ret = ret + count * m * 2;
		count = count / (i+1) * (n-i) * neg;
	}

	count = 3*n;
	if (n % 2) count = count * neg;

	rep(a, 1, n+1) {
		Zp x3 = three.pow(n-a);
		Zp m = (one - x3).pow(n) - (-x3).pow(n);
		ret = ret + count * m;
		count = count / (a+1) * (n-a) * neg;
	}

	cout << ret.x << endl;
	return 0;
}