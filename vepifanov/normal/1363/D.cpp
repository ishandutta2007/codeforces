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
vi v[1001];
int was[1001];
int p[1001];
int res[1001];

int ask (int l, int r, bool inv = false) {
	vi w;
	for (int i = 0; i < m; i++)
		if ((i >= l && i <= r) != inv)
			w.insert (w.end (), v[i].begin (), v[i].end ());
	printf ("? %d", sz (w));
	for (int i = 0; i < sz (w); i++) printf (" %d", w[i] + 1);
	printf ("\n");
	fflush (stdout);
	int x;
	scanf ("%d", &x);
	re x;
}

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf ("%d%d", &n, &m);
		int mm = m;
		for (int i = 0; i < n; i++) was[i] = 0;
		for (int i = 0; i < m; i++) {
			scanf ("%d", &p[i]);
			v[i].resize (p[i]);
			for (int j = 0; j < p[i]; j++) {
				scanf ("%d", &v[i][j]); v[i][j]--;
				was[v[i][j]] = 1;
			}
		}
		v[m].clear ();
		for (int i = 0; i < n; i++)
			if (!was[i])
				v[m].pb (i);
		if (!v[m].empty ()) m++;
		int l = 0, r = m - 1;
		for (int i = 0; i < m; i++) res[i] = 0;
		int tot = ask (0, m - 1);
		while (true) {
			if (l == r) {
				res[l] = ask (l, l, true);
				break;
			}
			int s = (l + r) / 2;
			int tmp = ask (l, s);
			if (tmp == tot) {
				for (int i = s + 1; i <= r; i++) res[i] = tot;
				r = s;
			} else {
				for (int i = l; i <= s; i++) res[i] = tot;
				l = s + 1;
			}
		}
		printf ("!");
		for (int i = 0; i < mm; i++) printf (" %d", res[i]);
		printf ("\n");
		fflush (stdout);
		char h[20];
		scanf ("%s", h);
	}
	re 0;
}