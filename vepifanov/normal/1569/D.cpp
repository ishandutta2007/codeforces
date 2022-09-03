#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
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
map<int, int> ax;
map<int, int> ay;
int sx[200000];
int sy[200000];
ii v[300000];
map<ii, int> sum;
int px[400001];
int py[400001];

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf ("%d%d%d", &n, &m, &k);
		ax.clear ();
		ay.clear ();
		sum.clear ();
		for (int i = 0; i < n; i++) {
			scanf ("%d", &sx[i]);
			ax[sx[i]] = 2 * i;
		}
		for (int i = 0; i < m; i++) {
			scanf ("%d", &sy[i]);
			ay[sy[i]] = 2 * i;
		}
		for (int i = 0; i <= 2 * n; i++) px[i] = 0;
		for (int i = 0; i <= 2 * m; i++) py[i] = 0;
		ll ans = 0;
		for (int i = 0; i < k; i++) {
			int x, y;
		    scanf ("%d%d", &x, &y);
//		    printf ("%d %d = ", x, y);
		    if (ax.count (x)) x = ax[x]; else x = (lower_bound (sx, sx + n, x) - sx) * 2 - 1;
		    if (ay.count (y)) y = ay[y]; else y = (lower_bound (sy, sy + m, y) - sy) * 2 - 1;
		    if (x & 1) ans += px[x] - sum[mp (x, y)];
		    if (y & 1) ans += py[y] - sum[mp (x, y)];
		    px[x]++;
		    py[y]++;
		    sum[mp (x, y)]++;
//		    printf ("%lld\n", ans);
		}
		printf ("%lld\n", ans);
	}
    re 0;
}