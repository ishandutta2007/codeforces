#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define present(t, x) (t.find(x) != t.end())
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcountll(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return val < a ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
template<class T> inline T isqrt(T k) {T r = sqrt(k) + 1; while (r * r > k) r--; return r;}
template<class T> inline T icbrt(T k) {T r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}

const int base = 10;
const int nblock = 9;
const int blockbase = (int) round(pow(base, nblock));
struct Bigint {
	vector<int> a;
	int sign;
	Bigint() : sign(1) {}
	Bigint(long long v) {*this = v;}
	Bigint(const string& s) {read(s);}
	void operator = (const Bigint& v) {sign = v.sign; a = v.a;}
	void operator = (long long v) {
		sign = 1;
		if (v < 0)
			sign = -1, v = -v;
		for (; v > 0; v = v / blockbase)
			a.push_back(v % blockbase);
	}
	Bigint operator + (const Bigint& v) const {
		if (sign == v.sign) {
			Bigint res = v;
			for (int i = 0, carry = 0; i < (int) max(a.size(), v.a.size()) || carry; i++) {
				if (i == (int) res.a.size()) res.a.push_back(0);
				res.a[i] += carry + (i < (int) a.size() ? a[i] : 0);
				carry = res.a[i] >= blockbase;
				if (carry) res.a[i] -= blockbase;
			}
			return res;
		}
		return *this - (-v);
	}
	Bigint operator - (const Bigint& v) const {
		if (sign == v.sign) {
			if (abs() >= v.abs()) {
				Bigint res = *this;
				for (int i = 0, carry = 0; i < (int) v.a.size() || carry; i++) {
					res.a[i] -= carry + (i < (int) v.a.size() ? v.a[i] : 0);
					carry = res.a[i] < 0;
					if (carry) res.a[i] += blockbase;
				}
				res.trim();
				return res;
			}
			return -(v - *this);
		}
		return *this + (-v);
	}
	void operator *= (int v) {
		if (v < 0) sign = -sign, v = -v;
		for (int i = 0, carry = 0; i < (int) a.size() || carry; i++) {
			if (i == (int) a.size()) a.push_back(0);
			long long cur = a[i] * (long long) v + carry;
			carry = (int) (cur / blockbase);
			a[i] = (int) (cur % blockbase);
		}
		trim();
	}
	Bigint operator * (int v) const {
		Bigint res = *this;
		res *= v;
		return res;
	}
	friend pair<Bigint, Bigint> divmod(const Bigint& a1, const Bigint& b1) {
		int norm = blockbase / (b1.a.back() + 1);
		Bigint a = a1.abs() * norm;
		Bigint b = b1.abs() * norm;
		Bigint q, r;
		q.a.resize(a.a.size());
		for (int i = a.a.size() - 1; i >= 0; i--) {
			r *= blockbase;
			r += a.a[i];
			int s1 = r.a.size() <= b.a.size() ? 0 : r.a[b.a.size()];
			int s2 = r.a.size() <= b.a.size() - 1 ? 0 : r.a[b.a.size() - 1];
			int d = ((long long) blockbase * s1 + s2) / b.a.back();
			r -= b * d;
			while (r < 0)
				r += b, d--;
			q.a[i] = d;
		}
		q.sign = a1.sign * b1.sign;
		r.sign = a1.sign;
		q.trim();
		r.trim();
		return make_pair(q, r / norm);
	}
	Bigint operator / (const Bigint& v) const {
		return divmod(*this, v).first;
	}
	Bigint operator % (const Bigint& v) const {
		return divmod(*this, v).second;
	}
	void operator /= (int v) {
		if (v < 0) sign = -sign, v = -v;
		for (int i = (int) a.size() - 1, rem = 0; i >= 0; i--) {
			long long cur = a[i] + rem * (long long) blockbase;
			a[i] = (int) (cur / v);
			rem = (int) (cur % v);
		}
		trim();
	}
	Bigint operator / (int v) const {
		Bigint res = *this;
		res /= v;
		return res;
	}
	int operator % (int v) const {
		if (v < 0) v = -v;
		int m = 0;
		for (int i = a.size() - 1; i >= 0; i--) m = (a[i] + m * (long long) blockbase) % v;
		return m * sign;
	}
	void operator += (const Bigint& v) {
		*this = *this + v;
	}
	void operator -= (const Bigint& v) {
		*this = *this - v;
	}
	void operator *= (const Bigint& v) {
		*this = *this * v;
	}
	void operator /= (const Bigint& v) {
		*this = *this / v;
	}
	bool operator < (const Bigint& v) const {
		if (sign != v.sign) return sign < v.sign;
		if (a.size() != v.a.size()) return a.size() * sign < v.a.size() * v.sign;
		for (int i = a.size() - 1; i >= 0; i--) if (a[i] != v.a[i]) return a[i] * sign < v.a[i] * sign;
		return false;
	}
	bool operator > (const Bigint& v) const {
		return v < *this;
	}
	bool operator <= (const Bigint& v) const {
		return !(v < *this);
	}
	bool operator >= (const Bigint& v) const {
		return !(*this < v);
	}
	bool operator == (const Bigint& v) const {
		return !(*this < v) && !(v < *this);
	}
	bool operator != (const Bigint& v) const {
		return *this < v || v < *this;
	}
	void trim() {
		while (!a.empty() && !a.back()) a.pop_back();
		if (a.empty()) sign = 1;
	}
	bool isZero() const {
		return a.empty() || (a.size() == 1 && !a[0]);
	}
	Bigint operator - () const {
		Bigint res = *this;
		res.sign = -sign;
		return res;
	}
	Bigint abs() const {
		Bigint res = *this;
		res.sign *= res.sign;
		return res;
	}
	long long longValue() const {
		long long res = 0;
		for (int i = a.size() - 1; i >= 0; i--) res = res * blockbase + a[i];
		return res * sign;
	}
	friend Bigint gcd(const Bigint& a, const Bigint& b) {
		return b.isZero() ? a : gcd(b, a % b);
	}
	friend Bigint lcm(const Bigint& a, const Bigint& b) {
		return a / gcd(a, b) * b;
	}
	void read(const string& s) {
		sign = 1; a.clear(); int pos = 0;
		while (pos < (int) s.size() && (s[pos] == '-' || s[pos] == '+')) {if (s[pos] == '-') sign = -sign; pos++;}
		for (int i = s.size() - 1; i >= pos; i -= nblock) {
			int x = 0;
			for (int j = max(pos, i - nblock + 1); j <= i; j++) x = x * base + s[j] - '0';
			a.push_back(x);
		}
		trim();
	}
	friend istream& operator>>(istream& stream, Bigint& v) {
		string s; stream>>s; v.read(s);
		return stream;
	}
	friend ostream& operator<<(ostream& stream, const Bigint& v) {
		if (v.sign == -1) stream << '-';
		stream<<(v.a.empty() ? 0 : v.a.back());
		for (int i = (int) v.a.size() - 2; i >= 0; i--) stream << setw(nblock) << setfill('0') << v.a[i];
		return stream;
	}
	static vector<int> convert_base(const vector<int>& a, int old_digits, int new_digits) {
		vector<long long> p(max(old_digits, new_digits) + 1);
		p[0] = 1;
		for (int i = 1; i < (int) p.size(); i++) p[i] = p[i - 1] * base;
		vector<int> res;
		long long cur = 0;
		int cur_digits = 0;
		for (int i = 0; i < (int) a.size(); i++) {
			cur += a[i] * p[cur_digits];
			cur_digits += old_digits;
			while (cur_digits >= new_digits) {
				res.push_back(int(cur % p[new_digits]));
				cur /= p[new_digits];
				cur_digits -= new_digits;
			}
		}
		res.push_back((int) cur);
		while (!res.empty() && !res.back()) res.pop_back();
		return res;
	}
	static vector<long long> karatsuba(vector<long long>& a, vector<long long>& b) {
		int n = a.size();
		vector<long long> res(n << 1);
		if (n <= 32) {
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					res[i + j] += a[i] * b[j];
			return res;
		}
		int k = n >> 1;
		vector<long long> a1(a.begin(), a.begin() + k);
		vector<long long> a2(a.begin() + k, a.end());
		vector<long long> b1(b.begin(), b.begin() + k);
		vector<long long> b2(b.begin() + k, b.end());
		vector<long long> a1b1 = karatsuba(a1, b1);
		vector<long long> a2b2 = karatsuba(a2, b2);
		for (int i = 0; i < k; i++) a2[i] += a1[i];
		for (int i = 0; i < k; i++) b2[i] += b1[i];
		vector<long long> r = karatsuba(a2, b2);
		for (int i = 0; i < (int) a1b1.size(); i++) r[i] -= a1b1[i];
		for (int i = 0; i < (int) a2b2.size(); i++) r[i] -= a2b2[i];
		for (int i = 0; i < (int) r.size(); i++) res[i + k] += r[i];
		for (int i = 0; i < (int) a1b1.size(); i++) res[i] += a1b1[i];
		for (int i = 0; i < (int) a2b2.size(); i++) res[i + n] += a2b2[i];
		return res;
	}
	Bigint operator * (const Bigint& v) const {
		int r = 6;
		int t = round(pow(base, r));
		vector<int> ar = convert_base(this->a, nblock, r);
		vector<int> br = convert_base(v.a, nblock, r);
		vector<long long> a(ar.begin(), ar.end());
		vector<long long> b(br.begin(), br.end());
		while (a.size() < b.size()) a.push_back(0);
		while (b.size() < a.size()) b.push_back(0);
		while (a.size() & (a.size() - 1)) a.push_back(0), b.push_back(0);
		vector<long long> c = karatsuba(a, b);
		Bigint res;
		res.sign = sign * v.sign;
		for (int i = 0, carry = 0; i < (int) c.size(); i++) {
			long long cur = c[i] + carry;
			res.a.push_back((int) (cur % t));
			carry = (int) (cur / t);
		}
		res.a = convert_base(res.a, r, nblock);
		res.trim();
		return res;
	}
	friend Bigint sqrt(const Bigint& a) {
		Bigint x0 = a, x1 = (a + 1) / 2;
		while (x1 < x0) {
			x0 = x1;
			x1 = (x1 + a / x1) / 2;
		}
		return x0;
	}
	friend Bigint pow(Bigint a, Bigint b) {
		if (b == Bigint(0)) return Bigint(1);
		Bigint T = pow(a, b / 2);
		if (b % 2 == 0) return T * T;
		return T * T * a;
	}
	friend Bigint pow(Bigint a, int b) {
		return pow(a, (Bigint(b)));
	}
	friend int log(Bigint a, int n) {
		int res = 0;
		while (a > Bigint(1)) {
			res++;
			a /= n;
		}
		return res;
	}
};

const int maxn = 100 + 10;
int n;
int p[maxn];
int f[maxn];
int vis[maxn];

void solve() {
	cin >> n;
	FOR(i, 0, n) cin >> p[i], p[i]--, f[p[i]] = 1;
	FOR(i, 0, n) if (!f[i]) {
		cout << -1 << "\n";
		return;
	}
	Bigint ans = 1;
	FOR(i, 0, n) if (!vis[i]) {
		int cur = i, cnt = 0;
		while (!vis[cur]) {
			vis[cur] = 1, cnt++;
			cur = p[cur];
		}
		if (cnt & 1) {
			ans = lcm(ans, cnt);
		}
		else {
			ans = lcm(ans, cnt >> 1);
		}
	}
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}