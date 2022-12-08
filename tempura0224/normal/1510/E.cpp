#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

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
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;
const ld pi = acosl(-1.0);

ll mod_pow(ll x, ll n, ll m = mod) {
	if (n < 0) {
		ll res = mod_pow(x, -n, m);
		return mod_pow(res, m - 2, m);
	}
	if (abs(x) >= m)x %= m;
	if (x < 0)x += m;
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
modint operator/=(modint& a, modint b) { a = a / b; return a; }
const int max_n = 1 << 21;
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

struct bl {
	ld area, cx, cy;
};

bl merge(bl a, bl b) {
	if (a.area == 0)return b;
	else if (b.area == 0)return a;
	bl res;
	res.area = a.area + b.area;
	res.cx = (a.cx * a.area + b.cx * b.area) / (res.area);
	res.cy = (a.cy * a.area + b.cy * b.area) / (res.area);
	return res;
}

map<ll, vector<LP>> mp[21][401];
void solve() {
	int n; ld x, y; cin >> n; cin >> x >> y;
	int d = n / 2;
	if (n > 20)d = 20;
	int d2 = n - d;
	rep(j, (1 << d)) {
		int sum = 0;
		int c = 0;
		bool valid = true;
		bl res = { 0,0,0 };
		rep(i, d) {
			int nc = c;
			bl up,dow;
			if (j & (1 << i)) {
				nc++;
				up.area = 1;
				up.cx = i + 2.0/3.0;
				up.cy = c + 1.0/3.0;
			}
			else {
				nc--;
				up.area = 1;
				up.cx = i + 1.0 / 3.0;
				up.cy = nc + 1.0 / 3.0;
			}
			if (nc < 0) {
				valid = false; break;
			}
			dow.area = 2*min(c,nc);
			dow.cx = i + 0.5;
			dow.cy = min(c, nc) / 2.0;
			res = merge(res, merge(up, dow));
			sum += c + nc;
			c = nc;
		}
		if (!valid)continue;
		ll ex = res.cx * 10000000;
		ll ey = res.cy * 10000000;
		mp[c][sum][ex].push_back({ ey,j });
		//cout << "hello ";
		//cout << c << " " << sum << " " << ex << " " << ey << "\n";
		//v[c][sum].push_back({ LDP{res.cx,res.cy},j });
		//cout << "hello ";
		//cout << c << " " << sum << " " << res.cx << " " << res.cy << "\n";
	}
	rep(i, 21)rep(j, 401)for (auto &v : mp[i][j])sort(all(v.second));
	rep(j, (1 << d2)) {
		int sum = 0;
		int c = 0; bool valid = true;
		bl res = { 0,0,0 };
		rep(i, d2) {
			int nc = c;
			bl up, dow;
			if (j & (1 << i)) {
				nc++;
				up.area = 1;
				up.cx = n-i - 2.0 / 3.0;
				up.cy = c + 1.0 / 3.0;
			}
			else {
				nc--;
				up.area = 1;
				up.cx = n-i- 1.0 / 3.0;
				up.cy = nc + 1.0 / 3.0;
			}
			if (nc < 0) {
				valid = false; break;
			}
			dow.area = 2*min(c,nc);
			dow.cx = n-i - 0.5;
			dow.cy = min(c, nc) / 2.0;
			res = merge(res,merge(up, dow));
			sum += c + nc;
			c = nc;
		}
		if (!valid)continue;
		rep(i, 401)if (mp[c][i].size()) {
			ld nx = (x * (i+ sum) - res.cx * sum) / (ld)(i);
			ld ny = (y * (i + sum) - res.cy * sum) / (ld)(i);
			ll ex = nx * 10000000;
			ll ey = ny * 10000000;
			//cout << "goal " << c << " " << i << " " << sum << " " << ex << " " << ey << "\n";
			for (ll tx = ex - 1; tx <= ex + 1; tx++) {
				vector<LP>& v = mp[c][i][tx];
				int id = lower_bound(all(v), LP{ ey - 1,-1 }) - v.begin();
				if (id < v.size() && v[id].first <= ey + 1) {
					int cl = v[id].second;
					int cr = j;
					string ans;
					rep(k, d) {
						if (cl & (1 << k)) {
							ans.push_back('(');
						}
						else {
							ans.push_back(')');
						}
					}
					per(k, d2) {
						if (cr & (1 << k)) {
							ans.push_back(')');
						}
						else {
							ans.push_back('(');
						}
					}
					cout << ans << "\n"; return;
				}
			}
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init();
	//expr();

	//int t; cin >> t; rep(i, t)
		solve();
	return 0;
}