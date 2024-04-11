#pragma GCC optimize("Ofast")
#pragma GCC target ("sse4")

#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<cassert>
#include<complex>
#include<numeric>
#include<array>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
constexpr ll mod = 998244353;
const ll INF = mod * mod;
typedef pair<int, int>P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define all(v) (v).begin(),(v).end()
typedef pair<ll, ll> LP;
typedef double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-12;
const ld pi = acosl(-1.0);

ll mod_pow(ll x, ll n, ll m = mod) {
	ll res = 1;
	while (n) {
		if (n & 1)res = res * x % m;
		x = x * x % m; n >>= 1;
	}
	return res;
}
struct modint {
	ll n;
	modint() :n(0) { ; }
	modint(ll m) :n(m) {
		if (n >= mod)n %= mod;
		else if (n < 0)n = (n % mod + mod) % mod;
	}
	operator int() { return n; }
};
bool operator==(modint a, modint b) { return a.n == b.n; }
modint operator+=(modint& a, modint b) { a.n += b.n; if (a.n >= mod)a.n -= mod; return a; }
modint operator-=(modint& a, modint b) { a.n -= b.n; if (a.n < 0)a.n += mod; return a; }
modint operator*=(modint& a, modint b) { a.n = ((ll)a.n * b.n) % mod; return a; }
modint operator+(modint a, modint b) { return a += b; }
modint operator-(modint a, modint b) { return a -= b; }
modint operator*(modint a, modint b) { return a *= b; }
modint operator^(modint a, ll n) {
	if (n == 0)return modint(1);
	modint res = (a * a) ^ (n / 2);
	if (n % 2)res = res * a;
	return res;
}

ll inv(ll a, ll p) {
	return (a == 1 ? 1 : (1 - p * inv(p % a, a)) / a + p);
}
modint operator/(modint a, modint b) { return a * modint(inv(b, mod)); }

const int max_n = 1 << 18;
modint fact[max_n], factinv[max_n];
void init_f() {
	fact[0] = modint(1);
	for (int i = 0; i < max_n - 1; i++) {
		fact[i + 1] = fact[i] * modint(i + 1);
	}
	factinv[max_n - 1] = modint(1) / fact[max_n - 1];
	for (int i = max_n - 2; i >= 0; i--) {
		factinv[i] = factinv[i + 1] * modint(i + 1);
	}
}
modint comb(int a, int b) {
	if (a < 0 || b < 0 || a < b)return 0;
	return fact[a] * factinv[b] * factinv[a - b];
}
modint combP(int a, int b) {
	if (a < 0 || b < 0 || a < b)return 0;
	return fact[a] * factinv[a - b];
}

void ans(int a, int b) {
	if (a > b)swap(a, b);
	cout << a + 1 << " " << b + 1 << "\n";
	return;
}


const int x = 100;
bool used[1 << 18];
void solve() {
	int n; cin >> n;
	vector<vector<int>> v(n);
	vector<int> vs;
	rep(i, n) {
		int k; cin >> k;
		v[i].resize(k);
		rep(j, k) {
			cin >> v[i][j];
			vs.push_back(v[i][j]);
		}
	}
	sort(all(vs));
	vs.erase(unique(all(vs)), vs.end());
	rep(i, n)used[i] = false;
	rep(i, vs.size())used[i] = false;
	rep(i, n)rep(j, v[i].size()) {
		v[i][j] = lower_bound(all(vs), v[i][j]) - vs.begin();
	}
	auto comp = [&](int i, int j)->bool {return v[i].size() < v[j].size(); };
	vector<int> ids(n);
	rep(i, n)ids[i] = i;
	sort(all(ids), comp);
	rep(i, ids.size()) {
		int id = ids[i];
		if (v[id].size() >= x) {
			for (int val : v[id])used[val] = true;
			rep(j, i) {
				int cnt = 0;
				for (int val : v[ids[j]]) {
					if (used[val])cnt++;
				}
				if (cnt >= 2) {
					ans(id, ids[j]); return;
				}
			}
			for (int val : v[id])used[val] = false;
		}
	}


	vector<vector<int>> w(vs.size());
	rep(i, n)for (int val : v[i]) {
		w[val].push_back(i);
	}
	auto comp2 = [&](int i, int j)->bool {return w[i].size() < w[j].size(); };
	ids.clear();
	ids.resize(vs.size());
	rep(j, vs.size())ids[j] = j;
	sort(all(ids), comp2);
	rep(i, ids.size()) {
		int id = ids[i];
		if (w[id].size() >= x) {
			for (int loc : w[id])used[loc] = true;
			rep(j, i) {
				int tmp = 0;
				int pre = -1;
				int to = ids[j];
				for (int loc : w[to])if (used[loc]) {
					tmp++;
					if (tmp == 2) {
						ans(pre, loc); return;
					}
					pre = loc;
				}
			}
			for (int loc : w[id])used[loc] = false;
		}
	}
	//cout << "hello "<<used[1]<<"\n";
	rep(i, n) {
		if (v[i].size() >= x)continue;
		rep(j, v[i].size()) {
			int val = v[i][j];
			if (w[val].size() >= x)continue;
			for (int loc : w[val])used[loc] = true;
			//cout << "hogeee " << used[1] << "\n";
			Rep(k, j + 1, v[i].size()){
				int tval = v[i][k];
				if (w[tval].size() >= x)continue;
				for (int loc : w[tval])if (used[loc] && loc != i) {
					//cout << "? " << loc<<" "<<val << " " << tval << "\n";
					ans(loc, i); return;
				}
			}
			for (int loc : w[val])used[loc] = false;
		}
	}
	cout << -1 << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(15);
	//init_f();
	//init();
	//expr();
	int t; cin >> t; rep(i, t)
	solve();
	return 0;
}