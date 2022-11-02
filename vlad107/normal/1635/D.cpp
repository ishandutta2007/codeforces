#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <chrono>
#include <random>
#include <bitset>
#include <functional>
#include <numeric>
#include <array>
#include <limits>
#include <stack>
#include <type_traits>
#include <exception>

using namespace std;

template<typename T>
struct Modular;

template<typename T, T Mod>
struct Modular<typename std::integral_constant<T, Mod>> {
	using IntConstT = typename std::integral_constant<T, Mod>;

	static int const mod = Mod;

	Modular() : value() {}
	template<typename U> Modular(U const &value) : value(normalize(value)) { }

	Modular(Modular const &other) { value = other.value; }
	Modular(Modular &&other) { value = other.value; }

	Modular &operator=(Modular<IntConstT> const &other) { value = other.value; return *this; }

	explicit operator T() const { return value; }
	T operator()() const {
		return value;
	}

	template<typename U>
	inline static T normalize(U const &value) { return ((value % mod) + mod) % mod; }

	inline void normalize_fast() {
		if (value >= mod) value -= mod;
		if (value < 0) value += mod;
	}

	Modular &operator+=(Modular const &other) { value += other.value; normalize_fast(); return *this; }
	Modular &operator-=(Modular const &other) { value -= other.value; normalize_fast(); return *this; }

	template<
		typename U = T,
		typename std::enable_if_t<!std::is_same_v<U, int>, bool> = true
	> 
	Modular &operator*=(Modular const &other) { throw std::runtime_error("default *= doesn't exist"); }

	template<
		typename U = T,
		typename std::enable_if_t<std::is_same_v<U, int>, bool> = true
	>
	Modular &operator*=(Modular const &other) { 
		value = (static_cast<long long>(value) * other.value) % mod;
		return *this;
	}

	Modular &operator/=(Modular const &other) {
		Modular rev_value = other.pow(mod - 2);
		return *this *= rev_value;
	}

	template<typename U>
	Modular pow(U const &x) const {
		Modular res(1);
		Modular cur_p(value);
		U p(x);
		while (p) {
			if (p % 2) res *= cur_p;
			cur_p *= cur_p;
			p /= 2;
		}
		return res;
	}

	void print() {
		std::cerr << value << " " << mod << std::endl;
	}

	Modular &operator++() { return *this += 1; }
	Modular operator++(int) const {
		Modular res(*this);
		++*this;
		return res;
	}
	Modular &operator--() { return *this += 1; }
	Modular operator--(int) const {
		Modular res(*this);
		--*this;
		return *this += 1; 
	}

	friend bool operator==(const Modular<T>& lhs, const Modular<T>& rhs);
	friend bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs);

private:
	T value;
};

#define defineop(op) \
template<typename T> Modular<T> operator op (const Modular<T>& lhs, const Modular<T>& rhs) { return Modular(lhs) op ##= rhs; } \
template<typename T, typename U> Modular<T> operator op (const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) op ##= rhs; } \
template<typename T, typename U> Modular<T> operator op (U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) op ##= rhs; }

defineop(+)
defineop(-)
defineop(*)
defineop(/)

template<typename T> 
bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value == rhs.value; }
template<typename T> 
bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value != rhs.value; }

using Mod = Modular<std::integral_constant<int, 1000000007>>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt = 1;
	while (tt--) {
		int n, p;
		cin >> n >> p;

		vector<Mod> g(p + 1);
		vector<Mod> f(p + 1);
		f[0] = 1;
		g[0] = 1;
		for (int i = 1; i <= p; i++) {
			g[i] = g[i - 1];
			if (i >= 2) g[i] += g[i - 2];
			f[i] = f[i - 1] + g[i];
		}

		Mod res;
		vector<int> a(n);
		set<int> was;
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a.begin(), a.end());
		for (int i = 0; i < n; i++) {
			int x = a[i];
			bool ok = true;
			while (x > 0) {
				if (was.find(x) != was.end()) {
					ok = false;
					break;
				}
				if (x % 2 == 1) {
					x = (x - 1) / 2;
				} else if (x % 4 == 0) {
					x /= 4;
				} else break;
			}
			if (!ok) continue;

			int cnt_bit = 0;
			for (x = a[i]; x > 0; x /= 2) ++cnt_bit;

			was.insert(a[i]);

			if (cnt_bit <= p) {
				res += f[p - cnt_bit];
			}
		}
		cout << res() << "\n";
	}
	return 0;
}