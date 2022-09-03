#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin (),(x).end()
#define sqrt(x) sqrt(abs(x))
#define re return
#define sz(x) ((int)(x).size ())
#define prev PREV
#define next NEXT

using ll = long long;
using ii = pair<int, int>;
using ld = long double;
using D = double;
using vi = vector<int>;
using vii = vector<ii>;
using vvi = vector<vi>;
using vs = vector<string>;

template<typename T> T abs (T x) { re x < 0 ? -x : x; }
template<typename T> T sgn (T x) { re x < 0 ? -1 : (x > 0 ? 1 : 0); }
template<typename T> T sqr (T x) { re x * x; }
template<typename T> T gcd (T a, T b) { re a ? gcd (b % a, a) : b; }

int n;
int m;
int k;

set<int> ax[100010];
set<int> ay[100010];

int main () {
	scanf ("%d%d%d", &n, &m, &k);
	for (int i = 0; i < k; i++) {
		int x, y;
		scanf ("%d%d", &x, &y);
		ax[x].insert (y);
		ay[y].insert (x);
	}
	for (int i = 1; i <= n; i++) {
		ax[i].insert (0);
		ax[i].insert (m + 1);
	}
	for (int i = 1; i <= m; i++) {
		ay[i].insert (0);
		ay[i].insert (n + 1);
	}
	int cx = 1, cy = 1, x1 = 1, y1 = 1, x2 = n, y2 = m;
	ll len = 1;
//	printf ("%d %d %d %d = %d %d\n", x1, y1, x2, y2, cx, cy);
	while (true) {
		int nx, ny;
		{
			if (cx < x1 || cx > x2) break;
			auto it = ax[cx].lower_bound (cy);
			ny = min (*it - 1, y2);
			len += ny - cy;
			x1 = cx + 1;
			cy = ny;
		}
//		printf ("%d %d %d %d = %d %d\n", x1, y1, x2, y2, cx, cy);
		if (x1 > x2 || y1 > y2) break;
		{
			if (cy < y1 || cy > y2) break;
			auto it = ay[cy].lower_bound (cx);
			nx = min (*it - 1, x2);
			len += nx - cx;
			y2 = cy - 1;
			cx = nx;
		}
//		printf ("%d %d %d %d = %d %d\n", x1, y1, x2, y2, cx, cy);
		if (x1 > x2 || y1 > y2) break;
		{
			if (cx < x1 || cx > x2) break;
			auto it = ax[cx].lower_bound (cy);
			it--;
			ny = max (*it + 1, y1);
			len += cy - ny;
			x2 = cx - 1;
			cy = ny;
		}
//		printf ("%d %d %d %d = %d %d\n", x1, y1, x2, y2, cx, cy);
		if (x1 > x2 || y1 > y2) break;
		{
			if (cy < y1 || cy > y2) break;
			auto it = ay[cy].lower_bound (cx);
			it--;
			nx = max (*it + 1, x1);
			len += cx - nx;
			y1 = cy + 1;
			cx = nx;
		}
//		printf ("%d %d %d %d = %d %d\n", x1, y1, x2, y2, cx, cy);
		if (x1 > x2 || y1 > y2) break;
	}
	if (len == (ll)n * m - k) printf ("Yes\n"); else printf ("No\n");
	re 0;
}