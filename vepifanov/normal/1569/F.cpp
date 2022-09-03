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
int k;
int cnt[12];
vi v[12];
int was[1 << 12][12][12];
pair<int, ii> q[(1 << 12) * 12 * 12];
int col[12];
int ct;
int g[12][12];
int ct2;
int was2[12];

void go2 (int x) {
	was2[x] = ct2;
	for (int i = 0; i < n; i++)
		if (g[x][i] && was2[i] != ct2)
			go2 (i);
}

int check (int mask, int x, int y) {
	ct2++;
	for (int i = 0; i < n; i++)
		if ((mask >> i) & 1)
			was2[i] = ct2;
	go2 (x);
	go2 (y);
	for (int i = 0; i < n; i++)
		if (was2[i] != ct2)
			re 0;
	re 1;
}

int pre[1 << 12][12][12];
int vv[1 << 12][12][12];
int cv[1 << 12][12];

int go2 (int mask, int x, int y) {
	if ((mask + 1) == (1 << n)) re 1;
	if (!pre[mask][x][y]) re 0;
	was[mask][x][y] = ct;
	for (int ia = 0; ia < cv[mask][x]; ia++)
		for (int ib = 0; ib < cv[mask][y]; ib++) {
			int a = vv[mask][x][ia];
			int b = vv[mask][y][ib];
			if (a != b && col[a] == col[b] && was[mask | (1 << a) | (1 << b)][a][b] != ct)
				if (go2 (mask | (1 << a) | (1 << b), a, b)) re 1;
		}
	re 0;
}

ll go (int i, int j, ll tot) {
	if (!tot) re 0;
	if (i == n) {
		for (int k = 0; k < j; k++)
			if (cnt[k] & 1)
				re 0;
		ct++;
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				if (g[i][j] && col[i] == col[j])
					if (go2 ((1 << i) | (1 << j), i, j)) re tot;
		re 0;
	}
	ll ans = 0;
	for (int k = 0; k <= j; k++) {
		col[i] = k;
		cnt[k]++;
		ans += go (i + 1, j + int (k == j), j == k ? tot * (::k - j) : tot);
		cnt[k]--;
	}
	re ans;
}

int main () {
	scanf ("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf ("%d%d", &a, &b); a--; b--;
		v[a].pb (b);
		v[b].pb (a);
		g[a][b] = g[b][a] = 1;
	}
	for (int i = 0; i < (1 << n); i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++) {
				pre[i][j][k] = check (i, j, k);
				if (((i >> k) & 1) == 0 && g[j][k])
					vv[i][j][cv[i][j]++] = k;
			}	
	printf ("%lld\n", go (0, 0, 1));
	cerr << clock () << endl;
    re 0;
}