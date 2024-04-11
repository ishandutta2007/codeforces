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
int x[200000];
ii v[200000];
int s[200001];
int res[200001];

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf ("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf ("%d", &x[i]);
			v[i] = mp (x[i], i);
		}
		sort (v, v + n);
		vii w;
		int cur = 0, pos = 0;
		for (int i = 0; i < n; i++) {
			cur++;
			if (i + 1 == n || v[i + 1].fi != v[i].fi) {
				w.pb (mp (pos, pos + cur - 1));
				pos += cur;
				cur = 0;
			}
		}
		m = sz (w);
		s[m] = 0;
		for (int i = m - 1; i >= 0; i--) s[i] = s[i + 1] + w[i].se - w[i].fi + 1;
		int ans = 0;
		for (int i = m - 1; i >= 0; i--) {
			res[i] = 1;
			if (i + 1 < m && v[w[i].se].se < v[w[i + 1].fi].se)
				res[i] += res[i + 1];
			int a = i, b = i + res[i] - 1;
			int cur = s[a] - s[b + 1];
			if (a > 0) {
				if (v[w[a - 1].se].se < v[w[a].fi].se) cur += w[a - 1].se - w[a - 1].fi + 1; else {
					int l = 0, r = w[a - 1].se - w[a - 1].fi + 1;
					while (r - l > 1) {
						int s = (l + r) / 2;
						if (v[w[a - 1].fi + s - 1].se < v[w[a].fi].se) l = s; else r = s;
					}
					cur += l;
				}	
			}
			if (b + 1 < m) {
				int l = 0, r = w[b + 1].se - w[b + 1].fi + 1;
				while (r - l > 1) {
					int s = (l + r) / 2;
					if (v[w[b].se].se < v[w[b + 1].se - s + 1].se) l = s; else r = s;
				}
				cur += l;
			}
			ans = max (ans, cur);
			if (i + 1 < m) {
				for (int j = 0; j < w[i].se - w[i].fi; j++) {
					int l = 0, r = w[i + 1].se - w[i + 1].fi + 1;
					while (r - l > 1) {
						int s = (l + r) / 2;
						if (v[w[i].fi + j].se < v[w[i + 1].se - s + 1].se) l = s; else r = s;
					}
					ans = max (ans, j + 1 + l);
				}
			}
		}
		printf ("%d\n", n - ans);
	}
	re 0;
}