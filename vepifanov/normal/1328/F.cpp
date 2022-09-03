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
ii p[200000];
ii q[200000];
int x[200000];

ll calc (ii* p, int r) {
	ll ans = 1e18, cur = 0;
	ll sum = 0;
	for (int i = 0; i < r; i++) sum += (ll)p[i].fi * p[i].se;
	for (int i = 0; i + 1 < r; i++) {
//		printf ("%d %d\n", p[i].fi, p[i].se);
		if (p[i].se >= m) ans = min (ans, cur - int (i > 0) * (p[i].se - m)); else {
			ans = min (ans, cur + (sum - (ll)p[i].se * p[i].fi - (ll)(n - p[i].se) * (p[i].fi + 1)) + (m - p[i].se));
		}	
		sum += (ll)p[i].se * (p[i + 1].fi - p[i].fi);
		cur += (ll)p[i].se * (p[i + 1].fi - p[i].fi);
		p[i + 1].se += p[i].se;
	}
	re ans;
}

int main () {
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
	sort (x, x + n);
	int r = 0;
	for (int i = 0; i < n; ) {
		int j = i;
		while (j < n && x[j] == x[i]) j++;
		p[r++] = mp (x[i], j - i);
		if (j - i >= m) {
			printf ("0\n");
			re 0;
		}
		i = j;
	}
	for (int i = 0; i < r; i++) {
		q[r - i - 1] = p[i];
		q[r - i - 1].fi *= -1;
	}
	printf ("%lld\n", min (calc (p, r), calc (q, r)));
	re 0;
}