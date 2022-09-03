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

const int N = 2*1000*1000;

int n;
int m;
int p;
int f;
int was[N];
vi v[N];
vi rv[N];
int col[N];
vi q;
int res[N];

int go (int x) {
	was[x] = 1;
	for (auto y : v[x])
		if (!was[y])
			go (y);
	q.pb (x);
	re 0;
}

int go2 (int x, int c) {
	col[x] = c;
	was[x] = 1;
	for (auto y : rv[x])
		if (!was[y])
			go2 (y, c);
	re 0;
}

int main () {
	scanf ("%d%d%d%d", &n, &p, &f, &m);
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf ("%d%d", &x, &y); x--; y--;
		v[2 * x].pb (2 * y + 1);
		v[2 * y].pb (2 * x + 1);
	}
	for (int i = 0; i <= f + 1; i++) {
		if (i > 0) v[2 * p + 2 * i + 1].pb (2 * p + 2 * i - 1);
		if (i <= f) v[2 * p + 2 * i].pb (2 * p + 2 * i + 2);
	}
	for (int i = 0; i < p; i++) {
		int l, r;
		scanf ("%d%d", &l, &r);
		v[2 * p + 2 * l].pb (2 * i);
		v[2 * i + 1].pb (2 * p + 2 * l + 1);
		v[2 * p + 2 * (r + 1) + 1].pb (2 * i);
		v[2 * i + 1].pb (2 * p + 2 * (r + 1));
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf ("%d%d", &x, &y); x--; y--;
		v[2 * x + 1].pb (2 * y);
		v[2 * y + 1].pb (2 * x);
	}
	for (int i = 0; i < 2 * p + 2 * (f + 2); i++)
		if (!was[i])
			go (i);
	reverse (all (q));
	memset (was, 0, sizeof (was));
	for (int i = 0; i < 2 * p + 2 * (f + 2); i++)
		for (auto j : v[i]) {
//			printf ("%d -> %d\n", i, j);
			rv[j].pb (i);
		}
	int r = 0;
	for (int i = 0; i < sz (q); i++)
		if (!was[q[i]]) {
			go2 (q[i], r);
			r++;
		}	
	for (int i = 0; i < p + f + 2; i++)
		if (col[2 * i] == col[2 * i + 1]) {
			printf ("-1\n");
			re 0;
		} else res[i] = int (col[2 * i + 1] > col[2 * i]);
//	for (int i = 0; i < 2 * (p + f + 2); i++) printf ("%d = %d\n", i, col[i]);
	int cnt = 0, sig = 0;
	for (int i = 1; i <= f; i++)
		if (res[p + i] && !res[p + i + 1])
			sig = i;
	for (int i = 0; i < p; i++)
		if (res[i])
			cnt++;
	printf ("%d %d\n", cnt, sig);
	for (int i = 0; i < p; i++)
		if (res[i])
			printf ("%d ", i + 1);
	printf ("\n");
	re 0;
}