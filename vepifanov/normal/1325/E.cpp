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

const int N = 1000000;
const int NP = 80000;
const int NSP = 168;

int n;
int m;
int r = 0;

int f[N + 1];
int p[N + 1];
int q[NP];
int one[NP];
int par[NP];
vi w[NP];
set<ii> all;
int d[NP];

int main () {
	for (int i = 2; i <= N; i++)
		if (!f[i]) {
			f[i] = i;
			q[r] = i;
			p[i] = r++;
			if (i <= N / i)
				for (int j = i * i; j <= N; j += i)
					f[j] = i;
		}
	scanf ("%d", &n);
	int ans = n + 1;
	for (int i = 0; i < n; i++) {
		int x;
		scanf ("%d", &x);
		vi v;
		while (x > 1) {
			int j = f[x];
			int k = 0;
			while (x % j == 0) {
				x /= j;
				k ^= 1;
			}
			if (k) v.pb (p[j]);
		}
		if (sz (v) == 0) ans = 1; else
		if (sz (v) == 1) {
			one[v[0]]++;
			if (one[v[0]] >= 2) ans = min (ans, 2);
		} else {
			if (all.count (mp (v[0], v[1]))) ans = min (ans, 2); else {
				all.insert (mp (v[0], v[1]));
				all.insert (mp (v[1], v[0]));
				w[v[0]].pb (v[1]);
				w[v[1]].pb (v[0]);
			}
		}
	}
	for (int i = 0; i < NSP; i++) {
		int l = 0, r = 1;
		q[0] = i;
		for (int j = 0; j < NP; j++)
			d[j] = -1;
		ii b1 (1e9, -1);
		ii b2 (1e9, -1);
		d[i] = 0;
		while (l < r) {
			int x = q[l++];
			if (one[x] == 1) {
				ii b (d[x], x);
				if (b < b1) { b2 = b1; b1 = b; } else
				if (b < b2) { b2 = b; }
			}
//			printf ("%d %d = %d\n", i, x, d[x]);
			for (auto y : w[x])
				if (d[y] == -1) {
					q[r++] = y;
					d[y] = d[x] + 1;
					par[y] = x;
				} else
					if (par[x] != y && d[x] + d[y] + 1 >= 3)
						ans = min (ans, d[x] + d[y] + 1);
		}
		if (b1.se != -1 && b2.se != -1) ans = min (ans, b1.fi + b2.fi + 2);
	}
	if (ans == n + 1) ans = -1;
	printf ("%d\n", ans);
	re 0;
}