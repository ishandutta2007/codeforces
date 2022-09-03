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
ii tree[1 << 21];
ii same[1 << 21];
vii v[300000];
int res[300000];
int prev[300000];
int was[300000];
vi x;
map<int, int> num;

ii get (int x, int l, int r, int lc, int rc) {
	if (r < lc || l > rc) re mp (-1, -1);
	if (l >= lc && r <= rc) re max (tree[x], same[x]);
	int s = (l + r) / 2;
	re max (same[x], max (get (x * 2 + 1, l, s, lc, rc), get (x * 2 + 2, s + 1, r, lc, rc)));
}

ii add (int x, int l, int r, int lc, int rc, ii y) {
	if (r < lc || l > rc) re max (tree[x], same[x]);
	if (l >= lc && r <= rc) {
		same[x] = max (same[x], y);
		re max (tree[x], same[x]);
	}
	int s = (l + r) / 2;
	tree[x] = max (add (x * 2 + 1, l, s, lc, rc, y), add (x * 2 + 2, s + 1, r, lc, rc, y));
	re max (same[x], tree[x]);
}

int main () {
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf ("%d%d%d", &a, &b, &c); a--;
		v[a].pb (mp (b, c + 1));
		x.pb (b);
		x.pb (c + 1);
	}
	sort (all (x));
	x.resize (unique (all (x)) - x.begin ());
	for (int i = 0; i < sz (x); i++) num[x[i]] = i;
	ii ans (0, -1);
	for (int i = 0; i < n; i++) {
		ii cur (0, -1);
		for (auto& w : v[i]) {
			int l = num[w.fi];
			int r = num[w.se] - 1;
			cur = max (cur, get (0, 0, sz (x) - 1, l, r));
		}
		cur.fi++;
		res[i] = cur.fi;
		prev[i] = cur.se;
		ans = max (ans, mp (cur.fi, i));
		for (auto& w : v[i]) {
			int l = num[w.fi];
			int r = num[w.se] - 1;
			add (0, 0, sz (x) - 1, l, r, mp (cur.fi, i));
		}

	}
	printf ("%d\n", n - ans.fi);
	int i = ans.se;
	while (true) {
		was[i] = 1;
		if (res[i] == 1) break;
		i = prev[i];
	}
	if (ans.fi < n) {
		for (int i = 0; i < n; i++) 
			if (!was[i])
				printf ("%d ", i + 1);
		printf ("\n");
	}
    re 0;
}