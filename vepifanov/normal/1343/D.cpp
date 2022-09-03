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
int x[200000];
int d[400010];

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf ("%d%d", &n, &m);
		for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
		for (int i = 1; i <= 2 * m; i++) d[i] = 0;
		for (int i = 0; i < n / 2; i++) {
			int a = min (x[i], x[n - i - 1]);
			int b = max (x[i], x[n - i - 1]);
			d[1] += 2;
			d[a + 1]--;
			d[a + b]--;
			d[a + b + 1]++;
			d[b + m + 1]++;
		}
		int cur = 0, ans = 1e9;
		for (int i = 1; i <= 2 * m; i++) {
			cur += d[i];
			ans = min (ans, cur);
		}
		printf ("%d\n", ans);
	}
	re 0;
}