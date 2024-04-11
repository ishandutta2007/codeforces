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
		scanf ("%d", &n);
		if (n == 1) printf ("FastestFinger\n"); else
		if (n == 2) printf ("Ashishgup\n"); else
		if (n % 2 == 1) printf ("Ashishgup\n"); else {
			if ((n & (n - 1)) == 0) printf ("FastestFinger\n"); else {
				int ok = 1;
				n /= 2;
				for (int j = 2; j * j <= n; j++)
					if (n % j == 0) {
						ok = 0;
						break;
					}	
				if (ok) printf ("FastestFinger\n"); else printf ("Ashishgup\n");
			}
		}
	}
	re 0;
}