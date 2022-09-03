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
int x;
ll w[300000];
int p[300000];
set<ii> v[300000];
set<pair<ll, int> > all;
vi res;

int gp (int x) {
	if (p[x] != x) p[x] = gp (p[x]);
	re p[x];
}

int main () {
	scanf ("%d%d%d", &n, &m, &x);
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		p[i] = i;
		scanf ("%lld", &w[i]);
		sum += w[i];
		all.insert (mp (-w[i], i));
	}
	if (sum < (ll)(n - 1) * x) {
		printf ("NO\n");
		re 0;
	}
	int rem = n - 1;
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf ("%d%d", &a, &b); a--; b--;
		int pa = gp (a);
		int pb = gp (b);
		if (pa != pb) {
			rem--;
			p[pa] = pb;
			v[a].insert (mp (b, i));
			v[b].insert (mp (a, i));
		}
	}
	for (int i = 0; i < n - 1; i++) {
		pair<ll, int> cur = *all.begin ();
		all.erase (cur);
		ii tmp = *v[cur.se].begin ();
		int a = cur.se;
		int b = tmp.fi;
		int c = tmp.se;
		res.pb (c + 1);
		v[a].erase (mp (b, c));
		v[b].erase (mp (a, c));
		all.erase (mp (-w[b], b));
		if (sz (v[a]) < sz (v[b])) swap (a, b);	
		w[a] += w[b] - x;
		for (auto& t : v[b]) {
			v[a].insert (t);
			v[t.fi].erase (mp (b, t.se));
			v[t.fi].insert (mp (a, t.se));
		}
		v[b].clear ();
		all.insert (mp (-w[a], a));
	}
	printf ("YES\n");
	for (auto i : res) printf ("%d ", i);
	printf ("\n");
	re 0;
}