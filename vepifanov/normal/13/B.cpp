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
int x1[3], y1[3], x2[3], y2[3], p[3];

ll dist (ll x1, ll y1, ll x2, ll y2) {
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int ison (ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
	ll vect = (x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3);
	ll scal = (x1 - x2) * (x1 - x3) + (y1 - y2) * (y1 - y3);
	return int (vect == 0 && scal < 0);
}

int check (ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4) {
	if (x1 == x3 && y1 == y3);
	if (x1 == x4 && y1 == y4) { swap (x3, x4); swap (y3, y4); }
	if (x2 == x3 && y2 == y3) { swap (x1, x2); swap (y1, y2); }
	if (x2 == x4 && y2 == y4) { swap (x1, x2); swap (y1, y2); swap (x3, x4); swap (y3, y4); }
	ll vect = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
	ll scal = (x1 - x2) * (x3 - x4) + (y1 - y2) * (y3 - y4);
	return int (vect != 0 && scal >= 0);
}

int main() {
	int t;
	scanf ("%d", &t);
	for (int i = 0; i < t; i++) {
		for (int i = 0; i < 3; i++) scanf ("%d%d%d%d", &x1[i], &y1[i], &x2[i], &y2[i]);
		int ok = 0;
		for (int i = 0; i < 3; i++) p[i] = i;
		do {
			int a = p[0], b = p[1], c = p[2];
			if (x1[a] == x1[b] && y1[a] == y1[b] || x1[a] == x2[b] && y1[a] == y2[b] || x2[a] == x2[b] && y2[a] == y2[b] || x2[a] == x1[b] && y2[a] == y1[b]) {
			if (check (x1[a], y1[a], x2[a], y2[a], x1[b], y1[b], x2[b], y2[b]))
				if (ison (x1[c], y1[c], x1[a], y1[a], x2[a], y2[a]) && ison (x2[c], y2[c], x1[b], y1[b], x2[b], y2[b])) {
	                        	long long d1 = dist (x1[a], y1[a], x1[c], y1[c]);
	                        	long long d2 = dist (x2[a], y2[a], x1[c], y1[c]);
	                        	long long d3 = dist (x1[b], y1[b], x2[c], y2[c]);
	                        	long long d4 = dist (x2[b], y2[b], x2[c], y2[c]);
	                        	if (min (d1, d2) * 16 >= max (d1, d2) && min (d3, d4) * 16 >= max (d3, d4)) ok = 1;
				} } 
		} while (next_permutation (p, p + 3));
		if (ok) printf ("YES\n"); else printf ("NO\n");
	}
	return 0;
}