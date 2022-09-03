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
set<int> all;
int x[100000];
int y[100000];

int main () {
	scanf ("%d", &n);
	for (int i = 0; i <= n + 1; i++) all.insert (i);
	for (int i = 0; i < n; i++) {
		scanf ("%d", &x[i]);
		all.erase (x[i]);
	}
	for (int i = 0; i < n; i++) {
		y[i] = *all.begin ();
		if (y[i] <= n) all.erase (y[i]);
		if (i + 1 < n && x[i + 1] > x[i]) all.insert (x[i]);
	}
	all.clear ();
	for (int i = 0; i <= n + 1; i++) all.insert (i);
	for (int i = 0; i < n; i++) {
		all.erase (y[i]);
		if (*all.begin () != x[i]) {
			printf ("-1\n");
			re 0;
		}
	}
	for (int i = 0; i < n; i++) printf ("%d ", y[i]);
	printf ("\n");
	re 0;
}