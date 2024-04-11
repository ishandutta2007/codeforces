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

const int N = 300000;

int n;
int m;
char h[N + 10];
int q[N][3];
int r[N];
ii p[N];
vi v[N];

ii gp (int x) {
	if (p[x].fi != x) {
		ii tmp = gp (p[x].fi);
		tmp.se ^= p[x].se;
		p[x] = tmp;
	}	
	re p[x];
}

int main () {
	scanf ("%d%d", &n, &m);
	scanf (" %s", h);
	for (int i = 0; i < m; i++) {
		int k;
		scanf ("%d", &k);	
		for (int j = 0; j < k; j++) {
			int x;
			scanf ("%d", &x); x--;
			v[x].pb (i);
		}
	}
	for (int i = 0; i < m; i++) {
		p[i] = mp (i, 0);
		q[i][0] = 0;
		q[i][1] = 1;
		q[i][2] = 0;
		r[i] = 2;
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (sz (v[i]) == 2) {
		    ii a = gp (v[i][0]);
		    ii b = gp (v[i][1]);
		    if (a.fi != b.fi) {
		    	if (rand () & 1) swap (a, b);
		    	int t = (a.se ^ b.se ^ (h[i] - '0') ^ 1);
	    		ans -= q[a.fi][r[a.fi]];
	    		ans -= q[b.fi][r[b.fi]];
	    		q[b.fi][0] += q[a.fi][t];
	    		q[b.fi][1] += q[a.fi][t ^ 1];
	    		q[b.fi][2] = min (q[b.fi][0], q[b.fi][1]);
	    		r[b.fi] = min (r[b.fi], r[a.fi] ^ t);
	    		ans += q[b.fi][r[b.fi]];
	    		p[a.fi] = mp (b.fi, t);
		    }
		} else
		if (sz (v[i]) == 1) {
			ii a = gp (v[i][0]);
			int req = (h[i] - '0') ^ a.se ^ 1;
			ans -= q[a.fi][r[a.fi]];
			r[a.fi] = req;
			ans += q[a.fi][r[a.fi]];
		}
		printf ("%d\n", ans);
	}
	re 0;
}