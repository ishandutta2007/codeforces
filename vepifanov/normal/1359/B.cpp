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
char h[1010];

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		int x, y;
		scanf ("%d%d%d%d", &n, &m, &x, &y);
		y = min (y, 2 * x);
		int ans = 0;
		for (int i = 0; i < n; i++) {
			scanf (" %s", h);
			for (int j = 0; j < m; ) {
				int k = j;
				while (k < m && h[k] == '.') k++;
				ans += (k - j) / 2 * y + (k - j) % 2 * x;
				j = k + 1;
			}
		}
		printf ("%d\n", ans);
	}
	re 0;
}