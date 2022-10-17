#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
typedef long long ll;
typedef unsigned long long ull;
typedef std::pair <int, int> pii;
typedef std::vector <int> vi;
typedef std::vector <pii> vp;
using std::sort;
using std::nth_element;

template <typename T>
inline T max(const T &x, const T &y) { return x < y ? y : x; }

template <typename T>
inline T min(const T &x, const T &y) { return x < y ? x : y; }

template <typename T>
inline T chkmax(T &x, const T &y) { if (x < y) x = y; }

template <typename T>
inline T chkmin(T &x, const T &y) { if (y < x) x = y; }

template <typename T>
inline T fabs(const T &x) { if (x < 0) return -x; return x; }

template <typename T>
inline void swap(T &x, T &y) { T t = x; x = y, y = t; }

template <typename T>
inline void read(T &x) {
	int fl = 0, ch;
	while (ch = getchar(), ch < 48 || 57 < ch) fl ^= ! (ch ^ 45); x = (ch & 15);
	while (ch = getchar(), 47 < ch && ch < 58) x = (x << 1) + (x << 3) + (ch & 15);
	if (fl) x = -x;
}

template <typename T>
inline void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar(x % 10 + 48);
}

template <typename T>
inline void print(T x, char ch) { print(x), putchar(ch); }

int n;
double p, l, ans;

int main() {
	read(n);
	for (int i = 1; i <= n; ++i) {
		scanf("%lf", &p);
		ans += (l * 2 + 1) * p;
		l = (l + 1) * p;
	}
	printf("%.10lf\n", ans);
	return 0;
}