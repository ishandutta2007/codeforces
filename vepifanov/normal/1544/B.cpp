#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
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
vii v;
int was[3][100][3];
int res[3][100][3];
vi w[100];
string ans[20];

int cool (ii a, ii b) {
	re int (abs (a.fi - b.fi) <= 1 && abs (a.se - b.se) <= 1);
}

int go (int st, int i, int mask) {
	if (i == sz (v)) {
		if ((mask & 1) && st) re -1e9;
		re 0;
	}
	if (was[st][i][mask]) re res[st][i][mask];
	was[st][i][mask] = 1;
	int cur = go (st, i + 1, (mask & 1) << 1);
	int ok = 1;
	for (int j = 0; j < sz (w[i]); j++)
		if ((mask >> w[i][j]) & 1)
			ok = 0;
	if (ok) cur = max (cur, go (st, i + 1, ((mask & 1) << 1) ^ 1) + 1);
	re res[st][i][mask] = cur;
}

int out (int st, int i, int mask) {
	if (i == sz (v)) re 0;
	if (res[st][i][mask] == go (st, i + 1, (mask & 1) << 1)) {
		out (st, i + 1, (mask & 1) << 1);
		re 0;
	}
	out (st, i + 1, ((mask & 1) << 1) ^ 1);
	ans[v[i].fi][v[i].se] = '1';
	re 0;
}

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf ("%d%d", &n, &m);
		memset (was, 0, sizeof (was));
		v.clear ();
		for (int i = 0; i < m; i++) v.pb (mp (0, i));
		for (int i = 1; i + 1 < n; i++) v.pb (mp (i, m - 1));
		for (int i = m - 1; i >= 0; i--) v.pb (mp (n - 1, i));
		for (int i = n - 2; i > 0; i--) v.pb (mp (i, 0));
		for (int i = 0; i < sz (v); i++) {
			w[i].clear ();
			for (int j = 0; j < i; j++)
				if (cool (v[i], v[j]))
					w[i].pb (i - j - 1);
		}
		pair<int, int> best (-1, 0);
		best = max (best, mp (go (0, 2, 0), 0));
		best = max (best, mp (go (1, 2, 1) + 1, 1));
		best = max (best, mp (go (2, 2, 2) + 1, 2));
		for (int i = 0; i < n; i++) ans[i] = string (m, '0');
		out (best.se, 2, best.se);
		if (best.se == 1) ans[v[1].fi][v[1].se] = '1';
		if (best.se == 2) ans[v[0].fi][v[0].se] = '1';
		if (it > 0) cout << endl;
		for (int i = 0; i < n; i++) cout << ans[i] << endl;
	}
    re 0;
}