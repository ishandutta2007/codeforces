#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define makeunique(x) sort(all(x)), (x).resize(unique(all(x)) - (x).begin())
#define re return
#define y0 y2415
#define y1 y346246
#define j0 j23562456
#define j1 j245623456
#define sqrt(x) sqrt (abs (x))

typedef unsigned long long ull;
typedef long long ll;
typedef double D;
typedef long double ld;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;
typedef vector <vi> vvi;
typedef vector <string> vs;

template <class T> T gcd (T a, T b) { re a ? gcd (b % a, a) : b; }
template <class T> T abs (T x) { re x > 0 ? x : -x; }
template <class T> T sqr (T x) { re x * x; }
template <class T> int sgn (T x) { re x > 0 ? 1 : (x < 0 ? -1 : 0); }

const ld pi = acos (-1.0);

const int N = 100100;

int n;
int m;
vi v[N];
vi w[N];
vi vert[N];
int was[N];
int col[N];
int cnt[N];
int ea[N];
int eb[N];
int ec[N];
int p[2];
vi q[2];
int bip[N];

int go (int x, int r) {
	if (was[x]) re 0;
	was[x] = 1;
	col[x] = r;
	cnt[r]++;
	vert[r].pb (x);
	for (int i = 0; i < sz (v[x]); i++) go (v[x][i], r);
	re 0;
}

int go2 (int x, int c) {
	if (was[x]) re int (bip[x] != c);
	bip[x] = c;
	was[x] = 1;
	p[c] += cnt[x];
	q[c].pb (x);
	for (int i = 0; i < sz (w[x]); i++)
		if (go2 (w[x][i], c ^ 1))
			re 1;
	re 0;
}

pair<int, vi> calc (int c) {
	memset (was, 0, sizeof (was));
	for (int i = 0; i < n; i++) v[i].clear ();
	for (int i = 0; i < m; i++)
		if (ec[i] == c) {
			v[ea[i]].pb (eb[i]);
			v[eb[i]].pb (ea[i]);
		}
	int r = 0;	
	for (int i = 0; i < n; i++)
		if (!was[i]) {
			vert[r].clear ();
			cnt[r] = 0;
			go (i, r);
			w[r].clear ();
			r++;
		}
	vi ans;
	for (int i = 0; i < m; i++)
		if (ec[i] != c) {
			int a = col[ea[i]];
			int b = col[eb[i]];
			if (a == b) re mp (1e9, ans);
			w[a].pb (b);
			w[b].pb (a);
		}
	memset (was, 0, sizeof (was));	
	for (int i = 0; i < r; i++)
		if (!was[i]) {
			p[0] = p[1] = 0;
			q[0].clear ();
			q[1].clear ();
			if (go2 (i, 0)) re mp (1e9, ans);
			int t = p[0] < p[1] ? 0 : 1;
			for (int j = 0; j < sz (q[t]); j++)
				for (int k = 0; k < sz (vert[q[t][j]]); k++)
					ans.pb (vert[q[t][j]][k]);
		}
	re mp (sz (ans), ans);
}

int main()
{
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		char h[5];
		scanf ("%d%d %s", &ea[i], &eb[i], h);
		ea[i]--;
		eb[i]--;
		ec[i] = int (h[0] == 'B');
	}	
	pair<int, vi> ans = min (calc (0), calc (1));
	if (ans.fi > 1e8) printf ("-1\n"); else {
		sort (all (ans.se));
		printf ("%d\n", ans.fi);
		for (int i = 0; i < ans.fi; i++) printf ("%d ", ans.se[i] + 1);
		printf ("\n");
	}
	return 0;
}