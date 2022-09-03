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
int now[6];
int was[80];
vii w[80][80];
int ans;
int g[80][80];

int gen (int i) {
	if (i == m / 2) {
		now[i] = 0;
		int cur = 0;
		for (int j = 0; j < m / 2; j++) {
			int a = now[j];
			int b = now[j + 1];
			int k = 0;
			while (k < sz (w[a][b]) && was[w[a][b][k].se]) k++;
			if (k == sz (w[a][b])) re 0;
			cur += w[a][b][k].fi;
			if (cur >= ans) re 0;
		}
//		for (int j = 0; j <= m / 2; j++) printf ("%d ", now[j] + 1);
//		printf ("= %d\n", cur);
		if (cur < ans) ans = cur;
		re 0;
	}
	for (int t = 0; t < n; t++) {
		was[t]++;
		now[i] = t;
		gen (i + 1);
		was[t]--;
	}
	re 0;
}

int main () {
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf ("%d", &g[i][j]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			w[i][j].clear ();
			for (int k = 0; k < n; k++)
				if (k != i && k != j)
					w[i][j].pb (mp (g[i][k] + g[k][j], k));
			sort (all (w[i][j]));
		}
	was[0] = 1;
	now[0] = 0;
	ans = 2e9;
	gen (1);
	printf ("%d\n", ans);
//	cerr << clock () << endl;
	re 0;
}