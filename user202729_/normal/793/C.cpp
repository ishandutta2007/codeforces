// http://codeforces.com/problemset/problem/793/C

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>

using ld = double;

//{
struct _read_type {
	std::istream& str;
	_read_type(std::istream& str) : str (str) {}
	template <typename T>
	_read_type operator , (T& t) { str >> t; return *this; }
} _read (std::cin);
struct _write_type {
	std::ostream& str;
	_write_type(std::ostream& str) : str (str) {}
	template <typename T>
	_write_type operator , (T t) { str << t; return *this; }
} _write (std::cout);
#define  read _read ,
#define write _write,
//}

ld eps = 1e-12;
//{ [Double comparison]
bool eq(ld x, ld y) {
//	std::cerr << "x = " << x << ", y = " << y << ", "
//	"abs = " << std::abs(x - y) << ", "
//	"eps = " << eps << ", eq = " << (std::abs(ld(x - y))<eps) << "\n";
	return (std::abs(x - y) < eps);
}

bool lt(ld x, ld y) {
	if (eq(x, y)) return false;
	return x < y;
}

bool leq(ld x, ld y) {
	if (eq(x, y)) return true;
	return x < y;
}

bool gt (ld x, ld y) {return lt (y, x);}
bool geq(ld x, ld y) {return leq(y, x);}
//}

struct openrange {
	ld min, max;
	void intersect(openrange r1) {
		min = std::max(min, r1.min);
		max = std::min(max, r1.max);
	}
	bool empty() {
		std::cerr << "min = " << min << ", max = " << max << ", empty = " << geq(min, max) << '\n';
		return geq(min, max); // min >= max, because the range is OPEN
	}
	bool contains(ld pos) {
		return lt(min, pos) && lt(pos, max);
	}
	static openrange const infrange, emptyrange;
};
openrange const openrange::infrange = {-1, 1e9};
openrange const openrange::emptyrange = {1, 0};

openrange inrange(int pos, int velocity, int min, int max) {
	if (velocity == 0) {
		if (min < pos && pos < max) return openrange::infrange;
		else return openrange::emptyrange;
	}
	ld tmin = ld(min - pos) / velocity,
		tmax = ld(max - pos) / velocity;
	return {std::min(tmin, tmax), std::max(tmin, tmax)};
}

int main() {
	std::cerr << std::setprecision(21);

	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
	int nMouse; read nMouse;
	int x1, y1, x2, y2;
	read x1, y1, x2, y2;

	openrange ans = openrange::infrange; // 1e9 is enough

	for (int mouse_id = 0; mouse_id < nMouse; ++mouse_id) {
		int mx, my, vx, vy;
		read mx, my, vx, vy;
		ans.intersect(inrange(mx, vx, x1, x2));
		ans.intersect(inrange(my, vy, y1, y2));
	}

//	std::cerr << "Range = [" << ans.min << ", " << ans.max << "]\n";

	if (leq(ans.max, 0) || ans.empty()) {
		std::cout << "-1\n";
	} else if (lt(ans.min, 0)) { // at exactly point 0
		std::cout << "0\n";
	} else {
		std::cout << std::setprecision(15) << ans.min << '\n'; // min + eps
	}
}

/*

1
-1 2 1 2
0 0 0 1

*/