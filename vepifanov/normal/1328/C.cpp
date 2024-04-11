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
char h[500010];
int a[500010];
int b[500010];

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf ("%d", &n);
		scanf (" %s", h);
		int ok = 1;
		for (int i = 0; i < n; i++)
			if (h[i] == '0')
				a[i] = b[i] = 0;
			else
			if (h[i] == '1') {
				if (ok) {
					a[i] = 1;
					b[i] = 0;
					ok = 0;
				} else {
					a[i] = 0;
					b[i] = 1;
				}
			} else {
				if (ok) {
					a[i] = 1;
					b[i] = 1;
				} else {
					a[i] = 0;
					b[i] = 2;
				}
			}
		for (int i = 0; i < n; i++) printf ("%d", a[i]);
		printf ("\n");
		for (int i = 0; i < n; i++) printf ("%d", b[i]);
		printf ("\n");
	}
	re 0;
}