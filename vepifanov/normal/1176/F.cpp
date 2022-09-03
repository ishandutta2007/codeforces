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
vi v[4];
ll res[10];
ll nres[10];
vii w;
int was[5];

int gen (int cur, int nt, ll now) {
	if (nt >= 10) nt -= 10;
	if (nres[nt] < now) nres[nt] = now;
	nt++;
	for (int j = 0; j < sz (w); j++)
		if (!was[j] && cur + w[j].se <= 3) {
			was[j] = 1;
			gen (cur + w[j].se, nt, now + (1 + int (nt == 10)) * w[j].fi);
			was[j] = 0;
		}
	re 0;	
}

int main () {
	scanf ("%d", &n);
	memset (res, 0, sizeof (res));
	for (int i = 1; i < 10; i++) res[i] = -1e18;
	for (int i = 0; i < n; i++) {
		scanf ("%d", &m);
		v[1].clear ();
		v[2].clear ();
		v[3].clear ();
		for (int j = 0; j < m; j++) {
			int a, b;
			scanf ("%d%d", &a, &b);
			v[a].pb (b);
		}
		w.clear ();
		for (int t = 1; t <= 3; t++) {
			sort (all (v[t]));
			reverse (all (v[t]));
			for (int j = 0; j < sz (v[t]) && t * (j + 1) <= 3; j++) w.pb (mp (v[t][j], t));
		}
		sort (all (w));
		for (int t = 0; t < 10; t++) nres[t] = -1e18;
		memset (was, 0, sizeof (was));
		for (int t = 0; t < 10; t++) gen (0, t, res[t]);
/*		do {
			for (int t = 0; t < 10; t++) {
				int cur = 0, nt = t;
				ll now = res[t];
				for (int j = 0; j < sz (w); j++) {
					cur += w[j].se;
					if (cur > 3) break;
					now += w[j].fi;
					nt++;
					if (nt == 10) now += w[j].fi;
					if (nt >= 10) nt -= 10;
					nres[nt] = max (nres[nt], now);
				}
			}
		} while (next_permutation (all (w)));*/
		for (int t = 0; t < 10; t++) res[t] = nres[t];
	}
	ll ans = 0;
	for (int i = 0; i < 10; i++) ans = max (ans, res[i]);
	printf ("%lld\n", ans);
	re 0;
}