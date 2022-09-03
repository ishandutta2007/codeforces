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

ll right (int x1, int y1, int x2, int y2) {
	if (x1 == x2) re 0;
	x1++;
	re (ll)(x2 - x1 + 1) * (2 * y1 - 2) + (ll)(x1 + x2) * (x2 - x1 + 1) / 2;
}

ll down (int x1, int y1, int x2, int y2) {
	if (y1 == y2) re 0;
	y1++;
	re (ll)(y2 - y1 + 1) * (x1 - 2) + (ll)(y1 + y2) * (y2 - y1 + 1);
}

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		int x1, y1, x2, y2;
		scanf ("%d%d%d%d", &x1, &y1, &x2, &y2);
		ll s1 = right (x1, y1, x2, y1) + down (x2, y1, x2, y2);
		ll s2 = down (x1, y1, x1, y2) + right (x1, y2, x2, y2);
		printf ("%lld\n", s2 - s1 + 1);
	}
	re 0;
}