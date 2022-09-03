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
int p[1000];
ll res[1000];
int q[1000];

mt19937 rng(0);

ll ask (int i, int j) {
	vi v;
	for (int k = 0; k < n; k++)
		if (((q[k] >> i) & 1) == j)
			v.pb (k);
	if (v.empty ()) re 0;
	printf ("? %d", sz (v));
	for (int i = 0; i < sz (v); i++) printf (" %d", v[i] + 1);
	printf ("\n");
	fflush (stdout);
	ll x;
	scanf ("%lld", &x);
	for (int k = 0; k < n; k++)
		if (((q[k] >> i) & 1) != j)
			res[k] |= x;
	re x;
}

ll askdet (int k) {
	printf ("? 1 %d\n", k + 1);
	fflush (stdout);
	ll x;
	scanf ("%lld", &x);
	for (int i = 0; i < n; i++)
		if (i != k)
			res[i] |= x;
	re x;
}

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) p[i] = i;
	for (int i = 0; i < n; i++) res[i] = 0;
	int r = 0;
	for (int i = 0; i < (1 << 13) && r < n; i++)
		if (__builtin_popcount (i) == 6)
			q[r++] = i;
	for (int i = 0; i < 13; i++) 
		for (int j = 0; j < 1; j++)
			ask (i, j);
	printf ("!");
	for (int i = 0; i < n; i++) printf (" %lld", res[i]);
	printf ("\n");
	fflush (stdout);
	re 0;
}