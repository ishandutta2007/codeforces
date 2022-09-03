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
int x;
set<ii> all;

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf ("%d%d%d", &n, &m, &x);
		all.clear ();
		for (int i = 0; i < m; i++) all.insert (mp (0, i + 1));
		printf ("YES\n");
		for (int i = 0; i < n; i++) {
			int y;
			scanf ("%d", &y);
			ii cur = *all.begin ();
			all.erase (all.begin ());
			printf ("%d ", cur.se);
			cur.fi += y;
			all.insert (cur);
		}
		printf ("\n");
	}
	re 0;
}