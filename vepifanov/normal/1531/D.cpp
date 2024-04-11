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
char h[10];
string col[100010];
int now[100010];
int tot[1 << 18];
int same[1 << 18];
ii tree[1 << 18];
ii tans[1 << 18];
set<int> intr;

void build (int x, int l, int r) {
	same[x] = 0;
	if (l == r) {
		tree[x] = mp (now[l], l);
		tans[x] = mp (1e9 * int (col[l] == "lock" || col[l] == "unlock") + now[l], -l);
		re;
	}
	int s = (l + r) / 2;
	build (x * 2 + 1, l, s);
	build (x * 2 + 2, s + 1, r);
	tree[x] = min (tree[x * 2 + 1], tree[x * 2 + 2]);
	tans[x] = min (tans[x * 2 + 1], tans[x * 2 + 2]);
}

void add (int x, int l, int r, int lc, int rc, int d) {	
	if (r < lc || l > rc) re;
	if (l >= lc && r <= rc) {
		same[x] += d;
		re;
	}
	int s = (l + r) / 2;
	add (x * 2 + 1, l, s, lc, rc, d);
	add (x * 2 + 2, s + 1, r, lc, rc, d);
	tree[x] = min (mp (tree[x * 2 + 1].fi + same[x * 2 + 1], tree[x * 2 + 1].se), mp (tree[x * 2 + 2].fi + same[x * 2 + 2], tree[x * 2 + 2].se));
	tans[x] = min (mp (tans[x * 2 + 1].fi + same[x * 2 + 1], tans[x * 2 + 1].se), mp (tans[x * 2 + 2].fi + same[x * 2 + 2], tans[x * 2 + 2].se));
}

void upd (int x, int l, int r, int y) {	
	if (r < y || l > y) re;
	if (l == r) {
		tans[x] = mp (1e9 * int (col[l] == "lock" || col[l] == "unlock") + now[l], -l);
		re;
	}
	int s = (l + r) / 2;
	upd (x * 2 + 1, l, s, y);
	upd (x * 2 + 2, s + 1, r, y);
	tans[x] = min (mp (tans[x * 2 + 1].fi + same[x * 2 + 1], tans[x * 2 + 1].se), mp (tans[x * 2 + 2].fi + same[x * 2 + 2], tans[x * 2 + 2].se));
}

void addlock (int x) {
	auto pr = intr.lower_bound (x);
	pr--;
	if (*pr < 0 || col[*pr] == "unlock") {
		auto nx = intr.lower_bound (x);
		add (0, 0, n, x, *nx - 1, 1);
	}
	intr.insert (x);
}

void dellock (int x) {
	intr.erase (x);
	auto pr = intr.lower_bound (x);
	pr--;
	if (*pr < 0 || col[*pr] == "unlock") {
		auto nx = intr.lower_bound (x);
		add (0, 0, n, x, *nx - 1, -1);
	}
}

void addunlock (int x) {
	auto pr = intr.lower_bound (x);
	pr--;
	if (*pr >= 0 && col[*pr] == "lock") {
		auto nx = intr.lower_bound (x);
		add (0, 0, n, x, *nx - 1, -1);
	}
	intr.insert (x);
}

void delunlock (int x) {
	intr.erase (x);
	auto pr = intr.lower_bound (x);
	pr--;
	if (*pr >= 0 && col[*pr] == "lock") {
		auto nx = intr.lower_bound (x);
		add (0, 0, n, x, *nx - 1, 1);
	}
}

int main () {
	scanf ("%d", &n);
	int cur = 0;
	now[0] = 0;
	col[0] = "blue";
	intr.insert (-1);
	intr.insert (n + 1);
	for (int i = 1; i <= n; i++) {
		scanf (" %s", h);
		if (h[0] == 'l') { intr.insert (i); cur = 1; }
		if (h[0] == 'u') { intr.insert (i); cur = 0; }
		now[i] = cur;
		col[i] = string (h);
	}
	build (0, 0, n);
	printf ("%s\n", col[-tans[0].se].c_str ());
	scanf ("%d", &m);
	for (int i = 0; i < m; i++) {
		int x;
		scanf ("%d %s", &x, h);
		// printf ("%d %s %s\n", x, col[x].c_str (), h);
		if (col[x][0] == 'l') dellock (x);
		if (col[x][0] == 'u') delunlock (x);
		if (h[0] == 'l') addlock (x);
		if (h[0] == 'u') addunlock (x);
		col[x] = string (h);
		upd (0, 0, n, x);
		printf ("%s\n", col[-tans[0].se].c_str ());
	}
	re 0;
}