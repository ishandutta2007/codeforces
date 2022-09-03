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
int ea[1000];
int eb[1000];
vii v[1000];
int mark[1000];
int d[1000][1000];
set<ii> all;

int main () {
	scanf ("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf ("%d%d%d", &a, &b, &c); a--; b--;
		v[a].pb (mp (b, c));
		v[b].pb (mp (a, c));
	}
	for (int i = 0; i < k; i++) {
		scanf ("%d%d", &ea[i], &eb[i]);
		ea[i]--;
		eb[i]--;
	}	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			d[i][j] = 1e9;
			mark[j] = 0;
		}
		mark[i] = 1;
		d[i][i] = 0;
		all.insert (mp (0, i));
		while (!all.empty ()) {
			int x = all.begin()->se;
			all.erase (all.begin ());
			for (auto& y : v[x])
				if (d[i][y.fi] > d[i][x] + y.se) {
					if (mark[y.fi]) all.erase (mp (d[i][y.fi], y.fi));
					mark[y.fi] = 1;
					d[i][y.fi] = d[i][x] + y.se;
					all.insert (mp (d[i][y.fi], y.fi));
				}
		}
	}
	int ans = 2e9;
	for (int i = 0; i < n; i++)
		for (auto& y : v[i]) {
			int j = y.fi;
			int cur = 0;
			for (int t = 0; t < k; t++)
				cur += min (d[ea[t]][eb[t]], min (d[ea[t]][i] + d[j][eb[t]], d[ea[t]][j] + d[i][eb[t]]));
			ans = min (ans, cur);
		}
	printf ("%d\n", ans);
	re 0;
}