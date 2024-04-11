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
vi p;
vi w;
vi u[30];
set<int> was;

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		p.clear ();
		w.clear ();
		for (int i = 0; i < 30; i++) u[i].clear ();
		was.clear ();
		scanf ("%d", &n);
		for (int i = 1; i * i <= n; i++)
			if (n % i == 0) {
				if (i > 1) w.pb (i);
				if (i * i != n)
					w.pb (n / i);
			}
		sort (all (w));
		m = n;
		for (int i = 2; i * i <= m; i++)
			if (m % i == 0) {
				p.pb (i);
				while (m % i == 0) m /= i;
			}
		if (m > 1) p.pb (m);
		int r = sz (p);
		for (int i = 0; i < r; i++) was.insert (p[i]);
		if (r == 1) {
			for (int i = 0; i < sz (w); i++) printf ("%d ", w[i]);
			printf ("\n0\n");
			continue;
		}
		for (int i = 0; i < r; i++) {
			u[i].pb (p[i] * p[(i + 1) % r]);
			was.insert (p[i] * p[(i + 1) % r]);
		}
		int ans = 0;
		if (r == 2) {
			if (p[0] * p[1] < n) {
				u[1][0] = n;
				was.insert (n);
			} else {
				u[1].pop_back();
				ans = 1;
			}
		}
		for (int i = 0; i < sz (w); i++)
			if (!was.count (w[i])) {
				int j = 0;
				while (j < r && w[i] % p[j] != 0) j++;
				if (j == r) {
					assert (false);
//					printf ("bad %d\n", w[i]);
				} else u[j].pb (w[i]);
			}
//		vi res;
		for (int i = 0; i < r; i++) {
			printf ("%d ", p[i]);
//			res.pb (p[i]);
			for (int j = 0; j < sz (u[i]); j++) {
//				res.pb (u[i][sz (u[i]) - j - 1]);
				printf ("%d ", u[i][sz (u[i]) - j - 1]);
			}	
		}
		printf ("\n%d\n", ans);
/*		assert (sz (res) == sz (w));
		int cur = 0;
		for (int i = 0; i < sz (w); i++) {	
			cur += int (gcd (res[i], res[(i + 1) % sz (w)]) == 1);
		}
		assert (cur == ans);
		sort (all (res));
		assert (res == w);*/
	}
	re 0;
}