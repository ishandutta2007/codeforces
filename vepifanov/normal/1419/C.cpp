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

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf ("%d%d", &n, &m);
		int sum = 0, eq = 0;
		for (int i = 0; i < n; i++) {
			int x;
			scanf ("%d", &x);
			sum += x;
			eq += int (x == m);
		}
		int ans = 0;
		if (eq == n) {
			ans = 0;
		} else
		if (sum == m * n) {
			ans = 1;
		} else
		if (eq == 0) {
			ans = 2;
		} else {
			ans = 1;
		}
		printf ("%d\n", ans);
	}
	re 0;
}