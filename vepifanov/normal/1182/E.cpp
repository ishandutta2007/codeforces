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

const int mod = 1000*1000*1000+7;
const int mod2 = 1000*1000*1000+6;

ll n, f1, f2, f3, c;

struct val {
	int c0, c1, c2, c3;
	val () {
		c0 = c1 = c2 = c3 = 0;
	}
	val (int a, int b, int c, int d) {
		c0 = a;
		c1 = b;
		c2 = c;
		c3 = d;
	}
};

val operator+ (const val& a, const val& b) {
	re val ((a.c0 + b.c0) % mod2, (a.c1 + b.c1) % mod2, (a.c2 + b.c2) % mod2, (a.c3 + b.c3) % mod2);
}

val operator* (const val& a, int b) {
	re val ((ll)a.c0 * b % mod2, (ll)a.c1 * b % mod2, (ll)a.c2 * b % mod2, (ll)a.c3 * b % mod2);
}

val e[5];
val u[5];
int g[5][5];
int h[5][5];

int power (int a, int b) {
	int c = 1;
	while (b) {
		if (b & 1) c = ((ll)c * a) % mod;
		a = ((ll)a * a) % mod;
		b /= 2;
	}
	re c;
}

int main () {
	cin >> n >> f1 >> f2 >> f3 >> c;
	e[0] = val (1, 0, 0, 0);
	e[1] = val (0, 1, 0, 0);
	e[2] = val (0, 0, 1, 0);
	e[3] = val (0, 0, 0, 2);
	e[4] = val (0, 0, 0, 1);
	g[1][0] = g[2][1] = g[0][2] = g[1][2] = g[2][2] = g[3][2] = g[3][3] = g[4][4] = 1;
	g[4][3] = 2;
	n -= 3;
	while (n) {
		if (n & 1) {
			for (int i = 0; i < 5; i++) {
				u[i] = val ();
				for (int j = 0; j < 5; j++)
					u[i] = u[i] + e[j] * g[j][i];
			}
			for (int i = 0; i < 5; i++) e[i] = u[i];
		}
		n /= 2;
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++) {
				h[i][j] = 0;
				for (int k = 0; k < 5; k++)
					h[i][j] = (h[i][j] + (ll)g[i][k] * g[k][j]) % mod2;
			}
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				g[i][j] = h[i][j];
	}
	int ans = (ll)power (f1, e[2].c0) * power (f2, e[2].c1) % mod * power (f3, e[2].c2) % mod * power (c, e[2].c3) % mod;
	printf ("%d\n", ans);
	re 0;
}