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
vi v[200];
int sum[200001][200];
int x[200001];

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		for (int i = 0; i < 200; i++) v[i].clear ();
		scanf ("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf ("%d", &x[i]);
			x[i]--;
			v[x[i]].pb (i);
		}
		for (int i = 0; i < 200; i++) sum[n][i] = 0;
		for (int i = n - 1; i >= 0; i--) {
			for (int j = 0; j < 200; j++)
				sum[i][j] = sum[i + 1][j];
			sum[i][x[i]]++;
		}
		int ans = 0;
		for (int i = 0; i < 200; i++) {
			for (int j = 0; 2 * j <= sz (v[i]); j++) {
				int l = 0, r = n - 1;
				if (j > 0) {
					l = v[i][j - 1] + 1;
					r = v[i][sz (v[i]) - j] - 1;
				}
				int cur = 2 * j;
				if (l <= r) {
					for (int k = 0; k < 200; k++)
						ans = max (ans, cur + sum[l][k] - sum[r + 1][k]);
				} else ans = max (ans, cur);
			}
		}
		printf ("%d\n", ans);
	}
	re 0;
}