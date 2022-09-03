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

int x[100000];
int y[100000];

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf ("%d", &n);
		for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
		for (int i = 0; i < n; i++) scanf ("%d", &y[i]);
		int ok = 1, pos = 0, neg = 0;
		for (int i = 0; i < n; i++) {
			if (y[i] > x[i] && !pos) ok = 0;
			if (y[i] < x[i] && !neg) ok = 0;
			pos |= int (x[i] > 0);
			neg |= int (x[i] < 0);
		}
		printf ("%s\n", ok ? "YES" : "NO");
	}
	re 0;
}