#include<bits/stdc++.h>
 
namespace std {
 
template<class Fun>
class y_combinator_result {
	Fun fun_;
public:
	template<class T>
	explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
 
	template<class ...Args>
	decltype(auto) operator()(Args &&...args) {
		return fun_(std::ref(*this), std::forward<Args>(args)...);
	}
};
 
template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
	return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
 
} // namespace std
 
template <int MOD_> struct modnum {
	static constexpr int MOD = MOD_;
	static_assert(MOD_ > 0, "MOD must be positive");
 
private:
	using ll = long long;
 
	int v;
 
	static int minv(int a, int m) {
		a %= m;
		assert(a);
		return a == 1 ? 1 : int(m - ll(minv(m, a)) * ll(m) / a);
	}
 
public:
 
	modnum() : v(0) {}
	modnum(ll v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
	explicit operator int() const { return v; }
	friend std::ostream& operator << (std::ostream& out, const modnum& n) { return out << int(n); }
	friend std::istream& operator >> (std::istream& in, modnum& n) { ll v_; in >> v_; n = modnum(v_); return in; }
 
	friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
	friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }
 
	modnum inv() const {
		modnum res;
		res.v = minv(v, MOD);
		return res;
	}
	friend modnum inv(const modnum& m) { return m.inv(); }
	modnum neg() const {
		modnum res;
		res.v = v ? MOD-v : 0;
		return res;
	}
	friend modnum neg(const modnum& m) { return m.neg(); }
 
	modnum operator- () const {
		return neg();
	}
	modnum operator+ () const {
		return modnum(*this);
	}
 
	modnum& operator ++ () {
		v ++;
		if (v == MOD) v = 0;
		return *this;
	}
	modnum& operator -- () {
		if (v == 0) v = MOD;
		v --;
		return *this;
	}
	modnum& operator += (const modnum& o) {
		v -= MOD-o.v;
		v = (v < 0) ? v + MOD : v;
		return *this;
	}
	modnum& operator -= (const modnum& o) {
		v -= o.v;
		v = (v < 0) ? v + MOD : v;
		return *this;
	}
	modnum& operator *= (const modnum& o) {
		v = int(ll(v) * ll(o.v) % MOD);
		return *this;
	}
	modnum& operator /= (const modnum& o) {
		return *this *= o.inv();
	}
 
	friend modnum operator ++ (modnum& a, int) { modnum r = a; ++a; return r; }
	friend modnum operator -- (modnum& a, int) { modnum r = a; --a; return r; }
	friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
	friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
	friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
	friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
};
 
int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
 
	int N; cin >> N;
	vector<int> A(N); for (auto& a : A) cin >> a;
 
	const int V = int(2e5);
	assert(*max_element(A.begin(), A.end()) <= V);
 
	using num = modnum<int(1e9)+7>;
 
	vector<int> primes; primes.reserve(V);
	vector<num> pinv(V+1);
	vector<int> pfac(V+1);
	for (int i = 2; i <= V; i++) {
		if (!pfac[i]) { pfac[i] = i; primes.push_back(i); pinv[i] = inv(num(i)); }
		for (int p : primes) {
			if (p > V/i) break;
			pfac[p*i] = p;
			if (p == pfac[i]) break;
		}
	}
 
	vector<int> last_seen(V+1, -1);
 
	vector<num> pref(N+1);
	pref[0] = 1;
	for (int i = 0; i < N; i++) pref[i+1] = pref[i] * num(A[i]);
	vector<num> inv_pref(N+1);
	inv_pref[N] = inv(pref[N]);
	for (int i = N-1; i >= 0; i--) inv_pref[i] = inv_pref[i+1] * num(A[i]);
 
	const int L = N ? (32 - __builtin_clz(N-1)) : 0;
	assert((1 << L) >= N);
	struct node {
		int c[2] = {0, 0};
		num v = num(1);
	};
	vector<node> seg(1); seg.reserve(4e6);
	int freeze_idx = 1;
	auto freeze = [&]() { freeze_idx = int(seg.size()); };
	auto update = std::y_combinator([&](auto self, int& a_ref, int level, int x, num v) -> void {
		if (!(x & ((1 << level)-1))) {
			return;
		}
		int a = a_ref;
		--level;
		if (a < freeze_idx) {
			a_ref = int(seg.size());
			seg.push_back(seg[a]);
			a = int(seg.size())-1;
		}
		assert(a >= freeze_idx);
		if ((x >> level) & 1) {
			seg[a].v *= v;
		}
		self(seg[a].c[(x >> level) & 1], level, x, v);
	});
 
	int cur_root = 0;
	vector<int> roots(N);
	// for prime p, if it divides A[k_1], A[k_2], ...
	// ans[l][r] *= p if l <= k_something < r
	// equivalently, for each i:
	//   ans[k_{i-1}..k_i][k_i..N] *= p
	for (int i = 0; i < N; i++) {
		int a = A[i];
		while (a > 1) {
			int p = pfac[a];
			int e = 0, q = 1;
 
			num invP = pinv[p];
 
			num curInv = 1;
			while (a % p == 0) {
				a /= p;
				e++, q *= p;
 
				curInv *= invP;
 
				if (a % p == 0 && last_seen[q*p] == last_seen[q]) {
					// don't insert it yet, just wait until the next loop
				} else {
					if (last_seen[q] != -1) {
						update(cur_root, L, last_seen[q]+1, curInv);
					}
					curInv = 1;
				}
				last_seen[q] = i;
			}
		}
		freeze();
		roots[i] = cur_root;
	}
 
	auto query = [&](int l, int r) -> num {
		assert(0 <= l && l < r && r <= N);
 
		num ans = pref[r] * inv_pref[l];
		for (int a = roots[r-1], level = L; a && ((~l) & ((1 << level)-1)); ) {
			assert(level);
			--level;
			if ((l >> level) & 1) {
				a = seg[a].c[1];
			} else {
				ans *= seg[a].v;
				a = seg[a].c[0];
			}
		}
		return ans;
	};
 
	int Q; cin >> Q;
	int last = 0;
	while (Q--) {
		int x, y; cin >> x >> y;
		int l = (last + x) % N + 1;
		int r = (last + y) % N + 1;
		if (l > r) swap(l, r);
		// half-open interval
		l--;
		num ans = query(l, r);
		cout << (last = int(ans)) << '\n';
	}
 
	return 0;
}