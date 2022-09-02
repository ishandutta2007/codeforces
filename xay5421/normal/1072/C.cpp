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

int a, b, cnt, q1[MAXN], q2[MAXN];
bool used[MAXN];

int main() {
	int i, j, k;
	read(a), read(b);
	for(i = 1; ; ++i)
		if (a >= i) a -= i, used[i] = 1;
		else {
			used[i] = 1;
			used[i - a] = 0;
			break;
		}
	for (i = 1; i <= 100000; ++i) if (used[i]) q1[++q1[0]] = i;
	for (i = 1; ; ++i) if (b >= i) {
		if (!used[i]) b -= i, q2[++q2[0]] = i;
	} else break;
	print(q1[0]), putchar('\n');
	for (i = 1; i <= q1[0]; ++i) print(q1[i]), putchar(' '); putchar('\n');
	print(q2[0]), putchar('\n');
	for (i = 1; i <= q2[0]; ++i) print(q2[i]), putchar(' '); putchar('\n');
	return 0;
}