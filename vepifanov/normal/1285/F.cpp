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

const int N = 100000;

int n;
int m;
int x[N + 1];
int y[N + 1];
int q[N + 1];
vi w[N + 1];
int cnt[N + 1];

int calc (const vi& w, int i, int cur, int md) {
	if (i == sz (w)) re cnt[cur] * md;
	re calc (w, i + 1, cur, md) + calc (w, i + 1, cur * w[i], -md);
}

void add (const vi& w, int i, int cur, int md) {
	if (i == sz (w)) {
		cnt[cur] += md;
		re;
	}
	add (w, i + 1, cur, md);
	if (cur % w[i] == 0) add (w, i, cur / w[i], md);
}

int main () {
	double start = clock ();
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf ("%d", &x);
		for (int j = 1; j * j <= x; j++)
			if (x % j == 0)
				y[j] = y[x / j] = 1;
	}	
	for (int i = 1; i <= N; i++) {
		int j = i;
		for (int t = 2; t * t <= i; t++)
			if (j % t == 0) {
				w[i].pb (t);
				while (j % t == 0) j /= t;
			}
		if (j > 1) w[i].pb (j);
	}
	n = 0;
	for (int i = 1; i <= N; i++)
		if (y[i])
			x[n++] = i;
	ll ans = x[n - 1];
	int r = 0;
	for (int i = n - 1; i >= 0; i--) {
		while (r > 0) {
			int now = calc (w[x[i]], 0, 1, 1);
//			printf ("%d %d %d\n", x[i], r, now);
			if (now > 0) {
//				printf ("%d %d\n", x[i], q[r - 1]);
				if (gcd (x[i], q[r - 1]) == 1) ans = max (ans, (ll)x[i] * q[r - 1]);
				add (w[q[r - 1]], 0, q[r - 1], -1);
				r--;
			} else break;
		}	
		q[r++] = x[i];
		add (w[x[i]], 0, x[i], 1);
	}
	cout << ans << endl;	
	re 0;
}