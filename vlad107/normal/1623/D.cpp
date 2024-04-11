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
#include <exception>
#include <random>
#include <bitset>
#include <type_traits>
#include <functional>
#include <numeric>
#include <array>
#include <limits>
#include <stack>

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

int solve(vector<int> const &touches, Mod prob) {
	prob /= 100;
	Mod k(1), b(0);
	for (int i = (int)touches.size() - 1; i >= 0; i--) {
		++b;
		if (touches[i]) {
			b *= 1 - prob;
			k *= 1 - prob;
		}
	}
	return (b / (1 - k))();
}

int solve(int n, int m, int sx, int sy, int ex, int ey, int p) {
	auto is_touch = [ex, ey](int x, int y) {
		return (x == ex) || (y == ey);
	};

	auto step = [n, m](int &x, int &y, int &vx, int &vy) {
		if ((x + vx < 1) || (x + vx > n)) vx = -vx;
		if ((y + vy < 1) || (y + vy > m)) vy = -vy;
		x += vx;
		y += vy;
	};

	int L = 2 * (n - 1) * (m - 1) / gcd(n - 1, m - 1);
	vector<int> touches;
	touches.reserve(L);
	int x = sx, y = sy, vx = 1, vy = 1;
	for (int i = 0; i < L; i++) {
		touches.push_back(is_touch(x, y));
		step(x, y, vx, vy);
	}

	return solve(touches, p);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, m, sx, sy, ex, ey, p;
		cin >> n >> m >> sx >> sy >> ex >> ey >> p;
		cout << solve(n, m, sx, sy, ex, ey, p) << "\n";
	}
	return 0;
}