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

const int inf = 2e9;
const int N = 100000;

int n;
int m;
int x1[N];
int y1[N];
int x2[N];
int y2[N];

int get (const set<int>& rem, vi& p, const vector<pair<ii, int> >& v, int x) {
	if (x >= sz (v)) re x;
	if (!rem.count (v[x].fi.se)) re x;
	re p[x] = get (rem, p, v, p[x]);
}

int go (const vi& v) {
//	printf ("%d\n", sz (v));
	if (sz (v) == 1) re 1;
	vector<pair<ii, int> > v1, v2, v3, v4;
	vi pv1 (sz (v)), pv2 (sz (v)), pv3 (sz (v)), pv4 (sz (v));
	for (int i = 0; i < sz (v); i++) {
//		printf ("%d %d %d %d\n", x1[v[i]], y1[v[i]], x2[v[i]], y2[v[i]]);
		v1.pb (mp (mp (x1[v[i]], v[i]), x2[v[i]]));
		v2.pb (mp (mp (y1[v[i]], v[i]), y2[v[i]]));
		v3.pb (mp (mp (-x2[v[i]], v[i]), -x1[v[i]]));
		v4.pb (mp (mp (-y2[v[i]], v[i]), -y1[v[i]]));
		pv1[i] = pv2[i] = pv3[i] = pv4[i] = i + 1;
	}
//	printf ("\n");
	sort (all (v1));
	sort (all (v2));
	sort (all (v3));
	sort (all (v4));
	set<int> rem;
	while (true) {
		int c1 = -inf;
		int c2 = -inf;
		int c3 = -inf;
		int c4 = -inf;
		int cnt = 0;
		vi w1, w2, w3, w4;
		int ok = 0;
		for (int i1 = 0, i2 = 0, i3 = 0, i4 = 0; ; ) {
//			printf ("%d %d %d %d | %d | %d %d %d\n", i1, i2, i3, i4, sz (rem), sz (v), sz (pv1), sz (v1));
			{
				while (i1 < sz (v) && rem.count (v1[i1].fi.se)) i1 = get (rem, pv1, v1, i1);
//				printf ("%d\n", i1);
				if (i1 == sz (v)) break;
				if (c1 != -inf && v1[i1].fi.fi >= c1) {
					if (!go (w1)) re 0;
					for (int i = 0; i < sz (w1); i++) rem.insert (w1[i]);
					ok = 1;
					break;
				}
				c1 = max (c1, v1[i1].se);
				w1.pb (v1[i1].fi.se);
				cnt++;
			}
			{
				while (i2 < sz (v) && rem.count (v2[i2].fi.se)) i2 = get (rem, pv2, v2, i2);
				if (c2 != -inf && v2[i2].fi.fi >= c2) {
					if (!go (w2)) re 0;
					for (int i = 0; i < sz (w2); i++) rem.insert (w2[i]);
					ok = 1;
					break;
				}
				c2 = max (c2, v2[i2].se);
				w2.pb (v2[i2].fi.se);
			}
			{
				while (i3 < sz (v) && rem.count (v3[i3].fi.se)) i3 = get (rem, pv3, v3, i3);
				if (c3 != -inf && v3[i3].fi.fi >= c3) {
					if (!go (w3)) re 0;
					for (int i = 0; i < sz (w3); i++) rem.insert (w3[i]);
					ok = 1;
					break;
				}
				c3 = max (c3, v3[i3].se);
				w3.pb (v3[i3].fi.se);
			}
			{
				while (i4 < sz (v) && rem.count (v4[i4].fi.se)) i4 = get (rem, pv4, v4, i4);
				if (c4 != -inf && v4[i4].fi.fi >= c4) {
					if (!go (w4)) re 0;
					for (int i = 0; i < sz (w4); i++) rem.insert (w4[i]);
					ok = 1;
					break;
				}
				c4 = max (c4, v4[i4].se);
				w4.pb (v4[i4].fi.se);
			}
			i1++; i2++; i3++; i4++;
		}
//		printf ("cool %d | %d\n", ok, cnt);
		if (ok) continue;
		if (cnt > 1) re 0;
		break;
	}
	re 1;
}

int main () {
	scanf ("%d", &n);
	vi v;
	for (int i = 0; i < n; i++) {
		scanf ("%d%d%d%d", &x1[i], &y1[i], &x2[i], &y2[i]);
		v.pb (i);
	}
	if (go (v)) printf ("YES\n"); else printf ("NO\n");
	re 0;
}