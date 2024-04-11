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

const int N = 1 << 18;

int n;
int m;
char h[N];
int p[N];
int q[N];
int f[N];

int get (char c, int x, int y) {
	if (c == '?') re x + y;
	if (c == '0') re x;
	re y;
}

int main () {
	scanf ("%d", &n);
	m = (1 << n) - 1;
	scanf (" %s", h);
	int o = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (1 << (n - i - 1)); j++) {
			p[(1 << (n - i - 1)) - 1 + j] = o + j;
			q[o + j] = (1 << (n - i - 1)) - 1 + j;			
		}	
		o += (1 << (n - i - 1));
	}
	for (int i = m - 1; i >= 0; i--)
		if (2 * i + 1 < m) f[i] = get (h[p[i]], f[2 * i + 1], f[2 * i + 2]); else f[i] = get (h[p[i]], 1, 1);
	int q;
	scanf ("%d", &q);
	for (int i = 0; i < q; i++) {
		int x;
		char s[5];
		scanf ("%d %s", &x, s); x--;
		h[x] = s[0];
		int y = ::q[x];
		while (true) {
			if (2 * y + 1 < m) f[y] = get (h[p[y]], f[2 * y + 1], f[2 * y + 2]); else f[y] = get (h[p[y]], 1, 1);
			if (y == 0) break;
			y = (y - 1) / 2;
		}
/*		for (int j = 0; j < m; j++) printf ("%c", h[p[j]]);
		printf (" = ");
		for (int j = 0; j < m; j++) printf ("%d ", f[j]);
		printf ("\n");*/
		printf ("%d\n", f[0]);
	}
	re 0;
}