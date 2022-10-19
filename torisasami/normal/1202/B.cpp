#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<set>
#include<string>
using namespace std;
int gcd(int a, int b) {
	int c = a % b;
	while (c != 0) {
		a = b;
		b = c;
		c = a % b;
	}
	return b;
}
struct UnionFind {
	vector<int> par; // par[i]:i() par[3] = 2 : 32

	UnionFind(int N) : par(N) { //
		for (int i = 0; i < N; i++) par[i] = i;
	}

	int root(int x) { // xroot(x) = {x}
		if (par[x] == x) return x;
		return par[x] = root(par[x]);
	}

	void unite(int x, int y) { // xy
		int rx = root(x); //xrx
		int ry = root(y); //yry
		if (rx == ry) return; //xy(=)
		par[rx] = ry; //xy(=)xrxyry
	}

	bool same(int x, int y) { // 2x, ytrue
		int rx = root(x);
		int ry = root(y);
		return rx == ry;
	}
};
typedef long long ll;

ll M = 1000000007;

vector<ll> fac(300001); //n!(mod M)
vector<ll> ifac(300001); //k!^{M-2} (mod M)

ll mpow(ll x, ll n) {
	ll ans = 1;
	while (n != 0) {
		if (n & 1) ans = ans * x % M;
		x = x * x % M;
		n = n >> 1;
	}
	return ans;
}
void setcomb() {
	fac[0] = 1;
	ifac[0] = 1;
	for (ll i = 0; i < 1000000; i++) {
		fac[i + 1] = fac[i] * (i + 1) % M; // n!(mod M)
	}
	ifac[1000000] = mpow(fac[1000000], M - 2);
	for (ll i = 1000000; i > 0; i--) {
		ifac[i - 1] = ifac[i] * i%M;
	}
}
ll comb(ll a, ll b) {
	if (a == 0 && b == 0)return 1;
	if (a < b || a < 0)return 0;
	ll tmp = ifac[a - b] * ifac[b] % M;
	return tmp * fac[a] % M;
}
ll perm(ll a, ll b) {
	if (a == 0 && b == 0)return 1;
	if (a < b || a < 0)return 0;
	return fac[a] * ifac[a - b] % M;
}
// mod. m  a  a^{-1} 
long long modinv(long long a) {
	long long b = M, u = 1, v = 0;
	while (b) {
		long long t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= M;
	if (u < 0) u += M;
	return u;
}
vector<vector<ll>> mul(vector<vector<ll>> a, vector<vector<ll>> b, int n) {
	int i, j, k, t;
	vector<vector<ll>> c(n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			t = 0;
			for (k = 0; k < n; k++)
				t = (t + a[i][k] * b[k][j] % M) % M;
			c[i].push_back(t);
		}
	}
	return c;
}

template< typename Monoid >
struct SegmentTree {

	int sz;
	vector< Monoid > seg;

	const Monoid M1;

	SegmentTree(int n, const Monoid &M1) : M1(M1) {
		sz = 1;
		while (sz < n) sz <<= 1;
		seg.assign(2 * sz, M1);
	}

	void set(int k, const Monoid &x) {
		seg[k + sz] = x;
	}

	void build() {
		for (int k = sz - 1; k > 0; k--) {
			seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
		}
	}

	void update(int k, const Monoid &x) {
		k += sz;
		seg[k] = x;
		while (k >>= 1) {
			seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
		}
	}

	Monoid query(int a, int b) {
		Monoid L = M1, R = M1;
		for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
			if (a & 1) L = f(L, seg[a++]);
			if (b & 1) R = f(seg[--b], R);
		}
		return f(L, R);
	}

	Monoid value(const int &k) const {
		return seg[k + sz];
	}

	Monoid f(Monoid a, Monoid b) {
		return a + b;
	}
};

int main() {
	ll	i, j, k, l, p[11][11],z[11][11], n, c[11], ans;
	char s[2222222];
	cin >> s;
	for (i = 0; i < 10; i++)
		for (j = 0; j < 10; j++)
			z[i][j] = 0;
	for (i = 1; s[i] != '\0'; i++)
		z[s[i - 1] - '0'][s[i] - '0']++;
	priority_queue<pair<int, int>> q;
	for (k = 0; k < 10; k++) {
		for (l = 0; l < 10; l++) {
			for (i = 0; i < 10; i++)
				for (j = 0; j < 10; j++)
					p[i][j] = -1;
			for (i = 0; i < 10; i++) {
				for (n = 0; n < 10; n++)
					c[n] = 0;
				q.push(make_pair(0, i));
				c[i]--;
				while (!q.empty()) {
					ll a = q.top().second, b = -q.top().first;
					q.pop();
					if (c[a] <= 0) {
						if (c[a] == 0)
							p[i][a] = b;
						int t;
						t = (a + k) % 10;
						if (c[t] <= 0) {
							q.push(make_pair(-(b + 1), t));
						}
						t = (a + l) % 10;
						if (c[t] <= 0) {
							q.push(make_pair(-(b + 1), t));
						}
						c[a]++;
					}
				}
			}
			ans = 0;
			for (i = 0; i < 10; i++) {
				if (ans == -1)
					break;
				for (j = 0; j < 10; j++) {
					if (z[i][j] > 0 && p[i][j] == -1) {
						ans = -1;
						break;
					}
					else
						ans += (p[i][j]-1) * z[i][j];
				}
			}
			cout << ans;
			if (l == 9)
				cout << endl;
			else
				cout << " ";
		}
	}
}