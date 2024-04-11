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
int a1, a2, k1, k2;

int main () {
	scanf ("%d%d%d%d%d", &a1, &a2, &k1, &k2, &n);
	int ansmin = 1e9, ansmax = 0;
	for (int c1 = 0; c1 <= a1; c1++)
		for (int c2 = 0; c2 <= a2; c2++)
			if (c1 * k1 + c2 * k2 <= n && c1 * k1 + (a1 - c1) * (k1 - 1) + c2 * k2 + (a2 - c2) * (k2 - 1) >= n) {
				ansmin = min (ansmin, c1 + c2);
				ansmax = max (ansmax, c1 + c2);
			}
	printf ("%d %d\n", ansmin, ansmax);
	re 0;
}