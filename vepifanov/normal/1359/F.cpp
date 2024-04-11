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

const int N = 25000;

int n;
int m;
int x[N];
int y[N];
int dx[N];
int dy[N];
int s[N];
double rv[N];

double dist (int x1, int y1, int x2, int y2) {
	re sqrt (sqr (x2 - x1) + sqr (y2 - y1) + 0.0);
}

bool cross (int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, double& t, double& s) {
	int a = x2 - x1;
	int b = x3 - x4;
	int c = x3 - x1;
	int d = y2 - y1;
	int e = y3 - y4;
	int f = y3 - y1;
	int p = c * e - b * f;
	int q = a * f - c * d;
	int r = a * e - b * d;
	if (r < 0) {
		p = -p;
		q = -q;
		r = -r;
	}
	if (p >= 0 && q >= 0) {
		t = (p + 0.0) / r;
		s = (q + 0.0) / r;
		return true;
	}
	return false;
}

int vect (int x1, int y1, int x2, int y2) {
	re x1 * y2 - x2 * y1;
}

int scal (int x1, int y1, int x2, int y2) {
	re x1 * x2 + y1 * y2;
}

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf ("%d%d%d%d%d", &x[i], &y[i], &dx[i], &dy[i], &s[i]);
		int d = gcd (abs (dx[i]), abs (dy[i]));
		dx[i] /= d;
		dy[i] /= d;
		rv[i] = sqrt (sqr (dx[i]) + sqr (dy[i]) + 0.0) / s[i];
	}
	double ans = 1e18;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++) {
			if (dx[i] == dx[j] && dy[i] == dy[j]) {
				if (vect (x[j] - x[i], y[j] - y[i], dx[i], dy[i]) == 0) {
					if (scal (x[j] - x[i], y[j] - y[i], dx[i], dy[i]) > 0) {
						ans = min (ans, dist (x[i], y[i], x[j], y[j]) / s[i]);
						continue;
					} else {
						ans = min (ans, dist (x[i], y[i], x[j], y[j]) / s[j]);
						continue;
					}
				} else continue;
			} else
			if (dx[i] == -dx[j] && dy[i] == -dy[j]) {
				if (vect (x[j] - x[i], y[j] - y[i], dx[i], dy[i]) == 0 && scal (x[j] - x[i], y[j] - y[i], dx[i], dy[i]) > 0) {
					ans = min (ans, dist (x[i], y[i], x[j], y[j]) / (s[i] + s[j]));
				} else continue;				
			}
			double t, s;
			if (cross (x[i], y[i], x[i] + dx[i], y[i] + dy[i], x[j], y[j], x[j] + dx[j], y[j] + dy[j], t, s))
				ans = min (ans, max (t * rv[i], s * rv[j]));
		}	
	if (ans > 1e17)	printf ("No show :(\n"); else printf ("%.10f\n", ans);
//	cerr << clock () << endl;
	re 0;
}