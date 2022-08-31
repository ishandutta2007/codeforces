#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__);fflush(stderr);
#else
	#define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

const ld PI = 4 * atanl(1.);

const ld eps = 1e-6;
bool eq(ld x, ld y) {
	return fabsl(x - y) < eps;
}
bool ls (ld x, ld y) {
	return x < y && !eq(x, y);
}
bool lseq(ld x, ld y) {
	return x < y || eq(x, y);
}

struct Point {
	ld x, y;

	Point() : x(), y() {}
	Point (ld _x, ld _y) : x(_x), y(_y) {}

	Point operator + (const Point &a) const {
		return Point(x + a.x, y + a.y);
	}
	Point operator - (const Point &a) const {
		return Point(x - a.x, y - a.y);
	}
	Point operator * (const ld &k) const {
		return Point(x * k, y * k);
	}
	Point operator / (const ld &k) const {
		return Point(x / k, y / k);
	}
	ld operator % (const Point &a) const {
		return x * a.x + y * a.y;
	}
	ld operator * (const Point &a) const {
		return x * a.y - y * a.x;
	}
	ld sqrLen() const {
		return *this % *this;
	}
	ld len() const {
		return sqrt(sqrLen());
	}
	Point norm() const {
		return *this / len();
	}
	Point ort() const {
		return Point(-y, x);
	}
	Point rot(const double &ca, const double &sa) const {
		return *this * ca + ort() * sa;
	}
	Point rot(const double &ang) const {
		return rot(cos(ang), sin(ang));
	}
};

ld R;

bool check(int X, int Y) {
	Point C = Point(X * 1.5, Y * sqrtl(3) / 2);
	Point d = Point(1, 0);
	for (int i = 0; i < 6; i++) {
		Point P = C + d;
		if (ls(R, P.sqrLen())) return false;
		d = d.rot(PI / 3);
	}
	return true;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	ll ans = 0;

	int P;
	scanf("%d", &P);
	R = (double)P * P;
	int y = 2 * P;
	for (int x = 0; x <= P; x++) {
		while(y >= 0 && !check(x, y)) y--;
		if (y < 0) break;
		int cnt = y;
		if (x % 2 == 0) {
			if (cnt % 2 == 0) cnt++;
		} else {
			if (cnt % 2 == 1) cnt++;
		}
		if (x == 0)
			ans += cnt;
		else
			ans += 2 * cnt;
	}
	printf("%lld\n", ans);

	return 0;
}