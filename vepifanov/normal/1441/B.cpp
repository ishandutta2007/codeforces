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

const int mod = 998244353;
const int N = 200000;
const int T = 20;

int n;
int m;
vi v[N][2];
ii d[N][2][T + 1];
int mark[N][2][T + 1];

bool ls (const ii& a, const ii& b) {
	if (a.fi > 25 || b.fi > 25) re a < b;
	int va = (1 << a.fi) + a.se;
	int vb = (1 << b.fi) + b.se;
	re va < vb;
}	

struct compare {
	bool operator () (const pair<ii, pair<ii, int> >& a, const pair<ii, pair<ii, int> >& b) {
		if (ls (a.fi, b.fi)) re false;
		if (ls (b.fi, a.fi)) re true;
		re a.se > b.se;
	}
};

priority_queue<pair<ii, pair<ii, int> >, vector<pair<ii, pair<ii, int> > >, compare> all;

void upd (int x, int y, ii nd) {
	int z = min (T, nd.fi);
	if (ls (nd, d[x][y][z])) {
//		if (mark[x][y][z]) all.erase (mp (d[x][y][z], mp (mp (x, y), z)));
		d[x][y][z] = nd;
//		mark[x][y][z] = 1;
		all.push (mp (d[x][y][z], mp (mp (x, y), z)));
	}	
}

int main () {
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf ("%d%d", &a, &b); a--; b--;
		v[a][0].pb (b);
		v[b][1].pb (a);
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 2; j++)
			for (int t = 0; t <= T; t++) {
				mark[i][j][t] = 0;
				d[i][j][t] = mp (1e9, 0);
			}
	d[0][0][0] = mp (0, 0);
	all.push (mp (d[0][0][0], mp (mp (0, 0), 0)));
//	int kkk = 0;
	while (!all.empty ()) {
//		kkk++;
		ii x = all.top ().se.fi;
		int z = all.top ().se.se;
		if (x.fi == n - 1) {
			int ans = 1;
			for (int i = 0; i < d[x.fi][x.se][z].fi; i++) ans = (ans * 2) % mod;
			ans = (ans + d[x.fi][x.se][z].se) % mod;
			ans = (ans + mod - 1) % mod;
			printf ("%d\n", ans);
//			cerr << clock () << endl;
			re 0;
		}
		all.pop ();
		if (mark[x.fi][x.se][z]) continue;
		mark[x.fi][x.se][z] = 1;
		upd (x.fi, x.se ^ 1, mp (d[x.fi][x.se][z].fi + 1, d[x.fi][x.se][z].se));
		for (auto y : v[x.fi][x.se])
			upd (y, x.se, mp (d[x.fi][x.se][z].fi, d[x.fi][x.se][z].se + 1));
	}
//	cerr << kkk << endl;
//	cerr << clock () << endl;
	re 0;
}