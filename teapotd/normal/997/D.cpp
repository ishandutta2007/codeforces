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

constexpr ll MOD = 998244353;

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

	Zp& operator+=(Zp r) {
		*this = *this + r;
		return *this;
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

struct Vert {
	Vi edges;
	unordered_map<int, Zp> dyn[40];
};

int n1, n2, k;
vector<Vert> V1, V2;

void loadTree(vector<Vert>& V, int n) {
	V.resize(n);
	rep(i, 1, n) {
		int a, b; cin >> a >> b;
		a--; b--;
		V[a].edges.pb(b);
		V[b].edges.pb(a);
	}
}

void compute(vector<Vert>& V) {
	each(vert, V) {
		each(e, vert.edges) vert.dyn[0][e] = 1;
		vert.dyn[0][-1] = 1;
	}

	rep(len, 1, k+1) rep(id, 0, sz(V)) {
		auto& vert = V[id];

		rep(part, 0, len) {
			Zp tail = 0;
			each(e, vert.edges) tail += V[e].dyn[len-part-1][id];

			vert.dyn[len][-1] += vert.dyn[part][-1] * tail;
			each(e, vert.edges) vert.dyn[len][e] += vert.dyn[part][e] * (tail - V[e].dyn[len-part-1][id]);
		}
	}
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	cin >> n1 >> n2 >> k;
	loadTree(V1, n1);
	loadTree(V2, n2);

	if (k % 2) {
		cout << "0\n";
		return 0;
	}

	k /= 2;
	compute(V1);
	compute(V2);

	Zp newton = 1;
	Zp ret = 0;

	rep(m, 0, k+1) {
		Zp t1 = 0, t2 = 0;
		each(vert, V1) t1 += vert.dyn[m][-1];
		each(vert, V2) t2 += vert.dyn[k-m][-1];

		ret += newton * t1 * t2;
		newton = newton / ((2*m+1) * (2*m+2)) * (2*k-2*m) * (2*k-2*m-1);
	}

	cout << ret.x << endl;
	return 0;
}