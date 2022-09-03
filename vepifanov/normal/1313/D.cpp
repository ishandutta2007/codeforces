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
int k;
int was[100000];
int r;
set<int> now;
int res[200000][1 << 8];
bool wres[200000][1 << 8];
vector<pair<int, ii> > w;
vi prep[200000];

int build (int i) {
	if (i + 1 == sz (w)) re 0;
	for (auto y : now) prep[i].pb (y);
	int t = w[i].se.fi;
	int j = w[i].se.se;
	if (t == 0) {
		now.erase (j);
		build (i + 1);
	} else {
		now.insert (j);
		build (i + 1);
	}
	re 0;
}

int go (int i) {
	if (i + 1 == sz (w)) re 0;
	int mask = 0;
	for (auto y : prep[i]) mask = (mask << 1) ^ was[y];
	if (wres[i][mask]) re res[i][mask];
	wres[i][mask] = 1;
	int t = w[i].se.fi;
	int j = w[i].se.se;
	int cur = 0;
	if (t == 0) {
		int old = was[j];
		was[j] = 0;
		if (old) r--;
		cur = max (cur, go (i + 1) + int (r % 2 == 1) * (w[i + 1].fi - w[i].fi));
		if (old) r++;
		was[j] = old;
	} else {
		cur = max (cur, go (i + 1) + int (r % 2 == 1) * (w[i + 1].fi - w[i].fi));
		was[j] = 1;
		r++;
		cur = max (cur, go (i + 1) + int (r % 2 == 1) * (w[i + 1].fi - w[i].fi));
		was[j] = 0;
		r--;
	}
	re res[i][mask] = cur;
}

int main () {
	scanf ("%d%d%d", &m, &n, &k);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf ("%d%d", &a, &b);
		w.pb (mp (a, mp (1, i)));
		w.pb (mp (b + 1, mp (0, i)));
	}
	sort (all (w));
	build (0);
	r = 0;
	printf ("%d\n", go (0));
	re 0;
}