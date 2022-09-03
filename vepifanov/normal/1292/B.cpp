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

ll x[100];
ll y[100];
ll ax, ay, bx, by, xs, ys, t;

ll dist (ll x1, ll y1, ll x2, ll y2) {
	re abs (x2 - x1) + abs (y2 - y1);
}

int main () {
	cin >> x[0] >> y[0] >> ax >> ay >> bx >> by >> xs >> ys >> t;
	int n = 1;
	while (true) {
		x[n] = x[n - 1] * ax + bx;
		y[n] = y[n - 1] * ay + by;
		if (x[n] > xs + t || y[n] > ys + t) break;
		n++;
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++) {
			ll need = min (dist (xs, ys, x[i], y[i]), dist (xs, ys, x[j], y[j])) + dist (x[i], y[i], x[j], y[j]);
			if (need <= t) ans = max (ans, j - i + 1);
		}
	printf ("%d\n", ans);	
	re 0;
}