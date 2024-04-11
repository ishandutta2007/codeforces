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

const int N = 1 << 19;
 
int n;
int m;
vii v[N];
int p[N];
int res[N];
int tree[2 * N + 10];
int anc[N][20];
int tin[N];
int tout[N];
int col[N];
int was[N];
int ea[N];
int eb[N];
int ec[N];
int ct = 0;

int gp (int x) {
	if (p[x] != x) p[x] = gp (p[x]);
	re p[x];
}

int isanc (int a, int b) { re int (tin[a] <= tin[b] && tout[a] >= tout[b]); }

int go (int x, int p, int c) {
	was[x] = 1;
	col[x] = c;
	anc[x][0] = p;
	for (int i = 1; i < 20; i++)
		anc[x][i] = anc[anc[x][i - 1]][i - 1];
	tin[x] = ct++;
	for (auto& y : v[x])
		if (p != y.fi)
			go (y.fi, x, c ^ y.se);
	tout[x] = ct - 1;
	re 0;
}

int lca (int a, int b) {
	int j = 19;
	while (!isanc (a, b))
		if (j == 0 || !isanc (anc[a][j], b))
			a = anc[a][j];
		else
			j--;	
	re a;
}

int get (int x, int l, int r, int y) {
	if (r < y || l > y) re 0;
	if (l == r) re tree[x];
	int s = (l + r) / 2;
	re get (x * 2 + 1, l, s, y) + get (x * 2 + 2, s + 1, r, y) + tree[x];
}

void add (int x, int l, int r, int lc, int rc) {
	if (r < lc || l > rc) re;
	if (l >= lc && r <= rc) {
		tree[x]++;
		re;
	}
	int s = (l + r) / 2;
	add (x * 2 + 1, l, s, lc, rc);
	add (x * 2 + 2, s + 1, r, lc, rc);
}

int main () {
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < n; i++) p[i] = i;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf ("%d%d%d", &a, &b, &c); a--; b--;
		ea[i] = a;
		eb[i] = b;
		ec[i] = c;
		int pa = gp (a);
		int pb = gp (b);
		if (pa != pb) {
			res[i] = 1;
			if (rand () & 1) swap (pa, pb);
			p[pa] = pb;
			v[a].pb (mp (b, c));
			v[b].pb (mp (a, c));
		}
	}
	for (int i = 0; i < n; i++)
		if (!was[i])
			go (i, i, 0);
	for (int i = 0; i < m; i++)
		if (!res[i]) {
			int a = ea[i];
			int b = eb[i];
			int c = ec[i];
			if ((col[a] ^ col[b] ^ c) == 0) continue;
			int z = lca (a, b);
			int bad = get (0, 0, n - 1, tin[a]) + get (0, 0, n - 1, tin[b]) - 2 * get (0, 0, n - 1, tin[z]);
			if (bad) continue;
			while (a != z) {
				add (0, 0, n - 1, tin[a], tout[a]);
				a = anc[a][0];
			}
			while (b != z) {
				add (0, 0, n - 1, tin[b], tout[b]);
				b = anc[b][0];
			}
			res[i] = 1;
		}
	for (int i = 0; i < m; i++) printf ("%s\n", res[i] ? "YES" : "NO");
    re 0;
}