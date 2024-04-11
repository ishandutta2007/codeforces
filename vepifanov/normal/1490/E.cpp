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
ii v[200000];

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf ("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf ("%d", &v[i].fi);
			v[i].se = i;
		}
		sort (v, v + n);
		ll sum = 0;
		int top = 0;
		for (int i = 0; i < n; i++) {
			if (v[i].fi > sum) top = i;
			sum += v[i].fi;
		}
		vi res;
		for (int i = top; i < n; i++) res.pb (v[i].se);
		sort (all (res));
		printf ("%d\n", sz (res));
		for (int i = 0; i < sz (res); i++) printf ("%d ", res[i] + 1);
		printf ("\n");
	}
	re 0;
}