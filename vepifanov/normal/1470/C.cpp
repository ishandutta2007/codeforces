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

int ask (int x) {
	printf ("? %d\n", x + 1);
	fflush (stdout);
	int y;
	scanf ("%d", &y);
	re y;
}

int main () {
	scanf ("%d%d", &n, &m);
	mt19937 rng (0);
	while (true) {
		int x = rng() % n;
		int y = ask (x);
		if (y > m) {
			while (true) {
				x = (x + n - 1) % n;
				int z = ask (x);
				if (z == m) {
					printf ("! %d\n", x + 1);
					fflush (stdout);
					re 0;
				}
			}
		} else
		if (y < m) {
			while (true) {
				x = (x + 1) % n;
				int z = ask (x);
				if (z == m) {
					printf ("! %d\n", x + 1);
					fflush (stdout);
					re 0;
				}
			}
		}
	}
	re 0;
}