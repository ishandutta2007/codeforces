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
int x[100000];

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf ("%d", &n);
		for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
		vi res;
		for (int i = 0; i < n; ) {
			res.pb (x[i]);
			int j = i;
			while (j + 1 < n && x[j + 1] == x[i]) j++;
			int k = j;
			if (k + 1 == n) break;
			while (k + 1 < n && (x[k + 1] == x[k] || int (x[k + 1] < x[k]) == int (x[j + 1] < x[j]))) k++;
			i = k;
		}
		if (sz (res) == 1) res.pb (x[n - 1]);
		printf ("%d\n", sz (res));
		for (int i = 0; i < sz (res); i++) printf ("%d ", res[i]);
		printf ("\n");
	}
	re 0;
}