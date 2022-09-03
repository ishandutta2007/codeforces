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
int x[8000];
ii y[8000];
int good[8000];

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf ("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf ("%d", &x[i]);
			y[i].fi = x[i];
			y[i].se = i;
			good[i] = 0;
		}
		sort (y, y + n);
		for (int i = 0; i < n; i++) {
			int cur = x[i];
			for (int j = i + 1, k = 0; j < n && k < n; j++) {
				cur += x[j];
				while (k < n && y[k].fi < cur) k++;
				if (k == n) break;
				while (k < n && y[k].fi == cur) {
					good[y[k].se] = 1;
					k++;
				}
			}
		}
		int ans = accumulate (good, good + n, 0);
		printf ("%d\n", ans);
	}
	re 0;
}