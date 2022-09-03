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
vi v[200000];
int p[200000];
ll sum[200001];
int d[3][200000];
int q[200000];
int was[200000];

int bfs (int t, int st) {
	for (int i = 0; i < n; i++) was[i] = 0;
	was[st] = 1;
	int l = 0, r = 0;
	q[r++] = st;
	d[t][st] = 0;
	while (l < r) {
		int x = q[l++];
//		printf ("%d %d %d = %d\n", t, st, x, d[t][x]);
		for (auto y : v[x])
			if (!was[y]) {
				q[r++] = y;
				was[y] = 1;
				d[t][y] = d[t][x] + 1;
			}
	}
	re 0;
}

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		int a, b, c;
		scanf ("%d%d%d%d%d", &n, &m, &a, &b, &c); a--; b--; c--;
		for (int i = 0; i < n; i++) v[i].clear ();
		for (int i = 0; i < m; i++) scanf ("%d", &p[i]);
		sort (p, p + m);
		sum[m] = 0;
		for (int i = m - 1; i >= 0; i--) sum[i] = sum[i + 1] + p[i];
		for (int i = 0; i < m; i++) {
			int x, y;
			scanf ("%d%d", &x, &y); x--; y--;
			v[x].pb (y);
			v[y].pb (x);
		}
		bfs (0, a);
		bfs (1, b);
		bfs (2, c);
		ll ans = 1e18;
		for (int i = 0; i < n; i++) {
			int one = d[0][i] + d[2][i];
			int two = d[1][i];
			if (one + two > m) continue;
//			printf ("%d = %d %d %d | %d %d | %lld %lld\n", i, d[0][i], d[1][i], d[2][i], one, two, sum[0] - sum[two], sum[two] - sum[two + one]);
			ll cur = (sum[0] - sum[two]) * 2 + (sum[two] - sum[two + one]);
			ans = min (ans, cur);
		}
		printf ("%lld\n", ans);
	}
	re 0;
}