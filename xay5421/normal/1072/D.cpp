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
using std::make_pair;
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

const int MAXN = 2005;

int n, k, f[MAXN][MAXN];
char s[MAXN][MAXN];
bool vis[MAXN][MAXN];
vp t[MAXN * 2], t2;
vp :: iterator it;

int main() {
	memset(f, 63, sizeof(f)); f[1][0] = f[0][1] = 0;
	read(n), read(k);
	for (int i = 1; i <= n; ++i) scanf("%s", s[i] + 1);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			f[i][j] = min(f[i - 1][j], f[i][j - 1]) + (s[i][j] != 'a');
			t[i + j].push_back(make_pair(i, j));
		}
	int max_x = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (f[i][j] <= k) {
				if (i + j > max_x) {
					max_x = i + j;
					t2.clear();
					t2.push_back(make_pair(i, j));
				} else if (i + j == max_x) {
					t2.push_back(make_pair(i, j));
				}
			}
	for (int i = 2; i <= max_x; ++i) putchar('a');
	if (t2.empty()) t2.push_back(make_pair(1, 1)), max_x = 2, putchar(s[1][1]);
	for (int i = max_x + 1; i <= n + n; ++i) {
		int min_x = 'z';
		for (int j = 0; j < t2.size(); j++) {
			if(t2[j].first != n) if(s[t2[j].first + 1][t2[j].second] < min_x) min_x = s[t2[j].first + 1][t2[j].second];
			if(t2[j].second != n) if(s[t2[j].first][t2[j].second + 1] < min_x) min_x = s[t2[j].first][t2[j].second + 1];
		}
		putchar(min_x);
		for (int j = 0; j < t2.size(); j++) {
			if(t2[j].first != n) if(s[t2[j].first + 1][t2[j].second] == min_x) vis[t2[j].first + 1][t2[j].second] = 1;
			if(t2[j].second != n) if(s[t2[j].first][t2[j].second + 1] == min_x) vis[t2[j].first][t2[j].second + 1] = 1;
		}
		t2.clear();
		for (it = t[i].begin(); it != t[i].end(); it++) {
			if(vis[it->first][it->second]) t2.push_back(make_pair(it->first, it->second));
		}
	}
	return 0;
}