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
int x[11];

int main () {
	for (int i = 0; i < 11; i++) scanf ("%d", &x[i]);
	for (int i = 10; i >= 0; i--) {
		double a = sqrt (fabs (x[i] + 0.0));
		double b = pow (x[i], 3.0) * 5;
		double c = a + b;
		if (c > 400) printf ("f(%d) = MAGNA NIMIS!\n", x[i]); else printf ("f(%d) = %.2f\n", x[i], c);
	}
	re 0;
}