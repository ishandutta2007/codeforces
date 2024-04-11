#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define makeunique(x) sort(all(x)), (x).resize(unique(all(x)) - (x).begin())
#define re return
#define y0 y2415
#define y1 y346246
#define j0 j23562456
#define j1 j245623456
#define sqrt(x) sqrt (abs (x))

typedef unsigned long long ull;
typedef long long ll;
typedef double D;
typedef long double ld;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;
typedef vector <vi> vvi;
typedef vector <string> vs;

template <class T> T gcd (T a, T b) { re a ? gcd (b % a, a) : b; }
template <class T> T abs (T x) { re x > 0 ? x : -x; }
template <class T> T sqr (T x) { re x * x; }
template <class T> int sgn (T x) { re x > 0 ? 1 : (x < 0 ? -1 : 0); }

const ld pi = acos (-1.0);

const int N = 300100;

int n;
int m;
int Q;
int was[N];
int col[N];
vii v[N];
int bad[2 * N];
vi q;
int R = 0;
vii imp;
vi w[N];
int p[N];
int ea[N];
int eb[N];
int x[N];
int num[N];
int tree[N];
int ct;
int tin[N];
int tout[N];
int anc[N][20];
int cimp[N];
int COL[N];

int rotate (int x) {
	x = (x + R) % n;
	if (x == 0) x = n;
	re x;
}

int go (int x, int p) {
	if (was[x]) re 0;
	was[x] = 1;
    for (int i = 0; i < sz (v[x]); i++) {
    	int y = v[x][i].fi;
    	int z = v[x][i].se;
    	if ((z ^ 1) == p || was[y] == 2) continue;
    	bad[z] = 1;
    	go (y, z);    
    }	
    was[x] = 2;
    q.pb (x);
    re 0;
}

int go2 (int x, int c) {
	if (was[x]) re 0;
	col[x] = c;
	was[x] = 1;
	for (int i = 0; i < sz (v[x]); i++) {
		int y = v[x][i].fi;
		int z = v[x][i].se;
		if (bad[z]) continue;
		go2 (y, c);
	}
	re 0;
}

int build (int n) {
    q.clear ();
	for (int i = 0; i < n; i++) was[i] = 0;
    for (int i = 0; i < n; i++) go (i, -1);
	for (int i = 0; i < n; i++) was[i] = 0;
    reverse (all (q));
    int o = 0;
    for (int i = 0; i < sz (q); i++) {
    	int x = q[i];
    	if (!was[x]) {
    		go2 (x, o);
    		o++;
    	}            
    }	
	re o;
}

int go3 (int x, int p, int c) {
	tin[x] = ct++;
	tree[x] = c;
	was[x] = 1;
	anc[x][0] = p;
	for (int i = 0; i < 19; i++)
		anc[x][i + 1] = anc[anc[x][i]][i];
	for (int i = 0; i < sz (w[x]); i++) {
		int y = w[x][i];
		if (y == p) continue;
		go3 (y, x, c);
	}
	tout[x] = ct++;
	re 0;
}

int isanc (int a, int b) { re int (tin[a] <= tin[b] && tout[a] >= tout[b]); }

int lca (int a, int b) {
	int j = 19;
	while (!isanc (a, b))
		if (j == 0 || !isanc (anc[a][j], b))
			a = anc[a][j];
		else
			j--;
	re a;	
}

int add (int x) {
	if (cimp[x] != ct) {
		cimp[x] = ct;
		imp.pb (mp (tin[x], x));
	}
	re 0;
}

int main()
{
    scanf ("%d%d%d", &n, &m, &Q);
    for (int i = 0; i < m; i++) {
    	int a, b;
    	scanf ("%d%d", &a, &b); a--; b--;
    	v[a].pb (mp (b, 2 * i));
    	v[b].pb (mp (a, 2 * i + 1));
    	ea[i] = a;
    	eb[i] = b;
    }
    int o = build (n);
    for (int i = 0; i < m; i++)
    	if (col[ea[i]] != col[eb[i]]) {
    		w[col[ea[i]]].pb (col[eb[i]]);
    		w[col[eb[i]]].pb (col[ea[i]]);
    	}
    memset (was, 0, sizeof (was));
    int r = 0;
	for (int i = 0; i < o; i++)
		if (!was[i]) {
			go3 (i, i, r);
			r++;
		}
	for (int i = 0; i < n; i++) COL[i] = col[i];	
	ct = 0;	
	for (int it = 0; it < Q; it++) {
		ct++;
		imp.clear ();
		int ni, mi;
		scanf ("%d%d", &ni, &mi);
		for (int i = 0; i < ni; i++) {
			scanf ("%d", &x[i]);
			x[i] = rotate (x[i]);
			x[i] = COL[x[i] - 1];
			add (x[i]);
		}
		for (int i = 0; i < mi; i++) {
			scanf ("%d%d", &ea[i], &eb[i]);
			ea[i] = rotate (ea[i]);
			eb[i] = rotate (eb[i]);
			ea[i] = COL[ea[i] - 1];
			eb[i] = COL[eb[i] - 1];
			if (ea[i] != eb[i]) {
				add (ea[i]);
				add (eb[i]);
			}
		}
		sort (all (imp));
		int cn = sz (imp);
		for (int i = 0; i + 1 < cn; i++) {
			int a = imp[i].se;
			int b = imp[i + 1].se;
			if (tree[a] == tree[b]) {
				int c = lca (a, b);
				add (c);
			}
		}
		sort (all (imp));
		cn = sz (imp);
		for (int i = 0; i < cn; i++) {
			num[imp[i].se] = i;
			v[i].clear ();
		}	
		for (int i = 0; i < cn; i++) {
			int a = imp[i].se;
			int b = imp[i].se;
			if (i > 0 && tree[imp[i - 1].se] == tree[imp[i].se]) a = lca (imp[i].se, imp[i - 1].se);
			if (i + 1 < cn && tree[imp[i + 1].se] == tree[imp[i].se]) b = lca (imp[i].se, imp[i + 1].se);
			if (isanc (a, b)) swap (a, b);
			if (a == imp[i].se) a = b;
			p[i] = num[a];
		}
		int e = 0;
		for (int i = 0; i < cn; i++)
			if (p[i] != i) {
				v[i].pb (mp (p[i], e++));
				v[p[i]].pb (mp (i, e++));
			}
		for (int i = 0; i < mi; i++) {
			int a = num[ea[i]];
			int b = num[eb[i]];
			v[a].pb (mp (b, e++));
			v[b].pb (mp (a, e++));
		}	
		for (int i = 0; i < e; i++) bad[i] = 0;
		build (cn);
		int ok = 1;
		for (int i = 1; i < ni && ok; i++)
			if (col[num[x[i]]] != col[num[x[0]]])
				ok = 0;
		if (ok) {
			printf ("YES\n");
			R += it + 1;
			R %= n;
		} else printf ("NO\n");
	}
	return 0;
}