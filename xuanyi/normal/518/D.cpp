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

const int MAXN = 2005, MAXT = 2005;

int n, t;
double p, ans, f[MAXN][MAXT];

int main() {
	scanf("%d%lf%d", &n, &p, &t);
	f[0][0] = 1;
	for (int i = 0; i < t; ++i) {
		f[i + 1][n] += f[i][n];
		for (int j = 0; j < n; ++j) if (f[i][j] > 1e-10) {
			f[i + 1][j + 1] += f[i][j] * p;
			f[i + 1][j] += f[i][j] * (1 - p);
		}
	}
	for (int i = 0; i <= n; ++i) ans += i * f[t][i];
	printf("%.6lf\n", ans);
	return 0;
}