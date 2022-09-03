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

const int N = 100000;

int n;
int m;
int g[N][4];
int w[N][3];
int ea[3 * N];
int eb[3 * N];
int cnt[3 * N];
vi v[3 * N];
vi u[N];
vi rp;
map<ii, int> num;
int o;
int q[N];
int was[N];
int now[N];

int get (int a, int b) {
	if (a > b) swap (a, b);
	if (num.find (mp (a, b)) != num.end ()) re num[mp (a, b)];
	num[mp (a, b)] = o;
	v[o].clear ();
	cnt[o] = 0;
	ea[o] = a;
	eb[o] = b;
	o++;
	re o - 1;
}

int go (int x, int p) {
	rp.pb (x);
	for (auto y : u[x])
		if (y != p && y != 0)
			re go (y, x);
	re 0;
}

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf ("%d", &n);
		o = 0;
		num.clear ();
		for (int i = 0; i < n - 2; i++) {
			for (int j = 0; j < 3; j++) {
				scanf ("%d", &g[i][j]);
				g[i][j]--;
			}
			g[i][3] = g[i][0];
			for (int j = 0; j < 3; j++) {
				w[i][j] = get (g[i][j], g[i][j + 1]);
				cnt[w[i][j]]++;
				v[w[i][j]].pb (i);
			}
		}
		for (int i = 0; i < n; i++) u[i].clear ();
		for (int i = 0; i < o; i++)
			if (cnt[i] == 1) {	
				u[ea[i]].pb (eb[i]);
				u[eb[i]].pb (ea[i]);
			}
		rp.clear ();
		go (0, 0);
		for (int i = 0; i < n; i++) printf ("%d ", rp[i] + 1);
		printf ("\n");
		int l = 0, r = 0;
		for (int i = 0; i < n - 2; i++) {
			was[i] = 0;
			now[i] = cnt[w[i][0]] + cnt[w[i][1]] + cnt[w[i][2]];
		}
		for (int i = 0; i < n - 2; i++)
			if (now[i] <= 4) {
				q[r++] = i;
				was[i] = 1;
			}
		while (l < r) {
			int x = q[l++];
			for (int i = 0; i < 3; i++) {
				int y = w[x][i];
				for (auto z : v[y]) {
					now[z]--;
					if (!was[z] && now[z] <= 4) {
						was[z] = 1;
						q[r++] = z;
					}
				}
					
			}
		}
		for (int i = 0; i < n - 2; i++) printf ("%d ", q[i] + 1);
		printf ("\n");
	}
	re 0;
}