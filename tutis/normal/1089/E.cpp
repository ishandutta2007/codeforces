#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

template<typename T>
struct seti : public tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> {
	seti(): tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>() {}
	explicit seti(initializer_list<T> o): tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>() {
		for (const T &x : o)
			this->insert(x);
	}
	inline T operator[](int i) {
		return *this->find_by_order(i);
	}
};

int VERY_RANDOM_NUMBER = (uint64_t)(std::make_unique<char>().get()) ^ (uint64_t)(std::chrono::high_resolution_clock::now().time_since_epoch().count());

struct chash {
	inline int operator()(int x) const {
		return x ^ VERY_RANDOM_NUMBER;
	}
};

template <class A, class B>
using hash_table = gp_hash_table<A, B, chash>;

#ifdef LOCAL
template<typename T>
ostream &operator<<(ostream &out, const vector<T> &arr) {
	out << "[";
	bool buv = false;

	for (auto && x : arr) {
		if (buv)
			out << ", ";

		out << x;
		buv = true;
	}

	out << "]";
	return out;
}

template<typename T, typename P>
ostream &operator<<(ostream &out, const map<T, P> &arr) {
	out << "{";
	bool buv = false;

	for (auto && x : arr) {
		if (buv)
			out << ", ";

		out << x.first << " => " << x.second;
		buv = true;
	}

	out << "}";
	return out;
}

template<typename T, typename P>
ostream &operator<<(ostream &out, const set<T, P> &arr) {
	out << "{";
	bool buv = false;

	for (auto && x : arr) {
		if (buv)
			out << ", ";

		out << x;
		buv = true;
	}

	out << "}";
	return out;
}

template<typename T>
ostream &operator<<(ostream &out, const seti<T> &arr) {
	out << "{";
	bool buv = false;

	for (auto && x : arr) {
		if (buv)
			out << ", ";

		out << x;
		buv = true;
	}

	out << "}";
	return out;
}

#define debug(...) __debugg(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __debugg(const char *name, Arg1 &&arg1) {
	cout << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __debugg(const char *names, Arg1 &&arg1, Args &&... args) {
	const char *comma = strchr(names + 1, ',');
	cout.write(names, comma - names) << " : " << arg1 << " | ";

	if (*(comma + 1) == ' ')
		comma++;

	__debugg(comma + 1, args...);
}
#else
#define debug(...)
#endif

template<typename X, typename Y>
struct Pair {
	X x;
	Y y;
	template<typename X1, typename Y1>
	Pair(const X1 &x, const Y1 &y): x(x), y(y) {}
	Pair() {}
	template<typename X1>
	explicit Pair(const X1 &x): x(x), y(Y()) {}
	template<typename X1, typename Y1>
	Pair<X, Y> operator+(const Pair<X1, Y1> &o)const {
		return Pair<X1, Y1>(x + o.x, y + o.y);
	}
	template<typename X1, typename Y1>
	Pair<X, Y> operator-(const Pair<X1, Y1> &o)const {
		return Pair<X1, Y1>(x - o.x, y - o.y);
	}
	template<typename X1, typename Y1>
	Pair<X, Y> operator*(const Pair<X1, Y1> &o)const {
		return Pair<X1, Y1>(x * o.x, y * o.y);
	}
	template<typename X1, typename Y1>
	Pair<X, Y> operator/(const Pair<X1, Y1> &o)const {
		return Pair<X1, Y1>(x / o.x, y / o.y);
	}
	template<typename X1, typename Y1>
	void operator+=(const Pair<X1, Y1> &o) {
		x += o.x;
		y += o.y;
	}
	template<typename X1, typename Y1>
	void operator-=(const Pair<X1, Y1> &o) {
		x -= o.x;
		y -= o.y;
	}
	template<typename X1, typename Y1>
	void operator*=(const Pair<X1, Y1> &o) {
		x *= o.x;
		y *= o.y;
	}
	template<typename X1, typename Y1>
	void operator/=(const Pair<X1, Y1> &o) {
		x /= o.x;
		y /= o.y;
	}
	template<typename X1, typename Y1>
	bool operator<(const Pair<X1, Y1> &o)const {
		if (x == o.x)
			return y < o.y;

		return x < o.x;
	}
	template<typename X1, typename Y1>
	bool operator<=(const Pair<X1, Y1> &o)const {
		if (x == o.x)
			return y <= o.y;

		return x <= o.x;
	}
	template<typename X1, typename Y1>
	bool operator>(const Pair<X1, Y1> &o)const {
		if (x == o.x)
			return y > o.y;

		return x > o.x;
	}
	template<typename X1, typename Y1>
	bool operator>=(const Pair<X1, Y1> &o)const {
		if (x == o.x)
			return y >= o.y;

		return x >= o.x;
	}
	template<typename X1, typename Y1>
	bool operator==(const Pair<X1, Y1> &o)const {
		return x == o.x and y == o.y;
	}
	template<typename X1, typename Y1>
	bool operator!=(const Pair<X1, Y1> &o)const {
		return x != o.x or y != o.y;
	}
	template<typename X1, typename Y1>
	void swap(Pair<X1, Y1> &o) {
		swap(x, o.x);
		swap(y, o.y);
	}
};

template<typename X, typename Y>
Pair<X, Y> makep(const X &x, const Y &y) {
	return Pair<X, Y>(x, y);
}

template<typename X, typename Y>
ostream &operator<<(ostream &out, const Pair<X, Y> &p) {
	out << "(" << p.x << ", " << p.y << ")";
	return out;
}

template<typename X, typename Y>
istream &operator>>(istream &in, Pair<X, Y> &p) {
	in >> p.x >> p.y;
	return in;
}

#define pair Pair

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef Pair<int, int> pii;
typedef Pair<ll, ll> pll;
typedef vector<pll> vpll;

template<typename T>
istream &operator>>(istream &in, vector<T> &arr) {
	for (auto && x : arr) {
		in >> x;
	}

	return in;
}

template<typename X, typename Y>
inline X mini(X &a, const Y &b) __attribute__((always_inline));
template<typename X, typename Y>
inline X mini(X &a, const Y &b) {
	if (a > b)
		a = b;

	return a;
}
template<typename X, typename Y>
inline X maxi(X &a, const Y &b) __attribute__((always_inline));
template<typename X, typename Y>
inline X maxi(X &a, const Y &b) {
	if (a < b)
		a = b;

	return a;
}


string ats(int n) {
	switch (n) {
	case 2:
		return "a1 h1 h8";

	case 3:
		return "a1 b1 h1 h8";

	case 4:
		return "a1 b1 c1 h1 h8";

	case 5:
		return "a1 b1 c1 d1 h1 h8";

	case 6:
		return "a1 b1 c1 d1 e1 h1 h8";

	case 7:
		return "a1 b1 c1 d1 e1 f1 h1 h8";

	case 8:
		return "a1 b1 c1 d1 e1 f1 g1 h1 h8";

	case 9:
		return "a1 b1 c1 d1 e1 f1 h1 g1 g8 h8";

	case 10:
		return "a1 b1 c1 d1 e1 f1 h1 g1 g2 h2 h8";

	case 11:
		return "a1 b1 c1 d1 e1 f1 h1 g1 g2 a2 h2 h8";

	case 12:
		return "a1 b1 c1 d1 e1 f1 h1 g1 g2 a2 b2 h2 h8";

	case 13:
		return "a1 b1 c1 d1 e1 f1 h1 g1 g2 a2 b2 c2 h2 h8";

	case 14:
		return "a1 b1 c1 d1 e1 f1 h1 g1 g2 a2 b2 c2 d2 h2 h8";

	case 15:
		return "a1 b1 c1 d1 e1 f1 h1 g1 g2 a2 b2 c2 d2 e2 h2 h8";

	case 16:
		return "a1 b1 c1 d1 e1 f1 h1 g1 g2 a2 b2 c2 d2 e2 f2 h2 h8";

	case 17:
		return "a1 b1 c1 d1 e1 f1 h1 g1 g2 a2 b2 c2 d2 e2 h2 f2 f8 h8";

	case 18:
		return "a1 b1 c1 d1 e1 f1 h1 g1 g2 a2 b2 c2 d2 e2 h2 f2 f3 h3 h8";

	case 19:
		return "a1 b1 c1 d1 e1 f1 h1 g1 g2 a2 b2 c2 d2 e2 h2 f2 f3 a3 h3 h8";

	case 20:
		return "a1 b1 c1 d1 e1 f1 h1 g1 g2 a2 b2 c2 d2 e2 h2 f2 f3 a3 b3 h3 h8";

	case 21:
		return "a1 b1 c1 d1 e1 f1 h1 g1 g2 a2 b2 c2 d2 e2 h2 f2 f3 a3 b3 c3 h3 h8";

	case 22:
		return "a1 b1 c1 d1 e1 f1 h1 g1 g2 a2 b2 c2 d2 e2 h2 f2 f3 a3 b3 c3 d3 h3 h8";

	case 23:
		return "a1 b1 c1 d1 e1 f1 h1 g1 g2 a2 b2 c2 d2 e2 h2 f2 f3 a3 b3 c3 d3 e3 h3 h8";

	case 24:
		return "a1 b1 c1 d1 e1 f1 h1 g1 g2 a2 b2 c2 d2 e2 h2 f2 f3 a3 b3 c3 d3 e3 g3 h3 h8";

	case 25:
		return "a1 b1 c1 d1 e1 f1 h1 g1 g2 a2 b2 c2 d2 e2 h2 f2 f3 a3 b3 c3 d3 e3 h3 g3 g8 h8";

	case 26:
		return "a1 b1 c1 d1 e1 f1 h1 g1 g2 a2 b2 c2 d2 e2 h2 f2 f3 a3 b3 c3 d3 e3 h3 g3 g4 h4 h8";

	case 27:
		return "a1 b1 c1 d1 e1 f1 h1 g1 g2 a2 b2 c2 d2 e2 h2 f2 f3 a3 b3 c3 d3 e3 h3 g3 g4 a4 h4 h8";

	case 28:
		return "a1 b1 c1 d1 e1 f1 h1 g1 g2 a2 b2 c2 d2 e2 h2 f2 f3 a3 b3 c3 d3 e3 h3 g3 g4 a4 b4 h4 h8";

	case 29:
		return "a1 b1 c1 d1 e1 f1 h1 g1 g2 a2 b2 c2 d2 e2 h2 f2 f3 a3 b3 c3 d3 e3 h3 g3 g4 a4 b4 c4 h4 h8";

	case 30:
		return "a1 b1 c1 d1 e1 f1 h1 g1 g2 a2 b2 c2 d2 e2 h2 f2 f3 a3 b3 c3 d3 e3 h3 g3 g4 a4 b4 c4 d4 h4 h8";

	case 31:
		return "a1 b1 c1 d1 e1 f1 h1 g1 g2 a2 b2 c2 d2 e2 h2 f2 f3 a3 b3 c3 d3 e3 h3 g3 g4 a4 b4 c4 d4 e4 h4 h8";

	case 32:
		return "a1 b1 c1 d1 e1 f1 h1 g1 g2 a2 b2 c2 d2 e2 h2 f2 f3 a3 b3 c3 d3 e3 h3 g3 g4 a4 b4 c4 d4 e4 f4 h4 h8";

	case 33:
		return "a1 b1 c1 d1 e1 f1 h1 g1 g2 a2 b2 c2 d2 e2 h2 f2 f3 a3 b3 c3 d3 e3 h3 g3 g4 a4 b4 c4 d4 e4 h4 f4 f8 h8";

	case 34:
		return "a1 b1 c1 d1 e1 f1 h1 g1 g2 a2 b2 c2 d2 e2 h2 f2 f3 a3 b3 c3 d3 e3 h3 g3 g4 a4 b4 c4 d4 e4 h4 f4 f5 h5 h8";

	case 35:
		return "a1 b1 c1 d1 e1 f1 h1 g1 g2 a2 b2 c2 d2 e2 h2 f2 f3 a3 b3 c3 d3 e3 h3 g3 g4 a4 b4 c4 d4 e4 h4 f4 f5 a5 h5 h8";

	case 36:
		return "a1 b1 c1 d1 e1 f1 h1 g1 g2 a2 b2 c2 d2 e2 h2 f2 f3 a3 b3 c3 d3 e3 h3 g3 g4 a4 b4 c4 d4 e4 h4 f4 f5 a5 b5 h5 h8";

	case 37:
		return "a1 b1 c1 d1 e1 f1 h1 g1 g2 a2 b2 c2 d2 e2 h2 f2 f3 a3 b3 c3 d3 e3 h3 g3 g4 a4 b4 c4 d4 e4 h4 f4 f5 a5 b5 c5 h5 h8";

	case 38:
		return "a1 b1 c1 d1 e1 f1 h1 g1 g2 a2 b2 c2 d2 e2 h2 f2 f3 a3 b3 c3 d3 e3 h3 g3 g4 a4 b4 c4 d4 e4 h4 f4 f5 a5 b5 c5 d5 h5 h8";

	case 39:
		return "a1 b1 c1 d1 e1 f1 h1 g1 g2 a2 b2 c2 d2 e2 h2 f2 f3 a3 b3 c3 d3 e3 h3 g3 g4 a4 b4 c4 d4 e4 h4 f4 f5 a5 b5 c5 d5 e5 h5 h8";

	case 40:
		return "a1 b1 c1 d1 e1 f1 h1 g1 g2 a2 b2 c2 d2 e2 h2 f2 f3 a3 b3 c3 d3 e3 h3 g3 g4 a4 b4 c4 d4 e4 h4 f4 f5 a5 b5 c5 d5 e5 g5 h5 h8";

	case 41:
		return "a1 b1 c1 d1 e1 f1 h1 g1 g2 a2 b2 c2 d2 e2 h2 f2 f3 a3 b3 c3 d3 e3 h3 g3 g4 a4 b4 c4 d4 e4 h4 f4 f5 a5 b5 c5 d5 e5 h5 g5 g8 h8";

	case 42:
		return "a1 b1 c1 d1 e1 f1 h1 g1 g2 a2 b2 c2 d2 e2 h2 f2 f3 a3 b3 c3 d3 e3 h3 g3 g4 a4 b4 c4 d4 e4 h4 f4 f5 a5 b5 c5 d5 e5 h5 g5 g6 h6 h8";

	case 43:
		return "a1 b1 c1 d1 e1 f1 h1 g1 g2 a2 b2 c2 d2 e2 h2 f2 f3 a3 b3 c3 d3 e3 h3 g3 g4 a4 b4 c4 d4 e4 h4 f4 f5 a5 b5 c5 d5 e5 h5 g5 g6 a6 h6 h8";

	case 44:
		return "a1 b1 c1 d1 e1 f1 h1 g1 g2 a2 b2 c2 d2 e2 h2 f2 f3 a3 b3 c3 d3 e3 h3 g3 g4 a4 b4 c4 d4 e4 h4 f4 f5 a5 b5 c5 d5 e5 h5 g5 g6 a6 b6 h6 h8";

	case 45:
		return "a1 b1 c1 d1 e1 f1 h1 g1 g2 a2 b2 c2 d2 e2 h2 f2 f3 a3 b3 c3 d3 e3 h3 g3 g4 a4 b4 c4 d4 e4 h4 f4 f5 a5 b5 c5 d5 e5 h5 g5 g6 a6 b6 c6 h6 h8";

	case 46:
		return "a1 b1 c1 d1 e1 f1 h1 g1 g2 a2 b2 c2 d2 e2 h2 f2 f3 a3 b3 c3 d3 e3 h3 g3 g4 a4 b4 c4 d4 e4 h4 f4 f5 a5 b5 c5 d5 e5 h5 g5 g6 a6 b6 c6 d6 h6 h8";

	case 47:
		return "a1 b1 c1 d1 e1 f1 h1 g1 g2 a2 b2 c2 d2 e2 h2 f2 f3 a3 b3 c3 d3 e3 h3 g3 g4 a4 b4 c4 d4 e4 h4 f4 f5 a5 b5 c5 d5 e5 h5 g5 g6 a6 b6 c6 d6 e6 h6 h8";

	case 48:
		return "a1 b1 c1 d1 e1 f1 h1 g1 g2 a2 b2 c2 d2 e2 h2 f2 f3 a3 b3 c3 d3 e3 h3 g3 g4 a4 b4 c4 d4 e4 h4 f4 f5 a5 b5 c5 d5 e5 h5 g5 g6 a6 b6 c6 d6 e6 f6 h6 h8";

	case 49:
		return "a1 b1 c1 d1 e1 f1 h1 g1 g2 a2 b2 c2 d2 e2 h2 f2 f3 a3 b3 c3 d3 e3 h3 g3 g4 a4 b4 c4 d4 e4 h4 f4 f5 a5 b5 c5 d5 e5 h5 g5 g6 a6 b6 c6 d6 e6 h6 f6 f8 h8";

	case 50:
		return "a1 b1 c1 d1 e1 f1 h1 g1 g2 a2 b2 c2 d2 e2 h2 f2 f3 a3 b3 c3 d3 e3 h3 g3 g4 a4 b4 c4 d4 e4 h4 f4 f5 a5 b5 c5 d5 e5 h5 g5 g6 a6 b6 c6 d6 e6 h6 f6 f7 h7 h8";

	case 51:
		return "a1 b1 c1 d1 e1 f1 h1 g1 g2 a2 b2 c2 d2 e2 h2 f2 f3 a3 b3 c3 d3 e3 h3 g3 g4 a4 b4 c4 d4 e4 h4 f4 f5 a5 b5 c5 d5 e5 h5 g5 g6 a6 b6 c6 d6 e6 h6 f6 f7 a7 h7 h8";

	case 52:
		return "a1 b1 c1 d1 e1 f1 h1 g1 g2 a2 b2 c2 d2 e2 h2 f2 f3 a3 b3 c3 d3 e3 h3 g3 g4 a4 b4 c4 d4 e4 h4 f4 f5 a5 b5 c5 d5 e5 h5 g5 g6 a6 b6 c6 d6 e6 h6 f6 f7 a7 b7 h7 h8";

	case 53:
		return "a1 b1 c1 d1 e1 f1 h1 g1 g2 a2 b2 c2 d2 e2 h2 f2 f3 a3 b3 c3 d3 e3 h3 g3 g4 a4 b4 c4 d4 e4 h4 f4 f5 a5 b5 c5 d5 e5 h5 g5 g6 a6 b6 c6 d6 e6 h6 f6 f7 a7 b7 c7 h7 h8";

	case 54:
		return "a1 b1 c1 d1 e1 f1 h1 g1 g2 a2 b2 c2 d2 e2 h2 f2 f3 a3 b3 c3 d3 e3 h3 g3 g4 a4 b4 c4 d4 e4 h4 f4 f5 a5 b5 c5 d5 e5 h5 g5 g6 a6 b6 c6 d6 e6 h6 f6 f7 a7 b7 c7 d7 h7 h8";

	case 55:
		return "a1 b1 c1 d1 e1 f1 h1 g1 g2 a2 b2 c2 d2 e2 h2 f2 f3 a3 b3 c3 d3 e3 h3 g3 g4 a4 b4 c4 d4 e4 h4 f4 f5 a5 b5 c5 d5 e5 h5 g5 g6 a6 b6 c6 d6 e6 h6 f6 f7 a7 b7 c7 d7 e7 h7 h8";

	case 56:
		return "a1 b1 c1 d1 e1 f1 h1 g1 g2 a2 b2 c2 d2 e2 h2 f2 f3 a3 b3 c3 d3 e3 h3 g3 g4 a4 b4 c4 d4 e4 h4 f4 f5 a5 b5 c5 d5 e5 h5 g5 g6 a6 b6 c6 d6 e6 h6 f6 f7 a7 b7 c7 d7 e7 g7 h7 h8";

	case 57:
		return "a1 b1 c1 d1 e1 f1 h1 g1 g2 a2 b2 c2 d2 e2 h2 f2 f3 a3 b3 c3 d3 e3 h3 g3 g4 a4 b4 c4 d4 e4 h4 f4 f5 a5 b5 c5 d5 e5 h5 g5 g6 a6 b6 c6 d6 e6 h6 f6 f7 a7 b7 c7 d7 e7 h7 g7 g8 h8";

	case 58:
		return "a1 b1 c1 d1 e1 f1 h1 g1 g2 a2 b2 c2 d2 e2 h2 f2 f3 a3 b3 c3 d3 e3 h3 g3 g4 a4 b4 c4 d4 e4 h4 f4 f5 a5 b5 c5 d5 e5 h5 g5 g6 a6 b6 c6 d6 e6 h6 f6 f7 a7 b7 c7 d7 e7 h7 g7 g8 a8 h8";

	case 59:
		return "a1 b1 c1 d1 e1 f1 h1 g1 g2 a2 b2 c2 d2 e2 h2 f2 f3 a3 b3 c3 d3 e3 h3 g3 g4 a4 b4 c4 d4 e4 h4 f4 f5 a5 b5 c5 d5 e5 h5 g5 g6 a6 b6 c6 d6 e6 h6 f6 f7 a7 b7 c7 d7 e7 h7 g7 g8 a8 b8 h8";

	case 60:
		return "a1 b1 c1 d1 e1 f1 h1 g1 g2 a2 b2 c2 d2 e2 h2 f2 f3 a3 b3 c3 d3 e3 h3 g3 g4 a4 b4 c4 d4 e4 h4 f4 f5 a5 b5 c5 d5 e5 h5 g5 g6 a6 b6 c6 d6 e6 h6 f6 f7 a7 b7 c7 d7 e7 h7 g7 g8 a8 b8 c8 h8";

	case 61:
		return "a1 b1 c1 d1 e1 f1 h1 g1 g2 a2 b2 c2 d2 e2 h2 f2 f3 a3 b3 c3 d3 e3 h3 g3 g4 a4 b4 c4 d4 e4 h4 f4 f5 a5 b5 c5 d5 e5 h5 g5 g6 a6 b6 c6 d6 e6 h6 f6 f7 a7 b7 c7 d7 e7 h7 g7 g8 a8 b8 c8 d8 h8";

	case 62:
		return "a1 b1 c1 d1 e1 f1 h1 g1 g2 a2 b2 c2 d2 e2 h2 f2 f3 a3 b3 c3 d3 e3 h3 g3 g4 a4 b4 c4 d4 e4 h4 f4 f5 a5 b5 c5 d5 e5 h5 g5 g6 a6 b6 c6 d6 e6 h6 f6 f7 a7 b7 c7 d7 e7 h7 g7 g8 a8 b8 c8 d8 e8 h8";

	case 63:
		return "a1 b1 c1 d1 e1 f1 h1 g1 g2 a2 b2 c2 d2 e2 h2 f2 f3 a3 b3 c3 d3 e3 h3 g3 g4 a4 b4 c4 d4 e4 h4 f4 f5 a5 b5 c5 d5 e5 h5 g5 g6 a6 b6 c6 d6 e6 h6 f6 f7 a7 b7 c7 d7 e7 h7 g7 g8 a8 b8 c8 d8 e8 f8 h8";
	}
	return "";
}

/*input
4
*/
int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;

	cout << ats(n);

}