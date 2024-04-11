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
int m[2];
vi v[2][2000];
int x[2][2000];
int y[2][2000];
int tin[2][2000];
int tout[2][2000];
int anc[2][2000][10];
int ct = 0;
int d[2][2000];

int dfs (int t, int x, int p, int len) {
	tin[t][x] = ct++;
	d[t][x] = len;
	anc[t][x][0] = p;
	for (int i = 0; i < 9; i++)
		anc[t][x][i + 1] = anc[t][anc[t][x][i]][i];
	for (auto y : v[t][x])
		dfs (t, y, x, len + 1);
	tout[t][x] = ct++;
	re 0;
}

int isanc (int t, int a, int b) { re int (tin[t][a] <= tin[t][b] && tout[t][a] >= tout[t][b]); }

int lca (int t, int a, int b) {
	int j = 9;
	while (!isanc (t, a, b))
		if (j == 0 || !isanc (t, anc[t][a][j], b))
			a = anc[t][a][j];
		else
			j--;	
	re a;
}

int get (int t, int a, int b) {
	a = x[t][a];
	b = x[t][b];
	if (b == -1) re d[t][a];
	int c = lca (t, a, b);
	re d[t][a] - d[t][c];
}

int was[1001][1001];
int res[1001][1001];

int go (int i, int j) {
	if (i == 0 || j == 0) re 0;
	if (was[i][j]) re res[i][j];
	was[i][j] = 1;
	int cur = 1e9;
	int k = min (i, j) - 1;
	cur = min (cur, go (k, j) + get (0, k, i));
	cur = min (cur, go (i, k) + get (1, k, j));
//	printf ("%d %d = %d\n", i + 1, j + 1, cur);
	re res[i][j] = cur;
}

int main () {
	scanf ("%d", &n);
	for (int t = 0; t < 2; t++) {
		scanf ("%d", &m[t]);
		for (int i = 0; i < m[t] - 1; i++) {
			int x;
			scanf ("%d", &x); x--;
			v[t][x].pb (i + 1);
		}
		for (int i = 0; i < n; i++) {
			scanf ("%d", &x[t][i]);
			x[t][i]--;
			y[t][x[t][i]] = i;
		}	
		x[t][n] = -1;
		dfs (t, 0, 0, 0);
	}	
	printf ("%d\n", m[0] + m[1] - 2 - go (n, n));
	re 0;
}