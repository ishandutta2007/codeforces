#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
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

int x[100001];
int y[100001];
int sx[100001];
int sy[100001];

ll calcx (int h) {
	int rem = (n + h) / 4;
	if (rem < n) re sx[n] + (ll)h * 100 - sx[rem];
	re (ll)(n + h - rem) * 100;
}

ll calcy (int h) {
	int rem = (n + h) / 4;
	if (rem < h) re sy[n];
	re sy[n] - sy[rem - h];
}

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {	
		scanf ("%d", &n);
		for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
		for (int i = 0; i < n; i++) scanf ("%d", &y[i]);
		sort (x, x + n);
		sort (y, y + n);
		sx[0] = sy[0] = 0;
		for (int i = 0; i < n; i++) {
			sx[i + 1] = sx[i] + x[i];
			sy[i + 1] = sy[i] + y[i];
		}
		int l = -1, r = 1e8;
		while (r - l > 1) {
			int s = (l + r) / 2;
			if (calcx (s) >= calcy (s)) r = s; else l = s;
		}
		printf ("%d\n", r);
	}
    re 0;
}