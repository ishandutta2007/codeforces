#include <cstdio>
#include <numeric>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>
#include <deque>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

int n;
int m;

int a[100000], b[100000], c[100000], d[200002], mark[200002], prev[200002], pedge[200002];
set<ii> all;
map<int, int> w;
vi v, res;
vector<pair<int, ii> > u[200002];

int out (int x) {
	if (x == 0) re 0;
	out (prev[x]);
	if (pedge[x] != -1) res.pb (pedge[x] + 1);
	re 0;
}

int main () {
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		int x, d, t, p;	
		scanf ("%d%d%d%d", &x, &d, &t, &p);
		a[i] = x - p;
		b[i] = x + d;
		c[i] = t + p;
		if (x - p >= 0 && x + d <= m) {
			v.pb (x - p);
			v.pb (x + d);
		}	
	}
	v.pb (0);
	v.pb (m);
	sort (all (v));
	v.resize (unique (all (v)) - v.begin ());
	int r = sz (v);
	for (int i = 0; i < r; i++) {
		if (i > 0) u[i].pb (mp (i - 1, mp (v[i] - v[i - 1], -1)));
		if (i + 1 < r) u[i].pb (mp (i + 1, mp (v[i + 1] - v[i], -1)));
		w[v[i]] = i;
	}	
	for (int i = 0; i < n; i++) 
		if (a[i] >= 0 && b[i] <= m)
			u[w[a[i]]].pb (mp (w[b[i]], mp (c[i], i)));
	memset (mark, 0, sizeof (mark));
	mark[0] = 1;    	
	d[0] = 0;
	all.insert (mp (0, 0));
	while (!all.empty ()) {
		int x = all.begin ()->se;
		all.erase (all.begin ());
		for (int i = 0; i < sz (u[x]); i++) {
			int y = u[x][i].fi;
			int z = d[x] + u[x][i].se.fi;
			if (!mark[y] || z < d[y]) {
				if (mark[y]) all.erase (mp (d[y], y));
				d[y] = z;
				mark[y] = 1;
				prev[y] = x;
				pedge[y] = u[x][i].se.se;
				all.insert (mp (d[y], y));
			}
		}
	}
	printf ("%d\n", d[r - 1]);
	out (r - 1);
	printf ("%d\n", sz (res));
	for (int i = 0; i < sz (res); i++) printf ("%d ", res[i]);
	printf ("\n");
	return 0;
}