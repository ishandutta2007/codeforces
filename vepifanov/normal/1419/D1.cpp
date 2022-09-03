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
int x[100100];
int y[100100];

int can (int h) {
	if (2 * h + 1 > n) re 0;
	for (int i = 0; i < h; i++)
		if (!(x[i] < x[n - h - 1 + i] && x[i] < x[n - h + i])) {
//			printf ("%d: %d %d %d\n", h, x[n - h - 1 + i], x[i], x[n - h + i]);
			re 0;
		}
	for (int i = 0; i < h; i++) {
		y[2 * i] = x[n - h - 1 + i];
		y[2 * i + 1] = x[i];
		y[2 * i + 2] = x[n - h + i];
	}
	for (int i = 0; i < n - 2 * h + 1; i++)
		y[2 * h + 1 + i] = x[h + i];
	re 1;
}

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
	sort (x, x + n);
	int l = 0, r = (n + 1) / 2;
	while (r - l > 1) {
		int s = (l + r) / 2;
		if (can (s)) l = s; else r = s;
	}
	can (l);
	printf ("%d\n", l);
	if (l == 0) {
		for (int i = 0; i < n; i++) printf ("%d ", x[i]);
		printf ("\n");
	} else {
		for (int i = 0; i < n; i++) printf ("%d ", y[i]);
		printf ("\n");
	}	
	re 0;
}