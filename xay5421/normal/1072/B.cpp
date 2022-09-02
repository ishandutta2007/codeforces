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

const int MAXN = 100005;

int n;
int a[MAXN], b[MAXN], c[MAXN];

inline bool IN() {
		
}

int main() {
	read(n);
	for (int i = 1; i < n; ++i) read(a[i + 1]);
	for (int i = 1; i < n; ++i) read(b[i + 1]);
	for (int t = 0; t <= 3; ++t) {
		c[1] = t; int flag = 1;
		for (int i = 2; i <= n; ++i) {
			int flag2 = 0;
			for (int tt = 0; tt <= 3; ++tt) {
				c[i] = tt;
				if (((c[i - 1] | c[i]) == a[i]) && ((c[i - 1] & c[i]) == b[i])) {
					flag2 = 1;
					break;
				}
			}
			if (!flag2) { flag = 0; break; }
		}
		if (flag) {
			puts("YES");
			for (int i = 1; i <= n; ++i) printf("%d ", c[i]);
			return 0;
		}
	}
	puts("NO");
	return 0;
}