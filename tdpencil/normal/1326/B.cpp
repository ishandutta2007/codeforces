#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <iterator>
#pragma GCC optimize("Ofast") // optimizes doubles + vectors
//using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int MAXN = 1e6, M = 1e9+7;
const ull INF = 1e18;
// #define runcase LOL
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<ull> vul;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef vector<array<int, 2>> var2;
typedef vector<array<int, 3>> var3;
typedef pair<ll, ll> pl;
typedef vector<pl> vpl;

#define FOR(j, V) for(int j = 0; j < V; j++)
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define DOR(tt, X) for(int tt = X; tt >= 0; --tt)
#define pb push_back
#define all(X) X.begin(),X.end()
#define vt vector
#define sz(X) int(X.size())
#define ub upper_bound
#define lb lower_bound
// template insertion spaces


//template <typename T> using oset = tree<T, null_type, std::less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T>

struct polynomial_hash {
	int n;
	string s;
	T m, b; // prime mod, base
	vector<T> hash, inverse; // hash[i] : hash value of s[0, i - 1]

	polynomial_hash() {}

	polynomial_hash(const string &_s, T _m, T _b) {
		init(_s, _m, _b);
	}

	void init(const string &_s, T _m, T _b) {
		s = _s;
		n = (int) (s.size());
		m = _m;
		b = _b;
		hash.resize(n + 1);
		inverse.resize(n + 1);
		precompute();
	}

	T binpow(T x, T y) {
		T res = 1;
		while (y > 0) {
			if (y % 2 != 0) res = (res * x) % m;
			x = (x * x) % m;
			y /= 2;
		}

		return res;
	}

	// Builds the hash and inverse array
	void precompute() {
		T power = b;
		hash[0] = 0;
		for (int i = 1; i <= n; i++) {
			hash[i] = (hash[i - 1] + (s[i - 1] - 'a' + 1) * power) % m;
			power = (power * b) % m;
		}

		inverse[n] = binpow(binpow(b, n), m - 2);
		for (int i = n - 1; i > 0; i--)
			inverse[i] = (inverse[i + 1] * b) % m;
	}

	// Returns the hash value of substring s[l, r]
	T get_hash(int l, int r) {
		l++, r++;
		if (l == 1) return hash[r];
		return ((((hash[r] - hash[l - 1]) % m) + m) * inverse[l - 1]) % m;
	}
};
// int n, q;

const int MAX_LOG = 20, N = 1e5+5, MAX = 100;
ll n, x, y, z, v, g, i, j, t, m;


ull modmul(ull a, ull b, ull M) {
	ll ret = a * b - M * ull(1.L / M * a * b);
	return ret + M * (ret < 0) - M * (ret >= (ll)M);
}
ull modpow(ull b, ull e, ull mod) {
	ull ans = 1;
	for (; e; b = modmul(b, b, mod), e /= 2)
		if (e & 1) ans = modmul(ans, b, mod);
	return ans;
}
bool isPrime(ull n) {
	if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
	ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
		s = __builtin_ctzll(n-1), d = n >> s;
	for (ull a : A) {   // ^ count trailing zeroes
		ull p = modpow(a%n, d, n), i = s;
		while (p != 1 && p != n - 1 && a % n && i--)
			p = modmul(p, p, n);
		if (p != n-1 && i != s) return 0;
	}
	return 1;
}

template<class T>
struct RMQ {
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

ll seg[MAXN]; 
ll a[MAXN];

ll gcd(ll x, ll y) {
	return (!y)?x:gcd(y, x %y);
}
void build(int root, int t1, int t2) {
	if(t1==t2) {
		seg[root]=a[t1];
	} else {
		int mid=(t1+t2)/2;
		build(root * 2, t1, mid);
		build(root * 2 + 1, mid + 1, t2);
		seg[root]=gcd(seg[root*2], seg[root*2+1]);
	}
}


ll query(int l, int r, int root = 1, int t1 = 0, int t2 = n - 1) {
	if(l > t2 || r < t1)
		return 0;
	else if(l <= t1 && r >= t2)
		return seg[root];
	int mid=(t1+t2)/2;
	return gcd(query(l, r, 2 * root, t1, mid), query(l, r, 2 * root + 1, mid + 1, t2));
}
mt19937_64 rng;
int64_t rnd(int64_t l, int64_t r) {
	return uniform_int_distribution<int64_t>(l, r)(rng);
}
int64_t get_divisor(int64_t n) {
	auto f = [&](int64_t x) -> int64_t {
		int64_t res = modmul(x, x, n) + 1;
		if (res == n) res = 0;
		return res;
	};

	while (true) {
		int64_t x = rnd(1, n - 1);
		int64_t y = f(x);
		while (x != y) {
			int64_t d = gcd(n, abs(x - y));
			if (d == 0)
				break;
			else if (d != 1)
				return d;
			x = f(x);
			y = f(f(y));
		}
	}
}

void solve(int test_case = 0) {
	int n; cin >> n;
	vi a(n);
	for(auto &i : a) {
		cin >> i;
	}
	int mx=0;
	for(int i = 0; i < n; ++i) {
		if(mx+a[i] > mx) {
			mx+=a[i];
			cout << mx << " ";
		} else {
			cout << max(0, mx + a[i]) << " ";
		}
	}
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	// precalc();
	int T = 1;
#ifdef runcase
	cin >> T;
#endif

	for(int nt = 0, i; nt < T; nt++) {
		solve(nt);
		++i;
	}
}