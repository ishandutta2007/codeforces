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
int q;
int g[1001][1001][2];

ll go (int f, int t, ll x1, ll y1, ll x2, ll y2) {
	if (x1 >= x2 || y1 >= y2 || x2 < 0 || y2 < 0) re 0;
	if (t == -1) re g[x1][y1][f] - g[x2][y1][f] - g[x1][y2][f] + g[x2][y2][f];
	ll nn = (ll)n << t;
	ll mm = (ll)m << t;
	if (x1 == 0 && x2 == 2 * nn) re (ll)(x2 - x1) * (y2 - y1) / 2;
	if (y1 == 0 && y2 == 2 * mm) re (ll)(x2 - x1) * (y2 - y1) / 2;
//	printf ("%d %d %lld %lld %lld %lld | %lld %lld\n", f, t, x1, y1, x2, y2, 2 * nn, 2 * mm);
	re go (f, t - 1, x1, y1, min (x2, nn), min (y2, mm)) + 
       go (f ^ 1, t - 1, max (0LL, x1 - nn), y1, x2 - nn, min (y2, mm)) + 
       go (f ^ 1, t - 1, x1, max (0LL, y1 - mm), min (x2, nn), y2 - mm) + 
       go (f, t - 1, max (0LL, x1 - nn), max (0LL, y1 - mm), x2 - nn, y2 - mm);
}

int main () {
	scanf ("%d%d%d", &n, &m, &q);
	for (int i = 0; i < n; i++) {
		char h[1001];
		scanf ("%s", h);
		for (int j = 0; j < m; j++) {
			g[i][j][0] = h[j] - '0';
			g[i][j][1] = g[i][j][0] ^ 1;
		}
	}	
	for (int i = n - 1; i >= 0; i--)
		for (int j = m - 1; j >= 0; j--)
			for (int t = 0; t < 2; t++)
				g[i][j][t] += g[i + 1][j][t] + g[i][j + 1][t] - g[i + 1][j + 1][t];
	for (int i = 0; i < q; i++) {
		int x1, y1, x2, y2;
		scanf ("%d%d%d%d", &x1, &y1, &x2, &y2); x1--; y1--;
		printf ("%lld\n", go (0, 29, x1, y1, x2, y2));
	}
	re 0;
}