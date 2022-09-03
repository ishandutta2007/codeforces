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
int x[N];
int pref[N + 1];
int suf[N + 1];

int main () {
	scanf ("%d", &n);
	pref[0] = suf[n] = 0;
	for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
	for (int i = 0; i < n; i++) pref[i + 1] = pref[i] | x[i];
	for (int i = n - 1; i >= 0; i--) suf[i] = suf[i + 1] | x[i];
	ii best (-1, 0);
	for (int i = 0; i < n; i++) {
		int y = pref[i] | suf[i + 1];
		best = max (best, mp ((x[i] | y) - y, i));
	}
	printf ("%d ", x[best.se]);
	for (int i = 0; i < n; i++)
		if (i != best.se)
			printf ("%d ", x[i]);
	printf ("\n");
	re 0;
}