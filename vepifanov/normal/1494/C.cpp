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
int same[200000];

int calc (vi& a, vi& b) {
	sort (all (a));
	sort (all (b));
	n = sz (a);
	m = sz (b);
	int ans = 0;
	int cur = 0;
	for (int i = n, j = m; j > 0; j--) {
		while (i > 0 && a[i - 1] > b[j - 1]) i--;
		int l = 0, r = j + 1;
		while (r - l > 1) {
			int s = (l + r) / 2;
			if (b[s - 1] + i > b[j - 1]) r = s; else l = s;
		}
		ans = max (ans, cur + j - r + 1);
//		printf ("%d = %d + %d/%d\n", b[j - 1], cur, same[j - 1], i);
		if (i > 0 && a[i - 1] == b[j - 1]) cur++;
	}
	re ans;
}

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		vi a1, a2, b1, b2;
		scanf ("%d%d", &n, &m);
		for (int i = 0; i < n; i++) {
			int x;
			scanf ("%d", &x);
			if (x > 0) a1.pb (x); else a2.pb (-x);
		}
		for (int i = 0; i < m; i++) {
			int x;
			scanf ("%d", &x);
			if (x > 0) b1.pb (x); else b2.pb (-x);
		}
		printf ("%d\n", calc (a1, b1) + calc (a2, b2));
	}
	re 0;
}