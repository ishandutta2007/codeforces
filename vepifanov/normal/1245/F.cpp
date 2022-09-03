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
int was[30][2][2];
ll res[30][2][2];
int ct = 0;

ll go (int x, int y, int i, int fx, int fy) {
	if (i < 0) re 1;
	if (was[i][fx][fy] == ct) re res[i][fx][fy];
	int ax = (x >> i) & 1;
	int ay = (y >> i) & 1;
	was[i][fx][fy] = ct;
	ll cur = 0;
	for (int bx = 0; bx < 2; bx++)
		for (int by = 0; bx + by < 2; by++)
			if ((fx || bx <= ax) && (fy || by <= ay))
				cur += go (x, y, i - 1, fx | int (bx < ax), fy | int (by < ay));
	re res[i][fx][fy] = cur;
}

ll go (int x, int y) {
	if (x < 0 || y < 0) re 0;
	ct++;
	re go (x, y, 29, 0, 0);
}

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf ("%d%d", &n, &m);
		ll ans = go (m, m) - go (n - 1, m) * 2 + go (n - 1, n - 1);
		printf ("%lld\n", ans);
	}
	re 0;
}