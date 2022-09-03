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
int ct;
int tin[200000];
int tout[200000];
vi v[200000];
int par[200000];
ii p[200000];

int go (int x, int p) {
	tin[x] = ct++;
	par[x] = p;
	for (auto y : v[x])
		if (y != p)
			go (y, x);
	tout[x] = ct++;
	re 0;
}

int main () {
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		scanf ("%d%d", &a, &b); a--; b--;
		v[a].pb (b);
		v[b].pb (a);
	}
	go (0, 0);
	for (int i = 0; i < m; i++) {
		int k;
		scanf ("%d", &k);
		for (int i = 0; i < k; i++) {
			int x;
			scanf ("%d", &x); x--;
			p[i].fi = tin[par[x]];
			p[i].se = par[x];
		}
		sort (p, p + k);
		int ok = 1;
		for (int i = 0; i + 1 < k; i++)
			ok &= int (tin[p[i].se] <= tin[p[i + 1].se] && tout[p[i].se] >= tout[p[i + 1].se]);
		printf ("%s\n", ok ? "YES" : "NO");
	}
	re 0;
}