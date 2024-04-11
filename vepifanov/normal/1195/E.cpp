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
int a, b;
int w[3000][3000];
int g, x, y, z;

int main () {
	scanf ("%d%d%d%d", &n, &m, &a, &b);
	scanf ("%d%d%d%d", &g, &x, &y, &z);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			w[i][j] = g;
			g = ((ll)g * x + y) % z;
		}
	int ta = 1, tb = 1;
	while (2 * ta < a) {
		for (int i = 0; i + ta < n; i++)
			for (int j = 0; j < m; j++)
				w[i][j] = min (w[i][j], w[i + ta][j]);
		ta *= 2;
	}
	while (2 * tb < b) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j + tb < m; j++)
				w[i][j] = min (w[i][j], w[i][j + tb]);
		tb *= 2;
	}
	ll ans = 0;
	for (int i = 0; i + a <= n; i++)
		for (int j = 0; j + b <= m; j++) {
			int ii = i + a - ta;
			int jj = j + b - tb;
			ans += min (min (w[i][j], w[ii][j]), min (w[i][jj], w[ii][jj]));
		}
	printf ("%lld\n", ans);	
	re 0;
}