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
#include <cassert>

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
#define prev PREV
#define j0 j1347829
#define j1 j234892
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }
template<class T> T gcd(T a, T b) { re a ? gcd (b % a, a) : b; }

int n;
int m;

int o;
map<pair<ll, ll>, int> num; 
vii v[400000];
int was[400000];

int get (int a, int b, int c, int d) {
	ll p = (ll)a * d;
	ll q = (ll)b * c;
	ll g = gcd (p, q);
	p /= g;
	q /= g;
	if (num.count (mp (p, q))) re num[mp (p, q)];
	num[mp (p, q)] = o;
	o++;
	re o - 1;
}

vii res;

int go (int x, int p) {
	was[x] = 1;
	vi w;
	if (p != -1) w.pb (p);
	for (auto& y : v[x]) {
		if (y.se == p) continue;
		if (!was[y.fi]) {
			if (go (y.fi, y.se)) w.pb (y.se);
		} else
		if (was[y.fi] == 1) w.pb (y.se);
	}
//	printf ("%d %d = %d\n", x, p, sz (w));
	while (sz (w) >= 2) {
		res.pb (mp (w[sz (w) - 2], w[sz (w) - 1]));
		w.pop_back ();
		w.pop_back ();
	}
	was[x] = 2;
	re sz (w);
}

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b, c, d;
		scanf ("%d%d%d%d", &a, &b, &c, &d);
		int x = get (a + b, b, c, d);
		int y = get (a, b, c + d, d);
//		printf ("%d %d\n", x, y);
		v[x].pb (mp (y, i));
		v[y].pb (mp (x, i));
	}
	for (int i = 0; i < o; i++)
		if (!was[i])
			go (i, -1);
	printf ("%d\n", sz (res));
	for (int i = 0; i < sz (res); i++) printf ("%d %d\n", res[i].fi + 1, res[i].se + 1);
    return 0;
}