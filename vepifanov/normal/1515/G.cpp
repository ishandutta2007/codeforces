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
vii w[200000];
vi v[200000];
vi rv[200000];
vi q;
int was[200000];
int col[200000];
int ea[200000];
int eb[200000];
int ec[200000];
ll sum[200000];
ll cur[200000];
int p[200000];

int go (int x) {
	if (was[x]) re 0;
	was[x] = 1;
	for (auto y : v[x]) go (y);
	q.pb (x);
	re 0;
}

int go2 (int x, int c) {
	if (was[x]) re 0;
	was[x] = 1;
	col[x] = c;
	for (auto y : rv[x]) go2 (y, c);
	re 0;
}

int go3 (int x, ll now) {
	sum[x] = now;
	was[x] = 1;
	for (auto& y : w[x])
		if (col[y.fi] == col[x]) {
			if (was[y.fi] == 1) {
				cur[col[x]] = gcd (cur[col[x]], now + y.se - sum[y.fi]);
//				printf ("%d - %d: %d %lld = %lld\n", x + 1, y.fi + 1, col[x] + 1, now + y.se - sum[y.fi], cur[col[x]]);
			} else
			if (!was[y.fi]) go3 (y.fi, now + y.se);
		}
	was[x] = 2;
	re 0;
}

int main () {
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf ("%d%d%d", &a, &b, &c); a--; b--;
		v[a].pb (b);
		rv[b].pb (a);
		w[a].pb (mp (b, c));
		w[b].pb (mp (a, -c));
		ea[i] = a;
		eb[i] = b;
		ec[i] = c;
	}
	for (int i = 0; i < n; i++) go (i);
	memset (was, 0, sizeof (was));
	reverse (all (q));
	int r = 0;
	for (int i = 0; i < n; i++)
		if (!was[q[i]]) {
			p[r] = q[i];
			go2 (q[i], r);
			r++;
		}
	memset (was, 0, sizeof (was));
	for (int i = 0; i < r; i++) {
		cur[i] = 0;
		go3 (p[i], 0);
	}
	int q;
	scanf ("%d", &q);
	for (int i = 0; i < q; i++) {
		int a, b, c;
		scanf ("%d%d%d", &a, &b, &c); a--;
//		printf ("%d %lld %d %lld\n", c - b, cur[col[a]], c, gcd (cur[col[a]], (ll)c));
		if (((c - b) % c) % gcd (cur[col[a]], (ll)c) != 0) printf ("NO\n"); else printf ("YES\n");
	}
	re 0;
}