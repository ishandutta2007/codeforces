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
int a[500];
int b[500];

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf ("%d", &n);
		for (int i = 0; i < n; i++) scanf ("%d", &a[i]);
		for (int i = 0; i < n; i++) scanf ("%d", &b[i]);
		vii v, w;
		for (int i = 0, j = n - 1; i < j; i++, j--) {
			v.pb (mp (min (a[i], a[j]), max (a[i], a[j])));
			w.pb (mp (min (b[i], b[j]), max (b[i], b[j])));
		}
		sort (all (v));
		sort (all (w));
		if (n & 1) {
			v.pb (mp (a[n / 2], a[n / 2]));
			w.pb (mp (b[n / 2], b[n / 2]));
		}	
		printf ("%s\n", (v == w) ? "Yes" : "No");
	}
	re 0;
}