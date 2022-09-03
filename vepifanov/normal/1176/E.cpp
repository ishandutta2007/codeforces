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
int was[200000];
vi q[2];
vi v[200000];

int go (int x, int c) {
	if (was[x]) re 0;
	was[x] = 1;
	q[c].pb (x + 1);
	for (auto y : v[x])
		go (y, c ^ 1);
	re 0;
}

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf ("%d%d", &n, &m);
		for (int i = 0; i < n; i++) {
			v[i].clear ();
			was[i] = 0;
		}
		for (int i = 0; i < m; i++) {
			int a, b;
			scanf ("%d%d", &a, &b); a--; b--;
			v[a].pb (b);
			v[b].pb (a);
		}
		q[0].clear ();
		q[1].clear ();
		for (int i = 0; i < n; i++) go (0, 0);
		int t = sz (q[0]) < sz (q[1]) ? 0 : 1;
		printf ("%d\n", sz (q[t]));
		for (auto x : q[t]) printf ("%d ", x);
		printf ("\n");
	}	
	re 0;
}