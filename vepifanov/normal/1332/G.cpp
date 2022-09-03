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

const int N = 1 << 18;
const int inf = 1e9;

int n;
int m;
vi vx;
map<int, int> num;
int x[N];
int qu[N];
int qd[N];
int pu[N];
int pd[N];
int nu[N];
int nd[N];
vi wu[N];
vi wd[N];
vi gu[N];
vi gd[N];
int r3[N];
int r4[N];
pair<int, ii> p3[N];
pair<ii, ii> p4[N];
int tree[2][2 * N + 10];
int tree2[2][2 * N + 10];
int tree3[2 * N + 10];
vi res[N];
vii req[N];

void build (int t, int x, int l, int r) {
	tree[t][x] = inf;
	if (l == r) re;
	int s = (l + r) / 2;
	build (t, x * 2 + 1, l, s);
	build (t, x * 2 + 2, s + 1, r);
}

int add (int t, int x, int l, int r, int y, int z) {
	if (r < y || l > y) re tree[t][x];
	if (l == r) re tree[t][x] = min (tree[t][x], z);
	int s = (l + r) / 2;
	re tree[t][x] = min (add (t, x * 2 + 1, l, s, y, z), add (t, x * 2 + 2, s + 1, r, y, z));
}

int get (int t, int x, int l, int r, int lc, int rc) {
	if (r < lc || l > rc) re inf;
	if (l >= lc && r <= rc) re tree[t][x];
	int s = (l + r) / 2;
	re min (get (t, x * 2 + 1, l, s, lc, rc), get (t, x * 2 + 2, s + 1, r, lc, rc));
}

int merge2 (int t, int i, int j) {
	if (t == 0) {
		if (i != inf && (j == inf || x[i] > x[j])) re i;
		re j;
	} else {
		if (i != inf && (j == inf || x[i] < x[j])) re i;
		re j;
	}	
}

int build2 (int t, int x, int l, int r) {
	if (l == r) {
		tree2[t][x] = l;
		re l;
	}
	int s = (l + r) / 2;
	re tree2[t][x] = merge2 (t, build2 (t, x * 2 + 1, l, s), build2 (t, x * 2 + 2, s + 1, r));
}

int get2 (int t, int x, int l, int r, int lc, int rc) {
//    printf ("get2 %d %d %d %d %d %d = %d\n", t, x, l, r, lc, rc, tree2);
	if (r < lc || l > rc) re inf;
	if (l >= lc && r <= rc) re tree2[t][x];
	int s = (l + r) / 2;
	re merge2 (t, get2 (t, x * 2 + 1, l, s, lc, rc), get2 (t, x * 2 + 2, s + 1, r, lc, rc));
}

void build3 (int x, int l, int r) {
	tree3[x] = inf;
	if (l == r) re;
	int s = (l + r) / 2;
	build3 (x * 2 + 1, l, s);
	build3 (x * 2 + 2, s + 1, r);
}

int add3 (int x, int l, int r, int y, int z) {
	if (r < y || l > y) re tree3[x];
	if (l == r) re tree3[x] = min (tree3[x], z);
	int s = (l + r) / 2;
	re tree3[x] = min (add3 (x * 2 + 1, l, s, y, z), add3 (x * 2 + 2, s + 1, r, y, z));
}

int get3 (int x, int l, int r, int lc, int rc) {
	if (r < lc || l > rc) re inf;
	if (l >= lc && r <= rc) re tree3[x];
	int s = (l + r) / 2;
	re min (get3 (x * 2 + 1, l, s, lc, rc), get3 (x * 2 + 2, s + 1, r, lc, rc));
}

int cool (int i, int j, int k) {
	if ((ll)(x[j] - x[i]) * (x[k] - x[j]) >= 0) re 1;
	re 0;
}

int main () {
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf ("%d", &x[i]);
		vx.pb (x[i]);
	}
	for (int i = 0; i < m; i++) {
		int l, r;
		scanf ("%d%d", &l, &r); l--; r--;
		req[l].pb (mp (r, i));
	}

	sort (all (vx));
	vx.resize (unique (all (vx)) - vx.begin ());
	int o = sz (vx);
	for (int i = 0; i < sz (vx); i++) num[vx[i]] = i;
	for (int i = 0; i < n; i++) x[i] = num[x[i]];

	{
		int ru = 0, rd = 0;
		for (int i = 0; i < n; i++) {
			while (ru > 0 && x[qu[ru - 1]] <= x[i]) ru--;
			if (ru > 0) pu[i] = qu[ru - 1]; else pu[i] = -1;
			while (rd > 0 && x[qd[rd - 1]] >= x[i]) rd--;
			if (rd > 0) pd[i] = qd[rd - 1]; else pd[i] = -1;
			qu[ru++] = i;
			qd[rd++] = i;
		}
	}	
	{
		int ru = 0, rd = 0;
		for (int i = n - 1; i >= 0; i--) {
			while (ru > 0 && x[qu[ru - 1]] <= x[i]) ru--;
			if (ru > 0) nu[i] = qu[ru - 1]; else nu[i] = -1;
			while (rd > 0 && x[qd[rd - 1]] >= x[i]) rd--;
			if (rd > 0) nd[i] = qd[rd - 1]; else nd[i] = -1;
			qu[ru++] = i;
			qd[rd++] = i;
		}
	}
	for (int i = 0; i < n; i++) r3[i] = r4[i] = n;
	for (int i = 0; i < n; i++) {
		if (pu[i] != -1 && pd[i] != -1) {
			int j = min (pu[i], pd[i]);
			if (r3[j] > i) {
				r3[j] = i;
				p3[j] = mp (pu[i], mp (pd[i], i));
			}
		}
		if (nu[i] != -1 && nd[i] != -1) {
			int j = max (nu[i], nd[i]);
			if (r3[i] > j) {
				r3[i] = j;
				p3[i] = mp (nu[i], mp (nd[i], i));
			}
		}
		if (pu[i] != -1 && nu[i] != -1) {
			if (r3[pu[i]] > nu[i]) {
				r3[pu[i]] = nu[i];
				p3[pu[i]] = mp (pu[i], mp (i, nu[i]));
			}
		}
		if (pd[i] != -1 && nd[i] != -1) {
			if (r3[pd[i]] > nd[i]) {
				r3[pd[i]] = nd[i];
				p3[pd[i]] = mp (pd[i], mp (i, nd[i]));
			}
		}
		if (nu[i] != -1) gu[nu[i]].pb (i);
		if (nd[i] != -1) gd[nd[i]].pb (i);
		if (pu[i] != -1) wu[pu[i]].pb (i);
		if (pd[i] != -1) wd[pd[i]].pb (i);
	}
	build (0, 0, 0, o - 1);
	build (1, 0, 0, o - 1);
	build2 (0, 0, 0, n - 1);
	build2 (1, 0, 0, n - 1);
	build3 (0, 0, o - 1);
//	for (int i = 0; i < n; i++) printf ("%d ", x[i]);
//	printf ("\n");
	for (int i = n - 1; i >= 0; i--) {
		for (auto j : gd[i]) {
			{
				int top = get2 (0, 0, 0, n - 1, j + 1, i - 1);
//				printf ("%d %d = %d\n", j, i, top);
				if (top != inf && x[top] > x[j]) {
					int right = get3 (0, 0, o - 1, x[j], x[top] - 1);
					if (r4[j] > right) {
//						printf ("%d %d %d %d | %d %d\n", j, i, top, right, x[j + 1], x[top] - 1);
						r4[j] = right;
						p4[j] = mp (mp (j, i), mp (top, right));
					}
				}
			}
			{
				int right = get (0, 0, 0, o - 1, x[j], o - 1);
				if (right < n) {
					int top = pu[right];
					if (r4[j] > right) {
						r4[j] = right;
						p4[j] = mp (mp (j, i), mp (top, right));
					}
				}
			}
		}
		for (auto j : gu[i]) {
			{
				int top = get2 (1, 0, 0, n - 1, j + 1, i - 1);
				if (top != inf && x[top] < x[j]) {
					int right = get3 (0, 0, o - 1, x[top] + 1, x[j]);
					if (r4[j] > right) {
						r4[j] = right;
						p4[j] = mp (mp (j, i), mp (top, right));
					}
				}
			}
			{
				int right = get (1, 0, 0, o - 1, 0, x[j]);
				if (right < n) {
					int top = pd[right];
					if (r4[j] > right) {
						r4[j] = right;
						p4[j] = mp (mp (j, i), mp (top, right));
					}
				}
			}
		}
		add3 (0, 0, o - 1, x[i], i);
		for (auto j : wu[i]) add (0, 0, 0, o - 1, x[j], j);
		for (auto j : wd[i]) add (1, 0, 0, o - 1, x[j], j);
	}
	int b3 = n, b4 = n;
	pair<int, ii> rb3;
	pair<ii, ii> rb4;
	for (int i = n - 1; i >= 0; i--) {
		if (r3[i] < b3) {
			b3 = r3[i];
			rb3 = p3[i];
		}
		if (r4[i] < b4) {
			b4 = r4[i];
			rb4 = p4[i];
		}
		for (auto& r : req[i]) {
//			printf ("%d %d %d | %d %d\n", i, r.fi, r.se, b3, b4);
			if (r.fi >= b4) {
				vi v;
				v.pb (rb4.fi.fi);
				v.pb (rb4.fi.se);
				v.pb (rb4.se.fi);
				v.pb (rb4.se.se);
				sort (all (v));
				res[r.se] = v;
			} else
			if (r.fi >= b3) {
				vi v;
				v.pb (rb3.fi);
				v.pb (rb3.se.fi);
				v.pb (rb3.se.se);
				sort (all (v));
				res[r.se] = v;
			} else res[r.se] = vi();
		}
	}
	cerr << clock () << endl;
	for (int i = 0; i < m; i++) {
		assert (sz (res[i]) == 0 || sz (res[i]) == 3 || sz (res[i]) == 4);
		printf ("%d\n", sz (res[i]));
		for (auto j : res[i])
			printf ("%d ", j + 1);
		printf ("\n");
		for (int a = 0; a < sz (res[i]); a++)
			for (int b = a + 1; b < sz (res[i]); b++)
				for (int c = b + 1; c < sz (res[i]); c++)
					assert (!cool (res[i][a], res[i][b], res[i][c]));
	}
	cerr << clock () << endl;
	re 0;
}