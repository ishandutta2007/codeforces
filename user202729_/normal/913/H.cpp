// http://codeforces.com/contest/913/problem/H

#ifdef Sublime
#include <iostream>
#include <sstream>
#define cin cin__
namespace std{std::stringstream cin(R"(
6
0.77
1.234567
2.1
1.890
2.9999
3.77
)");}
#endif // Sublime


#ifndef _GLIBCXX_DEBUG
#define NDEBUG
#endif
#include <cassert>

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>
#include <climits>

int constexpr MOD = 998244353;

int inverse(int x, int y) {
	int a = x, b = y, ax = 1, ay = 0, bx = 0, by = 1;
	while (b) {
		int q = a / b, tmp;
		tmp = a  - q * b ; a  = b ; b  = tmp;
		tmp = ax - q * bx; ax = bx; bx = tmp;
		tmp = ay - q * by; ay = by; by = tmp;
	}
	while (ax < 0) ax += y;
	return ax;
}

template <int MOD>
class num_mod {
	int v;
public:
	num_mod() : v(0) {}
	num_mod(int v) : v(v) {
		assert(0 <= v && v < MOD);
	}
	explicit operator int () const {
		return v;
	}
	num_mod& operator += (num_mod a) { v += a.v; if (v >= MOD) v -= MOD; return *this; }
	num_mod& operator -= (num_mod a) { v -= a.v; if (v < 0   ) v += MOD; return *this; }
	num_mod& operator *= (num_mod a) { v = v * (int64_t)        a.v     %MOD; return *this; }
	num_mod& operator /= (num_mod a) { v = v * (int64_t)inverse(a.v,MOD)%MOD; return *this; }
 	#define d(OP) num_mod operator OP (num_mod x) const { return x OP##= *this; }
	d(+) d(*)
	#undef d
 	#define d(OP) num_mod operator OP (num_mod x) const { num_mod ans = *this; return ans OP##= x; }
	d(-) d(/)
	#undef d
	num_mod operator - () const {
		return { MOD - v - MOD *!v }; // *!: obfuscation (subtract MOD iff v == 0 (falsy))
	}
	
	bool operator == (num_mod x) const { return v == x.v; }

	template <int MOD1>
	friend std::ostream& operator << (
		std::ostream&, num_mod<MOD1> const&);
}; // NOT ordered

template <int DENOM>
class fix_frac {
	int v;
public:
	fix_frac() : v() {}
	fix_frac(int v) : v(v * DENOM) {} // construct from number
	fix_frac(int v, int) : v(v) {} // construct from numerator

	fix_frac operator - () const { 
		assert(v != INT_MIN);
		return fix_frac(-v, 0);
	}
	fix_frac& operator += (fix_frac x) { 
		if (v == INT_MIN) {
			// -inf already, nothing to do
		} else if (x.v == INT_MIN) {
			
			/* not necessary */ assert(false);
			
			v = INT_MIN;
		} else
			v += x.v;
		return *this;
	}
	fix_frac& operator -= (fix_frac x) {
		if (v == INT_MIN) {
			
			/* not necessary */ assert(false);
			
			assert (x.v != INT_MIN);
			return *this; // -inf already, nothing to do
		}
		assert(x.v != INT_MIN); // cannot subtract (-INF) (will get +INF, not supported)
		v -= x.v; return *this; 
	}
/*
	operator double () const {
		return v / (double) DENOM;
	}
*/	
	fix_frac operator + (fix_frac x) const { return x += *this; }
	fix_frac operator - (fix_frac x) const { fix_frac ans = *this; return ans -= x; }

	template <int MOD>
	explicit operator num_mod<MOD> () const {
		int64_t const INV_DENOM = inverse(DENOM, MOD);
		int ans = v * INV_DENOM % MOD;
		return { ans + MOD * (ans < 0) };
	}

	// bool operator <=> // someday...
	#define d(OP) \
	bool operator OP (fix_frac x) const { return v OP x.v; }
	d(<) d(>) d(<=) d(>=) d(==) d(!=)
	#undef d

	static fix_frac const MIN;

	template <int DENOM1>
	friend std::ostream& operator << (std::ostream&, fix_frac<DENOM1> const &);
};

template <int MOD>
std::ostream& operator << (std::ostream& str, num_mod<MOD> const& a) {
	return str << a.v;
}

template <int DENOM>
std::ostream& operator << (std::ostream& str, fix_frac<DENOM> const & a) {
	return str << a.v << "/" << DENOM;
}

template <int DENOM>
fix_frac<DENOM> const fix_frac<DENOM>::MIN { INT_MIN, 0 };

namespace std {
	template <int DENOM>
	struct numeric_limits<fix_frac<DENOM>> {
		static fix_frac<DENOM> const min () {
			return fix_frac<DENOM>::MIN;
		}
	};
}

template <class num>
class poly {
public:
	std::vector<num> x; // coefficients

	poly() : x (1/*, {}*/) {} // zero polynomial (coeff size == 1)
	poly(std::vector<num> x) : x(std::move(x)) {}

	poly& operator += (poly const & b) {
		if (x.size() < b.x.size())
			x.resize(b.x.size(), 0);
		for (size_t i = b.x.size(); i --> 0;)
			x[i] += b.x[i];
		return *this;
	}
	
	poly operator + (poly x) const { return x += *this; }

	poly integrate() const {
		poly ans; ans.x.resize(x.size()+1);
		for (size_t i = ans.x.size(); i --> 1;)
			ans.x[i] = x[i-1] / i;
		return ans;
	}

	// Polynomial multiplication.
	poly operator * (poly const & b) const {
		std::vector<num> ans; ans.resize(x.size() + b.x.size() - 1);

		for (size_t i = x.size(); i --> 0;)
			for (size_t j = b.x.size(); j --> 0;)
				ans[i+j] += x[i] * b.x[j];

		return poly(std::move(ans));
	}
	
	poly& operator *= (poly b) {
		return *this = *this * b;
	}

	poly& operator *= (num b) {
		for (num& a : x) a *= b;
		return *this;
	}
	
	poly operator * (num b) const { poly ans = *this; return ans *= b; }

	/// Function composition.
	poly operator ^ (poly const & b) const {
		poly ans; // zero
		poly base ({1});
		for (num v : x) {
			ans += base * v;
			base *= b;
		}
		return ans;
	}
	
	poly& operator ^= (poly x) { return *this = *this ^ x; }

	poly operator - () const {
		poly ans; ans.x.resize(x.size());
		for (size_t i = x.size(); i --> 0;)
			ans.x[i] = -x[i];
		return ans;
	}

	/// polynomial evaluation
	num operator () (num a) {
		num base = 1, ans = 0;
		for (num v : x) {
			ans += base * v;
			base *= a;
		}
		return ans;
	}
};

template <class T>
std::ostream& operator << (std::ostream& str, poly<T> const & a) {
	for (size_t i = 0; i < a.x.size(); ++i) {
		str << " + " << a.x[i];
		if (i == 0) continue;
		str << 'x';
		if (i > 1) 
			str << '^' << i;
	}
	return str;
}

/// Piecewise polynomial.
template <class xnum, class ynum>
class func {
	using polyN = poly<ynum>;
	using funcN = func<xnum, ynum>;
	
	struct piece {
		polyN p; xnum s; // start
		piece(polyN p, xnum s) : p(p), s(s) {}
	};
	
public:
	std::vector<piece> t;
	
	/// Initialize to the step function f(x) = 0 if x <= 0 else 1
	func() : t { piece{polyN(), std::numeric_limits<xnum>::min()}, piece{polyN({1}), 0} } {
		// self.t = t or [poly(), 0, poly([0, 1])] # <-- max(0, x), integrate of step function.
	}
	func(std::vector<piece> t) : t(std::move(t)) {}

	funcN operator - () const {
		funcN ans (t);
		for (piece& p : ans.t)
			p.p = -p.p;
		return ans;
	}

	funcN operator + (funcN const & x) const {
		std::vector<piece> ans;
		
		std::vector<piece> a = t, b = x.t; // copy

		while (!a.empty() && !b.empty()) {
			if (a.back().s < b.back().s) {
				ans.emplace_back(a.back().p + b.back().p, b.back().s);
				b.pop_back();
			} else if (b.back().s < a.back().s) {
				ans.emplace_back(a.back().p + b.back().p, a.back().s);
				a.pop_back();
			} else {
				ans.emplace_back(a.back().p + b.back().p, a.back().s);
				a.pop_back();
				b.pop_back();
			}
		}

		assert(a.empty() && b.empty());
		assert(ans.back().s == std::numeric_limits<xnum>::min());

		std::reverse(ans.begin(), ans.end());
		return funcN(std::move(ans));
	}
	
	funcN& operator += (funcN x) { return *this = x + *this; }

	funcN integrate() const {
		std::vector<piece> ans = t;
		for (piece& p : ans)
			p.p = p.p.integrate();

		for (size_t i = 1; i < ans.size(); ++i) {
			
			// fit poly ans.t[i] with ans.t[i-2]
			ynum last_val = ans[i-1].p((ynum) ans[i].s);
			ynum this_val = ans[i  ].p((ynum) ans[i].s);
			
			ans[i].p.x[0] += last_val - this_val;
			assert( ans[i-1].p((ynum) ans[i].s) == ans[i  ].p((ynum) ans[i].s) );
		}

		return ans;
	}

	/// Shift this function left (++) by (a) units.
	funcN& operator >>= (xnum a) {
		polyN p ({(ynum) -a, (ynum) 1});
		for (piece& pi : t) {
			pi.p ^= p;
			pi.s += a;
		}
		return *this;
	}
	
	funcN operator >> (xnum a) const {
		funcN ans = *this;
		return ans >>= a;
	}

	/// Set all values of self at value >= a to self(a).
	funcN& flatten_larger(xnum a) {
		if (!(t.size() == 1 || t.back().s < a)) {
			// len(t) must be at least 3 and t[1] >= a
			while (t.size() >= 2 and (----t.end())->s  >= a)
				t.pop_back();
			t.pop_back(); // remove the last function
		}
		t.emplace_back( polyN( { t.back().p((ynum) a) } ), a );
		return *this;
	}

};

template <class xnum, class ynum>
std::ostream& operator << (std::ostream& str, func<xnum, ynum> const & a) {
	str << "Piecewise[{";
	for (size_t x = a.t.size(); x --> 1;) {
		str << '{' << a.t[x].p << ",x>" << a.t[x].s << '}';
		if (x != 1) str << ',';
	}
	return str << "}," << a.t[0].p << ']';
}

int main() {

	int constexpr DENOM = 1000000;

	int n; std::cin >> n;

	func<fix_frac<DENOM>, num_mod<MOD>> fn;

	for (int i = n; i --> 0;) {
		double xi_f; std::cin >> xi_f;
		fix_frac<DENOM> xi { (int) std::round(xi_f * DENOM), 0 };
		fn = fn.integrate();
		fn += -(fn >> 1);
		fn.flatten_larger(xi);
	}

	assert(fn.t.back().p.x.size() == 1);
	int ans = (int) (num_mod<MOD>) fn.t.back().p.x[0]; // this must be a constant function
	// print(ans.numerator * inverse(ans.denominator, mod) % mod)
	std::cout << ans << '\n';

	return 0;

}