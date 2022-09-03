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
int k;
int b;
int l[200000];
int r[200000];
set<int> all;
pair<int, ll> q[10];
pair<int, ll> nq[10];

void add (pair<int, ll>* q, int& qr, int y, ll z) {
	auto it = all.lower_bound (y);
	if (*it < m) q[qr++] = mp (*it, z + abs (y - *it));
	it--;
	if (*it >= 0) q[qr++] = mp (*it, z + abs (y - *it));
}

int main () {
	scanf ("%d%d%d%d", &n, &m, &k, &b);
	for (int i = 0; i < n; i++) {
		l[i] = m;
		r[i] = -1;
	}
	for (int i = 0; i < k; i++) {
		int x, y;
		scanf ("%d%d", &x, &y); x--; y--;
		l[x] = min (l[x], y);
		r[x] = max (r[x], y);
	}
	all.insert (-1);
	all.insert (m);
	for (int i = 0; i < b; i++) {
		int x;
		scanf ("%d", &x);
		x--;
		all.insert (x);
	}
	int qr = 0;
	if (r[0] == -1) {
		add (q, qr, 0, 0);
	} else {
		q[qr++] = mp (0, 0);
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		if (r[i] == -1) continue;
		ans = 1e18;
		int nqr = 0;
		{
			ll best = 1e18;
			for (int j = 0; j < qr; j++)
				best = min (best, q[j].se + abs (q[j].fi - r[i]) + abs (l[i] - r[i]));
			add (nq, nqr, l[i], best);
			ans = min (ans, best + i);
		}
		{
			ll best = 1e18;
			for (int j = 0; j < qr; j++)
				best = min (best, q[j].se + abs (q[j].fi - l[i]) + abs (l[i] - r[i]));
			add (nq, nqr, r[i], best);
			ans = min (ans, best + i);
		}
		qr = nqr;
//		printf ("%d %d\n", l[i], r[i]);
		for (int j = 0; j < qr; j++) {
//			printf ("%d %d = %lld\n", i + 1, nq[j].fi + 1, nq[j].se);
			q[j] = nq[j];
		}
	}
	cout << ans << endl;
	re 0;
}