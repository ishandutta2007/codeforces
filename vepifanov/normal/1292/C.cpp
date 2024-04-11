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

const int N = 3000;

int n;
int m;

int anc[N][12];
int tin[N];
int tout[N];
int ct;
vi v[N];
int cnt[N];
int d[N];
ll res[N][N];

int dfs (int x, int p) {
	tin[x] = ct++;
	anc[x][0] = p;
	for (int i = 1; i < 12; i++) anc[x][i] = anc[anc[x][i - 1]][i - 1];
	cnt[x] = 1;
	for (auto y : v[x])
		if (y != p) {
			d[y] = d[x] + 1;
			cnt[x] += dfs (y, x);
		}
	tout[x] = ct++;
	re cnt[x];
}

inline bool isanc (int x, int y) { re tin[x] <= tin[y] && tout[x] >= tout[y]; }

int lca (int x, int y) {
	int t = 11;
	while (!isanc (x, y))
		if (t == 0 || !isanc (anc[x][t], y))
			x = anc[x][t];
		else
			t--;	
	re x;
}

int up (int x, int dy) {
	int t = 11;
	while (d[x] != dy)
		if (t == 0 || d[anc[x][t]] > dy)
			x = anc[x][t];
		else
			t--;	
	re x;
}

ll go (int x, int y) {
	if (x == y) re 0;
	if (x > y) swap (x, y);
	if (res[x][y]) re res[x][y];
	ll cur = 0;
	int z = lca (x, y);
	if (z == x) {
		int nx = up (y, d[x] + 1);
		cur = max (go (nx, y), go (x, anc[y][0])) + (n - cnt[nx]) * cnt[y];
	} else if (z == y) {
		int ny = up (x, d[y] + 1);
		cur = max (go (ny, x), go (y, anc[x][0])) + (n - cnt[ny]) * cnt[x];
	} else {
		cur = max (go (anc[x][0], y), go (x, anc[y][0])) + cnt[x] * cnt[y];
	}
//	printf ("%d %d = %d | %d %d %d\n", x + 1, y + 1, (int)cur, z + 1, cnt[x], cnt[y]);
	re res[x][y] = cur;
}

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		scanf ("%d%d", &a, &b); a--; b--;
		v[a].pb (b);
		v[b].pb (a);
	}
	d[0] = 0;
	dfs (0, 0);
	ll ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			ans = max (ans, go (i, j));
	cout << ans << endl;
	re 0;
}