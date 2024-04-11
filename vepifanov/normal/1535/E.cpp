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

const int N = 300010;

int n;
int m;
int a[N];
int c[N];
int par[N][20];

int up (int x) {
	for (int j = 19; j >= 0; j--)
		if (a[par[x][j]] > 0)
			x = par[x][j];
	re x;			
}

int main () {
	scanf ("%d%d%d", &n, &a[0], &c[0]);
	for (int i = 0; i < 20; i++) par[0][i] = 0;
	for (int i = 1; i <= n; i++) {
		int t;
		scanf ("%d", &t);
		if (t == 1) {
			scanf ("%d%d%d", &par[i][0], &a[i], &c[i]);
			for (int j = 1; j < 20; j++) par[i][j] = par[par[i][j - 1]][j - 1];
		} else {
			int x, y;
			int tot = 0;
			ll ans = 0;
			scanf ("%d%d", &x, &y);
			while (y > 0 && a[x] > 0) {
				int z = up (x);
				int tmp = min (a[z], y);
				tot += tmp;
				ans += (ll)tmp * c[z];
				a[z] -= tmp;
				y -= tmp;
			}
			printf ("%d %lld\n", tot, ans);
			fflush (stdout);
		}
	}
	re 0;
}