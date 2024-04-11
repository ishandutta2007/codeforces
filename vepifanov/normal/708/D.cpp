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

int n;
int m;
int fin[100];
int fout[100];
int d[110];
int mark[110];
int q[110];
vii v[110];
int ec[10000];
int ef[10000];
int prev[110];
int preve[110];
int e = 0;

void addedge (int a, int b, int c, int d) {
//	if (c > 0) printf ("%d -> %d, %d %d\n", a + 1, b + 1, c, d);
	v[a].pb (mp (b, e));
	ec[e] = d;
	ef[e] = c;
	e++;
	v[b].pb (mp (a, e));
	ec[e] = -d;
	ef[e] = 0;
	e++;
}

int go (int S, int T) {
	for (int i = 0; i < n + 2; i++) {
		d[i] = 1e9;
		mark[i] = 0;
	}
	int l = 0, r = 1;
	q[0] = S;
	d[S] = 0;
	mark[S] = 1;
	while (l != r) {
		int x = q[l++];
		if (l == n + 2) l = 0;
		mark[x] = 0;
		for (int i = 0; i < sz (v[x]); i++) {
			int y = v[x][i].fi;
			int z = v[x][i].se;
			if (ef[z] <= 0) continue;
			int nd = d[x] + ec[z];
			if (nd < d[y]) {
				d[y] = nd;
				prev[y] = x;
				preve[y] = z;
				if (!mark[y]) {
					mark[y] = 1;
					q[r++] = y;
					if (r == n + 2) r = 0;
				}
			}
		}
	}
	if (d[T] > 5e8) re -1;
	re d[T];
}

int main () {
	scanf ("%d%d", &n, &m);
	ll ans = 0;
	for (int i = 0; i < m; i++) {
		int a, b, c, f;
		scanf ("%d%d%d%d", &a, &b, &c, &f); a--; b--;
		fout[a] += f;
		fin[b] += f;
		if (c >= f) {
			addedge (a, b, c - f, 1);
			addedge (a, b, 1e9, 2);
			addedge (b, a, f, 1);
		} else {
			ans += f - c;
			addedge (a, b, 1e9, 2);
			addedge (b, a, c, 1);
			addedge (b, a, f - c, 0);
		}
	}
	addedge (n - 1, 0, 1e9, 0);
	for (int i = 0; i < n; i++)
		if (fout[i] > fin[i])
			addedge (i, n + 1, fout[i] - fin[i], 0);
		else
		if (fin[i] > fout[i])
			addedge (n, i, fin[i] - fout[i], 0);
	int cur;
	while ((cur = go (n, n + 1)) != -1) {
		int j = n + 1;
		int tmp = 1e9;
		while (j != n) {
			int k = prev[j];
			int z = preve[j];
			tmp = min (tmp, ef[z]);
			j = k;
		}
		j = n + 1;
		while (j != n) {
			int k = prev[j];
			int z = preve[j];
			ef[z] -= tmp;
			ef[z ^ 1] += tmp;
			j = k;
		}
		ans += (ll)cur * tmp;
	}
	cout << ans << endl;
	return 0;
}