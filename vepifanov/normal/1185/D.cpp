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
ii v[200000];
int cl[200000];
int cr[200000];

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf ("%d", &v[i].fi);
		v[i].se = i + 1;
	}
	sort (v, v + n);
	cl[0] = cl[1] = 1;
	for (int i = 2; i < n; i++) cl[i] = cl[i - 1] & int (v[i].fi - v[i - 1].fi == v[i - 1].fi - v[i - 2].fi);
	cr[n - 1] = cr[n - 2] = 1;
	for (int i = n - 3; i >= 0; i--) cr[i] = cr[i + 1] & int (v[i].fi - v[i + 1].fi == v[i + 1].fi - v[i + 2].fi);
	if (cr[1]) {
		printf ("%d\n", v[0].se);
		re 0;
	}
	if (cl[n - 2]) {
		printf ("%d\n", v[n - 1].se);
		re 0;
	}
	for (int i = 1; i + 1 < n; i++)
		if (cl[i - 1] && cr[i + 1]) {
			int ok = 1;
			if (i - 2 >= 0) ok &= int (v[i + 1].fi - v[i - 1].fi == v[i - 1].fi - v[i - 2].fi);
			if (i + 2 < n) ok &= int (v[i + 1].fi - v[i - 1].fi == v[i + 2].fi - v[i + 1].fi);
			if (ok) {
				printf ("%d\n", v[i].se);
				re 0;
			}
		}
	printf ("-1\n");
	re 0;
}