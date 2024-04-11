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
mt19937 rng (0);
int y[2048];
int zero = -1;
int res[2048];
//int p[2048];
int cnt = 0;

int ask (int x, int y) {
	cnt++;
	assert (x != y);
//	printf ("%d: ? %d %d\n", cnt, x + 1, y + 1);
	printf ("? %d %d\n", x + 1, y + 1);
	fflush (stdout);
	int z;
	scanf ("%d", &z);
	re z;
//	re p[x] | p[y];
}

int go (vi v) {
	if (sz (v) == 1) {
		zero = v[0];
		re 0;
	}
	shuffle (all (v), rng);
	int x;
	int cur;
	int cnt;
	int now = 0;
	do {
		x = abs ((int)rng ()) % sz (v);
		cur = 2047;
		cnt = 0;
		for (int i = 0; i < sz (v); i++)
			if (i != x) {
				now++;
				y[i] = ask (v[i], v[x]);
				if ((cur & y[i]) != cur) cnt = 0;
				cur &= y[i];
				/*if (y[i] == cur) {
					cnt++;
					if (cnt >= 16 && __builtin_popcount (cur) > 6) {
						printf ("");
						cur = -1;
						break;
					}
				}*/
				if (i >= 32 && __builtin_popcount (cur) > 6) {
					cur = -1;
					break;
				}
//				printf ("%d = %d\n", cur, i);
			}
	} while (cur == -1);
	if (cur == 0) {
		zero = v[x];
		re 0;
	}
	vi w;
	for (int i = 0; i < sz (v); i++)
		if (i != x && y[i] == cur)
			w.pb (v[i]);
	go (w);
	re 0;
}

int main () {
	scanf ("%d", &n);
/*	for (int i = 0; i < n; i++) p[i] = i;
	shuffle (p, p + n, rng);*/
	vi v(n);
	for (int i = 0; i < n; i++) v[i] = i;
	go (v);
	for (int i = 0; i < n; i++)
		if (i == zero)
			res[i] = 0;
		else
			res[i] = ask (i, zero);	
	printf ("!");
	for (int i = 0; i < n; i++) printf (" %d", res[i]);
	printf ("\n");
	fflush (stdout);
/*	printf ("!");
	for (int i = 0; i < n; i++) printf (" %d", p[i]);
	printf ("\n");
	for (int i = 0; i < n; i++) assert (res[i] == p[i]);
	assert (cnt <= 4269);*/
	re 0;
}