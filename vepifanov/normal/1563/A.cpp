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
int a, b;
int can[200001];

int check (int x, int y) {
	int xa = min (x, a);
	int yb = min (y, b);
	int xb = x - xa;
	int ya = y - yb;
	int l = xb + ya;
	xb = min (x, b);
	ya = min (y, a);
	xa = x - xb;
	yb = y - ya;
	int r = xb + ya;
	for (int i = l; i <= r; i += 2) can[i] = 1;
	re 0;
}

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf ("%d%d", &a, &b);
		n = a + b;
		for (int i = 0; i <= n; i++) can[i] = 0;
		check ((a + b + 1) / 2, (a + b) / 2);
		check ((a + b) / 2, (a + b + 1) / 2);
		int ans = 0;
		for (int i = 0; i <= n; i++) ans += can[i];
		printf ("%d\n", ans);
		for (int i = 0; i <= n; i++)
			if (can[i])
				printf ("%d ", i);
		printf ("\n");
	}
    re 0;
}