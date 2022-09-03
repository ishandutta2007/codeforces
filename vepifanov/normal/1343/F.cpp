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
int len[200];
vi g[200];
set<int> w[200];
int res[200];
int q[200];

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf ("%d", &n);
		for (int i = 0; i < n - 1; i++) {
			scanf ("%d", &len[i]);
			g[i].resize (len[i]);
			for (int j = 0; j < len[i]; j++) {
				scanf ("%d", &g[i][j]);
				g[i][j]--;
			}
		}
		for (int st = 0; st < n; st++) {
			for (int i = 0; i < n; i++) w[i].clear ();
			for (int i = 0; i < n - 1; i++)
				for (int j = 0; j < len[i]; j++)
					w[g[i][j]].insert (i);
			int cur = -1;
			for (int i = 0; i < n; i++)
				if (i != st && sz (w[i]) == 1) {
					cur = i;
					break;
				}
			if (cur == -1) continue;
			int ok = 1;
			for (int i = n - 1; i > 0; i--) {
				res[i] = cur;
				if (i == 1) break;
				int t = *w[cur].begin ();
				cur = -1;
				for (int j = 0; j < len[t]; j++) {
					w[g[t][j]].erase (t);
					if (g[t][j] != st && sz (w[g[t][j]]) == 1) cur = g[t][j];
				}
				if (cur == -1) {
					ok = 0;
					break;
				}
			}
			if (ok) {
				res[0] = st;
				for (int i = 0; i < n; i++) q[res[i]] = i;
				for (int i = 0; i < n - 1; i++) {
					int a = n, b = -1;
					for (int j = 0; j < len[i]; j++) {
						a = min (a, q[g[i][j]]);
						b = max (b, q[g[i][j]]);
					}
					if (b - a + 1 != len[i]) {
						ok = 0;
						break;
					}
				}
				if (ok)	break;
			}
		}
		for (int i = 0; i < n; i++) printf ("%d ", res[i] + 1);
		printf ("\n");
	}
	re 0;
}