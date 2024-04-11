#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define j0 j5743892
#define j1 j542893
#define prev PREV
#define next NEXT
                         
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }
template<class T> T gcd(T a, T b) { re a ? gcd (b % a, a) : b; }
template<class T> T sqr(T a) { re a * a; }
template<class T> T sgn(T a) { re a > 0 ? 1 : (a < 0 ? -1 : 0); }

#define filename ""

const int N = 1200100;

int n;
int m;
char h[300010];
int next[N][26];
int len[N];
int suf[N];
int par[N];
int cnt[N];
int last[N];
int o;
vs q[2];
vector<pair<ii, int> > seg[2];

void add (int root, string s) {
//	cout << "add " << root << " " << s << endl;
	int x = root;
	for (int i = 0; i < sz (s); i++) {
		int c = s[i] - 'a';
		if (next[x][c] == root) {
			next[x][c] = o;
			for (int j = 0; j < 26; j++) next[o][j] = root;
			par[o] = x;
			last[o] = c;
			len[o] = len[x] + 1;
			cnt[o] = 0;
			o++;
		}
		x = next[x][c];
	}
	cnt[x]++;
}

int build (int t, ii seg) {
	int root = o++;
	len[root] = 0;
	par[root] = root;
	for (int i = 0; i < 26; i++) next[root][i] = root;
	for (int i = seg.fi; i <= seg.se; i++) add (root, q[t][i]);
	vii v;
	for (int i = root; i < o; i++) v.pb (mp (len[i], i));
	sort (all (v));
	suf[root] = root;
	for (int i = 0; i < sz (v); i++) {
		int x = v[i].se;
		int z = last[x];
		int y = suf[par[x]];
		while (y != root && next[y][z] == root) y = suf[y];
		if (next[y][z] != root && len[y] + 1 < len[x]) y = next[y][z];
		suf[x] = y;
		cnt[x] += cnt[suf[x]];
		for (int j = 0; j < 26; j++)
			if (next[x][j] == root)
				next[x][j] = next[suf[x]][j];
	}
	re root;
}

void push (int t, string s) {
	seg[t].pb (mp (mp (sz (q[t]), sz (q[t])), 0));
	q[t].pb (s);
	while (sz (seg[t]) >= 2 && seg[t][sz (seg[t]) - 1].fi.se - seg[t][sz (seg[t]) - 1].fi.fi == seg[t][sz (seg[t]) - 2].fi.se - seg[t][sz (seg[t]) - 2].fi.fi) {
		seg[t][sz (seg[t]) - 2].fi.se = seg[t][sz (seg[t]) - 1].fi.se;
		seg[t].pop_back ();
	}
	seg[t].back().se = build (t, seg[t].back ().fi);
}

ll calc (int t, string s) {
	ll cur = 0;
	for (int i = 0; i < sz (seg[t]); i++) {
		int x = seg[t][i].se;
		for (int j = 0; j < sz (s); j++) {
			int c = s[j] - 'a';
			x = next[x][c];
			cur += cnt[x];
		}
	}
	re cur;
}

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		int t;
		scanf ("%d %s", &t, h);
		if (t == 1) push (0, string (h)); else
		if (t == 2) push (1, string (h)); else printf ("%lld\n", calc (0, string (h)) - calc (1, string (h)));
		fflush (stdout);
	}
	cerr << clock () << endl;
	return 0;
}