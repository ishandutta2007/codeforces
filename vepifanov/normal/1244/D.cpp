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
int g[3][100000];
ll res[100001][4][4];
int prev[100001][4][4];
vi v[100000];
int col[100000];
vi q;

int go (int x, int p) {
	q.pb (x);
	for (auto y : v[x])
		if (y != p)
			go (y, x);
	re 0;
}

int out (int i, int a, int b) {
	if (i == 0) re 0;
	col[q[i - 1]] = b;
	out (i - 1, prev[i][a][b], a);
	re 0;
}

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < n; j++)
			scanf ("%d", &g[i][j]);
	for (int i = 0; i + 1 < n; i++) {
		int a, b;
		scanf ("%d%d", &a, &b); a--; b--;
		v[a].pb (b);
		v[b].pb (a);
	}
	for (int i = 0; i < n; i++)
		if (sz (v[i]) > 2) {
			printf ("-1\n");
			re 0;
		}
	for (int i = 0; i < n; i++)
		if (sz (v[i]) == 1) {
			go (i, i);
			break;
		}	
	for (int i = 0; i <= n; i++)
		for (int a = 0; a <= 3; a++)
			for (int b = 0; b <= 3; b++)
				res[i][a][b] = 1e18;
	res[0][3][3] = 0;
	for (int i = 0; i < n; i++)
		for (int a = 0; a <= 3; a++)
			for (int b = 0; b <= 3; b++) {
//				printf ("%d %d %d = %lld\n", i, a, b, res[i][a][b]);
				for (int c = 0; c < 3; c++)
					if (a != c && b != c && res[i][a][b] + g[c][q[i]] < res[i + 1][b][c]) {
						res[i + 1][b][c] = res[i][a][b] + g[c][q[i]];
						prev[i + 1][b][c] = a;
					}
			}
	ll ans = 1e18;
	int aa, ab;
	for (int a = 0; a <= 3; a++)
		for (int b = 0; b < 3; b++)
			if (res[n][a][b] < ans) {
				ans = res[n][a][b];
				aa = a;
				ab = b;
			}	
	out (n, aa, ab);
	printf ("%lld\n", ans);
	for (int i = 0; i < n; i++) printf ("%d ", col[i] + 1);
	printf ("\n");
	re 0;
}