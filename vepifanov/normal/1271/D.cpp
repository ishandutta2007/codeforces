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
int k;

int a[5000];
int b[5000];
int c[5000];
int fr[5000];
vi v[5000];
multiset<int> now;

int main () {
	scanf ("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++) scanf ("%d%d%d", &a[i], &b[i], &c[i]);
	for (int i = 0; i < n; i++) fr[i] = i;
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf ("%d%d", &a, &b); a--; b--;
		fr[b] = max (fr[b], a);
	}
	for (int i = 0; i < n; i++) v[fr[i]].pb (c[i]);
	int ans = 0, cur = k;
	for (int i = 0; i < n; i++) {
		if (cur < a[i]) {
			printf ("-1\n");
			re 0;
		}
		while (sz (now) > cur - a[i]) {
			ans -= *now.begin();
			now.erase (now.begin ());
		}
		cur += b[i];
		for (auto x : v[i]) {
			now.insert (x);
			ans += x;
		}
	}
	while (sz (now) > cur) {
		ans -= *now.begin();
		now.erase (now.begin ());
	}
	printf ("%d\n", ans);
	re 0;
}