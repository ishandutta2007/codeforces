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

const int pr[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

int n;
int m;
int x[1000];
int was[11];

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf ("%d", &n);
		memset (was, 0, sizeof (was));
		for (int i = 0; i < n; i++) {
			scanf ("%d", &x[i]);
			for (int j = 0; j < 11; j++)
				if (x[i] % pr[j] == 0) {
					was[j] = 1;
					break;
				}
		}
		int r = 0;
		for (int i = 0; i < 11; i++) 
			if (was[i])
				was[i] = ++r;
		printf ("%d\n", r);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < 11; j++)
				if (x[i] % pr[j] == 0) {
					printf ("%d ", was[j]);
					break;
				}
		printf ("\n");
	}
	re 0;
}