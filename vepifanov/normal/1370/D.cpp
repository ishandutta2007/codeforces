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
vii v;
int x[200000];
int was[200000];

int can (int h) {
	for (int i = 0; i < n; i++) was[i] = 0;
	for (int i = 0; i < h; i++) was[v[i].se] = 1;
	int cur0 = 0, last0 = -1, cur1 = 0, last1 = -2;
	for (int i = 0; i < n; i++)
		if (was[i]) {
			if (i > last0 + 1) {
				cur0++;
				last0 = i;
			}
			if (i > last1 + 1) {
				cur1++;
				last1 = i;
			}
		}
//	printf ("%d = %d %d %d %d\n", h, cur0, last0, cur1, last1);
	if (2 * cur0 + int (last0 + 1 < n) >= m) re 1;
	if (2 * cur1 - 1 + int (last1 + 1 < n) >= m) re 1;
	re 0;
}

int main () {
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf ("%d", &x[i]);
		v.pb (mp (x[i], i));
	}
	sort (all (v));
	int l = 0, r = n;
	while (r - l > 1) {
		int s = (l + r) / 2;
		if (can (s)) r = s; else l = s;
	}
	printf ("%d\n", v[r - 1].fi);
	re 0;
}