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
int c;
int q;
set<int> pos[N];
set<int> now[N];
map<int, int> out[N];
int p[N];

int gp (int x) {
	if (p[x] != x) p[x] = gp (p[x]);
	re p[x];
}

void merge (int a, int b) {
	a = gp (a);
	b = gp (b);
	if (a == b) re;
	if (sz (now[a]) > sz (now[b])) swap (a, b);
	p[a] = b;
	for (auto x : now[a]) {
		pos[x].erase (a);
		pos[x].insert (b);
		now[b].insert (x);
	}
	now[a].clear ();
}

void add (int a, int b, int c) {
	pos[a].insert (gp (b));
	now[gp (b)].insert (a);
	if (out[a].find (c) == out[a].end ()) out[a][c] = b; else {
		int x = out[a][c];
		merge (x, b);
	}
}

int main () {
	scanf ("%d%d%d%d", &n, &m, &c, &q);
	for (int i = 0; i < n; i++) p[i] = i;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf ("%d%d%d", &a, &b, &c); a--; b--; c--;
		add (a, b, c);
		add (b, a, c);
	}
	for (int i = 0; i < q; i++) {
		char h[5];
		int x, y, z;
		scanf (" %s%d%d", h, &x, &y); x--; y--;
		if (h[0] == '?') {
			if (gp (x) == gp (y) || pos[y].count (gp (x))) printf ("Yes\n"); else printf ("No\n");
		} else {
			scanf ("%d", &z); z--;
			add (x, y, z);
			add (y, x, z);
		}
	}
	re 0;
}