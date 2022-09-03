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
 
const int N = 200000;

int n;
int m;
vi v[N];
vi rv[N];
int p[N];
int q[N];
int was[N];
int x[N];

int go (int x) {
	if (x == -1) re 1;
	if (was[x] == 1) re 0;
	was[x] = 1;
	for (auto y : v[x])
		if (go (q[y])) {
			p[x] = y;
			q[y] = x;
			re 1;
		}
	re 0;
}

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf ("%d", &n);
		for (int i = 0; i < n; i++) {
			v[i].clear ();
			rv[i].clear ();
		}
		for (int i = 0; i < n; i++) {
			scanf ("%d", &x[i]);
			x[i]--;
			v[i].pb (x[i]);
			rv[x[i]].pb (i);
		}
		for (int i = 0; i < n; i++) {
			p[i] = q[i] = -1;
			was[i] = 0;
		}
		for (int i = 0; i < n; i++)
			if (!rv[i].empty ()) {
				q[i] = rv[i][0];
				p[rv[i][0]] = i;
			}
		vi rb, rp, rq;
		for (int i = 0; i < n; i++)
			if (p[i] == -1 && q[i] == -1) {
				rp.pb (i);
				rq.pb (i);
			}
		for (int i = 0; i < n; i++) {
			if (p[i] == -1 && q[i] != -1) rp.pb (i);
			if (q[i] == -1 && p[i] != -1) rq.pb (i);
		}
		if (sz (rp) == 1 && rp[0] == rq[0]) {
			int a = rp[0];
			int b = x[a];
			int c = q[b];
			p[a] = b;
			q[b] = a;
			p[c] = a;
			q[a] = c;
		} else 
		if (!rp.empty ()) {
			rq.pb (rq[0]);
			rq.erase (rq.begin ());
			for (int i = 0; i < sz (rp); i++) {
				p[rp[i]] = rq[i];
				q[rq[i]] = rp[i];
				assert (rp[i] != rq[i]);
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			ans += int (p[i] == x[i]);
			assert (p[i] != -1);
		}	
		printf ("%d\n", ans);
		for (int i = 0; i < n; i++) printf ("%d ", p[i] + 1);
		printf ("\n");
	}
    re 0;
}