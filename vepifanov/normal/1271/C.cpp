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
int sx, sy;
int x[200000];
int y[200000];

int calc (int xx, int yy) {
	int cur = 0;
	for (int i = 0; i < n; i++)
		if (xx >= min (sx, x[i]) && xx <= max (sx, x[i]) && yy >= min (sy, y[i]) && yy <= max (sy, y[i]))
			cur++;
	re cur;
}

int main () {
	scanf ("%d%d%d", &n, &sx, &sy);
	for (int i = 0; i < n; i++) scanf ("%d%d", &x[i], &y[i]);
	int ans = 0, ax, ay;
	for (int t = 0; t < 4; t++) {
		int xx = sx - int (t == 0) + int (t == 1);
		int yy = sy - int (t == 2) + int (t == 3);
		int cur = calc (xx, yy);
		if (cur > ans) {
			ans = cur;
			ax = xx;
			ay = yy;
		}
	}
	printf ("%d\n%d %d\n", ans, ax, ay);
	re 0;
}