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
int p[200000];
int q[200000];
int was[200000];

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf ("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf ("%d", &p[i]);
			p[i]--;
		}
		for (int i = 0; i < n; i++) scanf ("%d", &q[i]);
		for (int i = 0; i < n; i++) was[i] = 0;
		int ans = n + 1;
		for (int i = 0; i < n; i++)
			if (!was[i]) {
				int j = i;
				vi v;
				while (!was[j]) {
					was[j] = 1;
					v.pb (j);
					j = p[j];
				}
				for (int t = 1; t <= sz (v) && t < ans; t++)
					if (sz (v) % t == 0)
						for (int j = 0; j < t; j++) {
							int ok = 1;
							int k = j;
							do {
								ok &= int (q[v[j]] == q[v[k]]);
								k = (k + t) % sz (v);
							} while (k != j);
							if (ok) ans = t;
						}
			}
		printf ("%d\n", ans);
	}
	re 0;
}