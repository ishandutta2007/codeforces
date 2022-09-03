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

const int N = 100000;

int n;
int m;

ll res[3 * N];

vii v[N];
ll d[N];
int dp[N];
vector<pair<ll, ii> > w;
ii seg[2][3 * N];
vi qi[2][3 * N];
int p[N];
int k, q;
set<pair<ll, int> > all;
int qa[3 * N];
int qb[3 * N];

int gp (int x) {
	if (p[x] != x) p[x] = gp (p[x]);
	re p[x];
}

int main () {
	scanf ("%d%d%d%d", &n, &m, &k, &q);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf ("%d%d%d", &a, &b, &c); a--; b--;
		v[a].pb (mp (b, c));
		v[b].pb (mp (a, c));
	}
	for (int i = 0; i < n; i++) d[i] = 1e18;
	for (int i = 0; i < k; i++) {
		d[i] = 0;
		dp[i] = i;
		all.insert (mp (0, i));
	}
	while (!all.empty ()) {
		auto st = *all.begin ();
		all.erase (all.begin ());
		int x = st.se;
		for (auto& y : v[x])
			if (d[y.fi] > d[x] + y.se) {
				all.erase (mp (d[y.fi], y.fi));
				d[y.fi] = d[x] + y.se;
				dp[y.fi] = dp[x];
				all.insert (mp (d[y.fi], y.fi));
			}
	}
	for (int i = 0; i < n; i++)
		for (auto& y : v[i])
			if (dp[i] != dp[y.fi] && dp[i] < dp[y.fi])
				w.pb (mp (d[i] + d[y.fi] + y.se, mp (dp[i], dp[y.fi])));
	sort (all (w));
	for (int i = 0; i < q; i++) {
		scanf ("%d%d", &qa[i], &qb[i]); qa[i]--; qb[i]--;
		seg[0][sz (w) / 2] = mp (0, sz (w));
		qi[0][sz (w) / 2].pb (i);
	}
	for (int t = 0; t < 20; t++) {
		int ct = t & 1;
		int nt = 1 - ct;
		for (int i = 0; i < n; i++) p[i] = i;
		for (int i = 0; i < sz (w); i++) qi[nt][i].clear ();
		for (int i = 0; i < sz (w); i++) {
			if (!qi[ct][i].empty ()) {
				auto& lr = seg[ct][i];
				if (lr.fi + 1 == lr.se) {
					for (auto id : qi[ct][i]) {
						res[id] = w[lr.se - 1].fi;
					}
	        	} else {
					for (auto id : qi[ct][i]) {
						int a = gp (qa[id]); 
						int b = gp (qb[id]);
						if (a != b) {
							seg[nt][(i + lr.se) / 2] = mp (i, lr.se);
							qi[nt][(i + lr.se) / 2].pb (id);
						} else {
							seg[nt][(lr.fi + i) / 2] = mp (lr.fi, i);
							qi[nt][(lr.fi + i) / 2].pb (id);
						}
					}
	        	}
			}
			int a = gp (w[i].se.fi); 
			int b = gp (w[i].se.se); 
			if (a != b) {
				if (rand () & 1) swap (a, b);
				p[a] = b;
			}
		}
	}
	for (int i = 0; i < q; i++) printf ("%lld\n", res[i]);
	re 0;
}