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
int t[3000];
ll s[3000][3001];
ll res[3001][6001];
int prev[3001][6001];
int was[3001];

int out (int i, int j) {
	if (i == 0) re 0;
	if (prev[i][j]) {
		was[i - 1] = 1;
		out (i - 1, j - t[i - 1]);
	} else {
		out (i - 1, j);
	}
}

int main () {
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		int tt;
		scanf ("%d", &tt);
		t[i] = min (m, tt);
		s[i][0] = 0;
		ll cur = 0;
		for (int j = 0; j < tt; j++) {
			int x;
			scanf ("%d", &x);
			cur += x;
			if (j < t[i]) s[i][j + 1] = cur;
		}
	}
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= 2 * m; j++)
			res[i][j] = -1e18;
	res[0][0] = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= 2 * m; j++) {
			if (res[i + 1][j] < res[i][j]) {
				res[i + 1][j] = res[i][j];
				prev[i + 1][j] = 0;
			}
			if (j + t[i] <= 2 * m && res[i + 1][j + t[i]] < res[i][j] + s[i][t[i]]) {
				res[i + 1][j + t[i]] = res[i][j] + s[i][t[i]];
				prev[i + 1][j + t[i]] = 1;
			}	
//			printf ("%d %d = %lld\n", i, j, res[i][j]);
		}
	ll ans = 0;
	for (int j = 0; j <= 2 * m; j++) {
		if (res[n][j] < 0) continue;
		for (int i = 0; i < n; i++) was[i] = 0;
		out (n, j);
//		printf ("%d = %lld\n", j, res[n][j]);
//		for (int i = 0; i < n; i++) printf ("%d ", was[i]);
//		printf ("\n");
		if (j < m) {
			for (int i = 0; i < n; i++)
				if (!was[i] && j + t[i] >= m)
					ans = max (ans, res[n][j] + s[i][m - j]);
		} else {
			for (int i = 0; i < n; i++)
				if (was[i] && t[i] >= (j - m))
					ans = max (ans, res[n][j] - s[i][t[i]] + s[i][t[i] - (j - m)]);
		}
//		printf ("%lld\n", ans);
	}
	printf ("%lld\n", ans);
	cerr << clock () << endl;
	re 0;
}