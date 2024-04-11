#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Vi = vector<int>;
using Pii = pair<int,int>;
#define pb push_back
#define x first
#define y second
#define rep(i,b,e) for(int i=(b); i<(e); i++)
#define each(a,x) for(auto& a : (x))
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

#define tem template<class t,class u,class...w>
#define pri(x,y)tem auto operator<<(t& o, u a)->decltype(x,o) { o << y; return o; }
pri(a.print(),"{";a.print();o<<"}");
pri(a.y,"("<<a.x<<", "<<a.y<<")");
pri(all(a),"[";auto d="";for(auto i : a)(o << d << i, d=", "); o << "]");
void DD(...){}
tem void DD(t s, u a, w... k) {
	int b = 44;
	while (*s && *s != b) {
		b += (*s == 40 ? 50 : *s == 41 ? -50 : 0);
		cerr << *s++;
	}
	cerr << ": " << a << *s++; DD(s, k...);
}
tem vector<t> span(const t* a, u n) { return {a, a+n}; }
#ifdef LOC
#define deb(...) (DD("#, "#__VA_ARGS__, __LINE__, __VA_ARGS__), cerr << endl)
#else
#define deb(...)
#endif
#define DBP(...) void print() { DD(#__VA_ARGS__, __VA_ARGS__); }

constexpr int MOD = 1e9+7;
constexpr int MAX_W = 1<<17;

vector<vector<Pii>> G;
vector<Pii> par;
Vi depth;
vector<vector<ll>> options;

ll modInv(ll a, ll m) {
	if (a == 1) return 1;
	return ((a - modInv(m%a, a))*m + 1) / a;
}

void dfs(int v) {
	each(e, G[v]) {
		if (par[e.x].y == -1) {
			par[e.x] = {v, e.y};
			depth[e.x] = depth[v]+1;
			dfs(e.x);
		} else if (depth[e.x] > depth[v]+1) {
			options.emplace_back(MAX_W);
			auto& out = options.back();
			out[e.y]++;
			for (int u = e.x; u != v; u = par[u].x) {
				out[par[u].y]++;
			}
		}
	}
}

template<bool inv, bool doMod>
void fwht(vector<ll>& a) {
	for (int n = sz(a), step = 1; step < n; step *= 2) {
		for (int i = 0; i < n; i += 2*step) {
			rep(j, i, i+step) {
				ll &u = a[j], &v = a[j+step];
				tie(u, v) = pair<ll, ll>(u+v, u-v);
				if (doMod) {
					u %= MOD;
					v %= MOD;
				}
			}
		}
	}
	if (inv) {
		if (doMod) {
			ll mult = modInv(sz(a), MOD);
			each(x, a) x = x*mult % MOD;
		} else {
			each(x, a) x /= sz(a);
		}
	}
}

void convMod(vector<ll>& a, vector<ll>& b) {
	rep(i, 0, sz(a)) a[i] = a[i]*b[i] % MOD;
}

void convOnes(vector<ll>& a, vector<ll>& b) {
	each(x, a) x = (x != 0);
	fwht<0, 0>(a);
	rep(i, 0, sz(a)) a[i] = a[i]*b[i] % MOD;
	fwht<1, 0>(a);
}

void printUsed(vector<ll>& vec) {
	rep(i, 0, sz(vec)) {
		if (vec[i]) cout << i << ' ';
	}
	cout << '\n';
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(18);

	int n, m; cin >> n >> m;
	int full = 0;
	G.resize(n);

	rep(i, 0, m) {
		int u, v, w; cin >> u >> v >> w;
		u--; v--;
		G[u].pb({v, w});
		G[v].pb({u, w});
		full ^= w;
	}

	if (m == n-1) {
		cout << full << '\n';
		return 0;
	}

	par.resize(n, {-1,-1});
	depth.resize(n);
	par[0].y = 0;
	dfs(0);

	vector<ll> ones = options[0], kek = options[0];
	fwht<0, 1>(kek);

	rep(i, 1, sz(options)) {
		fwht<0, 0>(options[i]);
		convOnes(ones, options[i]);
		convMod(kek, options[i]);
	}

	each(x, ones) x = (x != 0);
	fwht<1, 1>(kek);
	ll bestCost = INT64_MAX, ways = 0;

	rep(i, 0, sz(ones)) {
		if (!ones[i]) continue;
		if ((i^full) < bestCost) {
			bestCost = i^full;
			ways = kek[i];
		}
	}

	ways %= MOD;
	if (ways < 0) ways += MOD;
	cout << bestCost << ' ' << ways << '\n';
}