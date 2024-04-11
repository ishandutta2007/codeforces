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
vi v[2];

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf ("%d", &n);
		v[0].clear ();
		v[1].clear ();
		for (int i = 0; i < 2 * n; i++) {
			int x;
			scanf ("%d", &x);
			v[x & 1].pb (i + 1);
		}
		int m = n - 1;
		for (int i = 0; i + 1 < sz (v[0]) && m > 0; i += 2, m--) printf ("%d %d\n", v[0][i], v[0][i + 1]);
		for (int i = 0; i + 1 < sz (v[1]) && m > 0; i += 2, m--) printf ("%d %d\n", v[1][i], v[1][i + 1]);
	}
	re 0;
}