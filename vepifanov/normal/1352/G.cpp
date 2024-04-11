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
int p[10];
int res[10][10];

int main () {
	for (int n = 6; n < 10; n++) {
		for (int i = 0; i < n; i++) p[i] = i;
		do {
			int ok = 1;
			for (int i = 0; i + 1 < n; i++) ok &= int (abs (p[i] - p[i + 1]) >= 2 && abs (p[i] - p[i + 1]) <= 4);
			if (ok) {
				for (int i = 0; i < n; i++) res[n][i] = p[i];
				break;
			}
		} while (next_permutation (p, p + n));
	}
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf ("%d", &n);
		if (n == 4) {
			printf ("3 1 4 2\n");
			continue;
		}
		if (n < 5) {
			printf ("-1\n");
			continue;
		}
		int cur = 1;
		while (n >= 10 || n == 5) {
			printf ("%d %d %d %d %d ", cur, cur + 3, cur + 1, cur + 4, cur + 2);
			cur += 5;
			n -= 5;
		}
		for (int i = 0; i < n; i++) printf ("%d ", cur + res[n][i]);
		printf ("\n");
	}
	re 0;
}