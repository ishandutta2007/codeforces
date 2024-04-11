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
		int a, b, c, d;
		int x, y, x1, y1, x2, y2;
		scanf ("%d%d%d%d", &a, &b, &c, &d);
		scanf ("%d%d%d%d%d%d", &x, &y, &x1, &y1, &x2, &y2);
		if (x - a + b >= x1 && x - a + b <= x2 && y - c + d >= y1 && y - c + d <= y2 && (a + b == 0 || x2 - x1 > 0) && (c + d == 0 || y2 - y1 > 0)) printf ("Yes\n"); else printf ("No\n");
	}
	re 0;
}