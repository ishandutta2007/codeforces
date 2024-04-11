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

const int inf = 1e9 + 100;
 
int n;
int m;
vi v[1000];
int x[1000];
int y[1000];
int good[1000];
int was[1000];
int prev[1000];
int q[1000];
int d[1000];

int add (int i) {
	int sum = 0;
	while (!good[i]) {
		good[i] = 1;
		sum = min (sum + y[i], inf);
//		printf ("add %d %d %d = %d:\n", i + 1, x[i], y[i], sum);
		i = prev[i];
	}
	re sum;
}

int check (int h) {
//	printf ("check %d:\n", h);
	for (int i = 0; i < n; i++) good[i] = 0;
	good[0] = 1;
	while (true) {
//		printf ("new h %d\n", h);
		int l = 0, r = 0;
		int ok = 0;
		for (int i = 0; i < n; i++) was[i] = 0;
		for (int i = 0; i < n && !ok; i++)
			if (good[i])
				for (auto j : v[i])
					if (!good[j] && h > x[j]) {
						if (!was[j]) {
							prev[j] = i;
							d[j] = h;
							was[j] = 1;
							q[r++] = j;
						} else {
							h = min (h + add (j), inf);
							ok = 1;
							break;
						}
					}
		if (ok) continue;
		while (l < r) {
			int i = q[l++];
//			printf ("%d %d %d\n", i, d[i], prev[i]);
			for (auto j : v[i]) {
				if (j == prev[i]) continue;
				if (good[j]) {
					h = min (h + add (i), inf);
					ok = 1;
					break;
				}
				if (!good[j] && d[i] + y[i] > x[j]) {
					if (!was[j]) {
						prev[j] = i;
						d[j] = min (d[i] + y[i], inf);
						was[j] = 1;
						q[r++] = j;
					} else {
						h = min (h + add (i), inf);
						h = min (h + add (j), inf);
						ok = 1;
						break;
					}
				}
			}	
			if (ok) break;	
		}
		if (!ok) break;
	}
	for (int i = 0; i < n; i++)
		if (!good[i]) re 0;
	re 1;
}

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf ("%d%d", &n, &m);
		for (int i = 0; i < n; i++) v[i].clear ();
		for (int i = 1; i < n; i++) scanf ("%d", &x[i]);
		for (int i = 1; i < n; i++) scanf ("%d", &y[i]);
		for (int i = 0; i < m; i++) {
			int a, b;
			scanf ("%d%d", &a, &b); a--; b--;
			v[a].pb (b);
			v[b].pb (a);
		}
		int l = 0, r = inf;
		while (r - l > 1) {
			int s = (l + r) / 2;
			if (check (s)) r = s; else l = s;
		}
		printf ("%d\n", r);
	}
    re 0;
}