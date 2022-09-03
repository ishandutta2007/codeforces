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

const int N = 1000;

int n;
int m;
int x, y, z;
int f[N + 1][3];
int per;
ll p[300000];

int mex (int a, int b, int c) {
	int d = 0;
	while (d == a || d == b || d == c) d++;
	re d;
}

int get (ll x, int y) {
	if (x <= N) re f[x][y];
	int xx = x - (x - N + per - 1) / per * per; 
	re f[xx][y];
}

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf ("%d%d%d%d", &n, &x, &y, &z);
		f[0][0] = f[0][1] = f[0][2] = 0;
		for (int i = 1; i <= N; i++) {
			f[i][0] = mex (f[max (i - x, 0)][0], f[max (i - y, 0)][1], f[max (i - z, 0)][2]);
			f[i][1] = mex (f[max (i - x, 0)][0], -1, f[max (i - z, 0)][2]);
			f[i][2] = mex (f[max (i - x, 0)][0], f[max (i - y, 0)][1], -1);
//			if (i < 10) printf ("%d: %d %d %d\n", i, f[i][0], f[i][1], f[i][2]);
		}
		per = 1;
		while (true) {
			int ok = 1;
			for (int i = N; i >= N / 2 && ok; i--)
				for (int j = 0; j < 3 && ok; j++)
					ok &= int (f[i][j] == f[i - per][j]);
			if (ok) break;
			per++;
		}
//		printf ("per = %d\n", per);
		int cur = 0;
		for (int i = 0; i < n; i++) {
			scanf ("%lld", &p[i]);
			cur ^= get (p[i], 0);
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if ((cur ^ get (p[i], 0) ^ get (max (p[i] - x, 0LL), 0)) == 0) ans++; 
			if ((cur ^ get (p[i], 0) ^ get (max (p[i] - y, 0LL), 1)) == 0) ans++; 
			if ((cur ^ get (p[i], 0) ^ get (max (p[i] - z, 0LL), 2)) == 0) ans++; 
		}
		printf ("%d\n", ans);
	}
	re 0;
}