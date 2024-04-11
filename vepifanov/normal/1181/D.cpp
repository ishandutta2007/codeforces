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
int q;
vector<pair<ll, int> > v;
vector<pair<ll, int> > w;
vector<pair<ll, int> > u;
int tree[1 << 20];
int cnt[500000];
int res[500000];

int add (int x, int l, int r, int y) {
	if (r < y || l > y) re tree[x];
	if (l == r) re tree[x] = tree[x] + 1;
	int s = (l + r) / 2;
	re tree[x] = add (x * 2 + 1, l, s, y) + add (x * 2 + 2, s + 1, r, y);
}

int get (int x, int l, int r, int y) {
	if (l == r) re l + 1;
	int s = (l + r) / 2;
	if (tree[x * 2 + 1] >= y) re get (x * 2 + 1, l, s, y);
	re get (x * 2 + 2, s + 1, r, y - tree[x * 2 + 1]);
}

int main () {
	scanf ("%d%d%d", &n, &m, &q);
	for (int i = 0; i < n; i++) {
		int x;
		scanf ("%d", &x); x--;
		cnt[x]++;
	}
	for (int i = 0; i < q; i++) {
		ll x;
		scanf ("%lld", &x);
		v.pb (mp (x, i));
	}
	for (int i = 0; i < m; i++) w.pb (mp (cnt[i], i));
	sort (all (w));
	for (int i = 0; i < m; ) {
		int j = i;
		while (j < m && w[j].fi == w[i].fi) j++;
		u.pb (mp (w[i].fi, j - i));
		i = j;
	}
	reverse (all (u));
	int pos = 0;
	while (pos < u[sz (u) - 1].se) {
//		printf ("add %d\n", w[pos].se + 1);
		add (0, 0, m - 1, w[pos].se);
		pos++;
	}
	sort (all (v));
	ll cur = n;
	for (int i = 0; i < q; i++) {
//		printf ("u = %d %lld %lld | %d | %lld %lld\n", sz (u), u[sz (u) - 2].fi, u[sz (u) - 1].fi, u[sz (u) - 1].se, cur + (u[sz (u) - 2].fi - u[sz (u) - 1].fi) * u[sz (u) - 1].se, v[i].fi);
		while (sz (u) > 1 && cur + (u[sz (u) - 2].fi - u[sz (u) - 1].fi) * u[sz (u) - 1].se < v[i].fi) {
			cur += (u[sz (u) - 2].fi - u[sz (u) - 1].fi) * u[sz (u) - 1].se;
			u[sz (u) - 2].se += u[sz (u) - 1].se;
			while (pos < u[sz (u) - 2].se) {
//				printf ("add %d\n", w[pos].se + 1);
				add (0, 0, m - 1, w[pos].se);
				pos++;
			}
			u.pop_back ();
		}
		res[v[i].se] = get (0, 0, m - 1, (v[i].fi - cur - 1) % u[sz (u) - 1].se + 1);
	}
	for (int i = 0; i < q; i++) printf ("%d\n", res[i]);
	re 0;
}