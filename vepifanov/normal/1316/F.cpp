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

const int N = 300000;
const int mod = 1000*1000*1000+7;
const int rev2 = (mod + 1) / 2;

int n;
int m;

map<ii, int> pos;
vii v;
ii p[N];
int t[N];
ii q[N];
int tree[1 << 21][3];
int same[1 << 21][3];

int power (int a, int b) {
	int c = 1;
	while (b) {
		if (b & 1) c = ((ll)c * a) % mod;
		a = ((ll)a * a) % mod;
		b /= 2;
	}
	re c;
}

void build (int x, int l, int r) {
	same[x][0] = same[x][1] = same[x][2] = 1;
	tree[x][0] = tree[x][1] = tree[x][2] = 0;
	if (l == r) re;
	int s = (l + r) / 2;
	build (x * 2 + 1, l, s);
	build (x * 2 + 2, s + 1, r);
}

inline void push (int t, int x, int l, int r) {
	if (same[x][t] == 1) re;
	tree[x][t] = ((ll)tree[x][t] * same[x][t]) % mod;
	if (l < r) {
		same[x * 2 + 1][t] = ((ll)same[x * 2 + 1][t] * same[x][t]) % mod;
		same[x * 2 + 2][t] = ((ll)same[x * 2 + 2][t] * same[x][t]) % mod;
	}	
	same[x][t] = 1;
}

int get (int t, int x, int l, int r, int lc, int rc) {
	if (r < lc || l > rc) re 0;
	push (t, x, l, r);
	if (l >= lc && r <= rc) re tree[x][t];
	int s = (l + r) / 2;
	int tmp = get (t, x * 2 + 1, l, s, lc, rc) + get (t, x * 2 + 2, s + 1, r, lc, rc);
	if (tmp >= mod) tmp -= mod;
	re tmp;
}

int put (int t, int x, int l, int r, int y, int z) {
	push (t, x, l, r);
	if (r < y || l > y) re tree[x][t];
	if (l == r) re tree[x][t] = z;
	int s = (l + r) / 2;
	int tmp = put (t, x * 2 + 1, l, s, y, z) + put (t, x * 2 + 2, s + 1, r, y, z);
	if (tmp >= mod) tmp -= mod;
	re tree[x][t] = tmp;
}

int mul (int t, int x, int l, int r, int lc, int rc, int z) {
	push (t, x, l, r);
	if (r < lc || l > rc) re tree[x][t];
//	printf ("mul %d %d %d %d %d %d %d = %d\n", t, x, l, r, lc, rc, z, tree[x][t]);
	if (l >= lc && r <= rc) {
		same[x][t] = z;
		push (t, x, l, r);
//		printf ("new %d\n", tree[x][t]);
		re tree[x][t];
	}
	int s = (l + r) / 2;
	int tmp = mul (t, x * 2 + 1, l, s, lc, rc, z) + mul (t, x * 2 + 2, s + 1, r, lc, rc, z);
	if (tmp >= mod) tmp -= mod;
	re tree[x][t] = tmp;
}

int print (int x, int l, int r) {
	push (0, x, l, r);
	push (1, x, l, r);
	push (2, x, l, r);
	printf ("%d %d %d = %d %d | %d %d | %d %d\n", x, l, r, tree[x][0], same[x][0], tree[x][1], same[x][1], tree[x][2], same[x][2]);
	if (l == r) {
		printf ("%d %d %d\n", tree[x][0], tree[x][1], tree[x][2]);
		re 0;
	}
	int s = (l + r) / 2;
	print (x * 2 + 1, l, s);
	print (x * 2 + 2, s + 1, r);
}

int add (ii x) {
	int diff = 0;
	int y = pos[x];
	int cnt = get (0, 0, 0, n + m - 1, 0, y - 1);
	put (0, 0, 0, n + m - 1, y, 1);
//	printf ("add %d %d = %d %d\n", x.fi, x.se, y, cnt);
	int lc = ((ll)x.fi * power (2, cnt)) % mod;
	int rc = ((ll)x.fi * power (rev2, cnt + 1)) % mod;
	put (1, 0, 0, n + m - 1, y, lc);
	put (2, 0, 0, n + m - 1, y, rc);
	mul (1, 0, 0, n + m - 1, y + 1, n + m - 1, 2);
	mul (2, 0, 0, n + m - 1, y + 1, n + m - 1, rev2);
	int ls = get (1, 0, 0, n + m - 1, 0, y - 1);
	int rs = get (2, 0, 0, n + m - 1, y + 1, n + m - 1);
//	printf ("%d %d | %d %d\n", lc, rc, ls, rs);
	diff = (diff - (ll)ls * rs + (ll)ls * rc + (ll)lc * rs) % mod;
	if (diff < 0) diff += mod;
//	print (0, 0, n + m - 1);
	re diff;
}

int del (ii x) {
	int diff = 0;
	int y = pos[x];
	int cnt = get (0, 0, 0, n + m - 1, 0, y - 1);
//	printf ("del %d %d = %d %d\n", x.fi, x.se, y, cnt);
	put (0, 0, 0, n + m - 1, y, 0);
	int lc = ((ll)x.fi * power (2, cnt)) % mod;
	int rc = ((ll)x.fi * power (rev2, cnt + 1)) % mod;
	put (1, 0, 0, n + m - 1, y, 0);
	put (2, 0, 0, n + m - 1, y, 0);
	int ls = get (1, 0, 0, n + m - 1, 0, y - 1);
	int rs = get (2, 0, 0, n + m - 1, y + 1, n + m - 1);
	mul (1, 0, 0, n + m - 1, y + 1, n + m - 1, rev2);
	mul (2, 0, 0, n + m - 1, y + 1, n + m - 1, 2);
	diff = (diff + (ll)ls * rs - (ll)ls * rc - (ll)lc * rs) % mod;
	if (diff < 0) diff += mod;
//	print (0, 0, n + m - 1);
	re diff;
}

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf ("%d", &p[i].fi);
		p[i].se = i;
		v.pb (p[i]);
	}
	scanf ("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf ("%d%d", &t[i], &q[i].fi); t[i]--;
		q[i].se = i + n;
		v.pb (q[i]);
	}
	sort (all (v));
	for (int i = 0; i < n + m; i++) pos[v[i]] = i;
	build (0, 0, n + m - 1);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += add (p[i]);
		if (ans >= mod) ans -= mod;
	}
	printf ("%d\n", ans);
	for (int i = 0; i < m; i++) {
		ans += del (p[t[i]]);
		if (ans >= mod) ans -= mod;
//		printf ("	%d\n", ans);
		p[t[i]] = q[i];
		ans += add (p[t[i]]);
		if (ans >= mod) ans -= mod;
		printf ("%d\n", ans);
	}
	re 0;
}