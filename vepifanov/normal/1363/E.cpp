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

const int N = 200000;

int n;
int m;
int a[N];
int b[N];
int c[N];
vi v[N];

ll ans = 0;

int go (int x, int p, int cur) {
	cur = min (cur, a[x]);
	int pos = int (b[x] > c[x]), neg = int (b[x] < c[x]);
	for (auto y : v[x])
		if (y != p) {
			int tmp = go (y, x, cur);
			if (tmp > 0) pos += tmp; else neg -= tmp;
		}
	ans += (ll)cur * min (pos, neg) * 2;
	re pos - neg;
}

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) scanf ("%d%d%d", &a[i], &b[i], &c[i]);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		scanf ("%d%d", &a, &b); a--; b--;
		v[a].pb (b);
		v[b].pb (a);
	}
	if (go (0, 0, 1e9) != 0) ans = -1;
	cout << ans << endl;
	re 0;
}