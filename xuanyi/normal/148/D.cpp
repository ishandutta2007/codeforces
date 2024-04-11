#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <pii> vp;

template <typename T>
inline T max(const T &x, const T &y) { return x < y ? y : x; }

template <typename T>
inline T min(const T &x, const T &y) { return x < y ? x : y; }

template <typename T>
inline T chkmax(T &x, const T &y) { if (x < y) x = y; }

template <typename T>
inline T chkmin(T &x, const T &y) { if (y < x) x = y; }

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

const int MAXW = 1005, MAXB = 1005;

int w, b;
double f[MAXW][MAXB];

int main() {
	read(w), read(b);
	for (int i = 0; i <= w; ++i)
		for (int j = 0; j <= b; ++j) {
			if (i == 0) { f[i][j] = 0.0; continue; }
			if (j == 0) { f[i][j] = 1.0; continue; }
			f[i][j] = 1.0 * i / (i + j);
			if (j >= 2) f[i][j] += 1.0 * j / (i + j) * (j - 1) / (i + j - 1) * i / (i + j - 2) * f[i - 1][j - 2];
			if (j >= 3) f[i][j] += 1.0 * j / (i + j) * (j - 1) / (i + j - 1) * (j - 2) / (i + j - 2) * f[i][j - 3];
		}
	printf("%.9lf\n", f[w][b]);
	return 0;
}