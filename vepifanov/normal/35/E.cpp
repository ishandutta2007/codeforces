#include <cstdio>
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

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < n; i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define y0 y3487465
#define y1 y8687969

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) {
	re x > 0 ? x : -x;
}

int n;
int m;

set<ii> all;
vector<pair<int, pair<int, ii> > > v;
vector<pair<int, ii> > w;
vii res;

int main() {
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	int n;
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		int l, r, h;
		scanf ("%d%d%d", &h, &l, &r);
		v.pb (mp (l, mp (0, mp (-h, i))));
		v.pb (mp (r, mp (1, mp (-h, i))));
	}
	sort (all (v));
	for (int i = 0; i < sz (v); i++) {
		if (v[i].se.fi == 0) all.insert (v[i].se.se); else all.erase (v[i].se.se);
		if (i + 1 < sz (v) && v[i + 1].fi > v[i].fi) {
			int h = 0;
			if (!all.empty ()) h = -all.begin ()->first;
			w.pb (mp (h, mp (v[i].fi, v[i + 1].fi)));
		}
	} 
	res.pb (mp (w[0].se.fi, 0));
	for (int i = 0; i < sz (w); i++) {
		int l = w[i].se.fi;
		int r = w[i].se.se;
		int h = w[i].fi;
		if (res[sz (res) - 1] == mp (l, h)) res[sz (res) - 1] = mp (r, h); else {
			res.pb (mp (l, h));
			res.pb (mp (r, h));
		}
	}
	res.pb (mp (w[sz (w) - 1].se.se, 0));
	printf ("%d\n", sz (res));
	for (int i = 0; i < sz (res); i++)
		printf ("%d %d\n", res[i].fi, res[i].se);
	return 0;
}