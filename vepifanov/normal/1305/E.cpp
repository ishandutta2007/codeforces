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

const int inf = 5e8;

int n;
int m;
int x[5000];

int main () {
	scanf ("%d%d", &n, &m);
	int cur = 0;
	for (int i = 0; i < n; i++) {
		x[i] = i + 1;
		cur += i / 2;
	}
	if (cur < m) {
		printf ("-1\n");
		re 0;
	}
	for (int i = n - 1; i >= 0 && cur > m; i--)
		if (cur - i / 2 < m) {
			x[i] += (cur - m) * 2;
			cur = m;
		} else {
			cur -= i / 2;
			x[i] = inf + i * 20000;
		}
	for (int i = 0; i < n; i++) printf ("%d ", x[i]);
	printf ("\n");

	if (1) {
		set<int> all;
		for (int i = 0; i < n; i++) all.insert (x[i]);
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				m -= all.count (x[i] + x[j]);
		fprintf (stderr, "%d\n", m); fflush (stderr);
		assert (m == 0);
	}
	re 0;
}