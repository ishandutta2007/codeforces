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
int f[1001][1001];
int ww[1001][1001], w[1001][1001], g[1001][1001];
long long s[1001][1001];
ii st[1001];

vector<pair<long long, pair<int, int> > > all;
vector<pair<pair<int, int>, long long > > res;

int add (int x, int y) {
	for (int p = x; p <= n; p |= (p + 1))
		for (int q = y; q <= m; q |= (q + 1))
			f[p][q]++;
}

int get (int x, int y) {
	int s = 0;
	for (int p = x; p > 0; p = (p & (p + 1)) - 1)
		for (int q = y; q > 0; q = (q & (q + 1)) - 1)
			s += f[p][q];
	return s;
}

int main() {
	int a, b;
	scanf ("%d%d%d%d", &n, &m, &a, &b);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf ("%d", &g[i][j]);
	memset (s, 0, sizeof (s));
	for (int i = n - 1; i >= 0; i--)
		for (int j = m - 1; j >= 0; j--)
			s[i][j] = s[i + 1][j] + s[i][j + 1] - s[i + 1][j + 1] + g[i][j];
	for (int i = 0; i < n; i++) {
		int r = 0, l = 0;
		for (int j = 0; j < m; j++) {
			while (l < r && st[l].second + b <= j) l++;
			while (r > l && st[r - 1].first > g[i][j]) r--;
			st[r++] = make_pair (g[i][j], j);
			if (j - b + 1 >= 0) ww[i][j - b + 1] = st[l].first;
		}
	}

	for (int j = 0; j + b <= m; j++) {
		int r = 0, l = 0;
		for (int i = 0; i < n; i++) {
			while (l < r && st[l].second + a <= i) l++;
			while (r > l && st[r - 1].first > ww[i][j]) r--;
			st[r++] = make_pair (ww[i][j], i);
			if (i - a + 1 >= 0) w[i - a + 1][j] = st[l].first;
		}
	}

	for (int i = 0; i + a <= n; i++)
		for (int j = 0; j + b <= m; j++) {
			long long cur = s[i][j] - s[i + a][j] - s[i][j + b] + s[i + a][j + b];
			cur -= (long long)w[i][j] * a * b;
			all.push_back (make_pair (cur, make_pair (i, j)));
		}
	sort (all.begin (), all.end ());
	for (int i = 0; i < all.size (); i++) {
		long long q = all[i].first;
		int x = all[i].second.first;
		int y = all[i].second.second;
		if (get (x + a, y + b) - get (max (x - a + 1, 0), y + b) - get (x + a, max (y - b + 1, 0)) + get (max (x - a + 1, 0), max (y - b + 1, 0)) == 0) {
			res.push_back (make_pair (make_pair (x, y), q));
			add (x + 1, y + 1);
		}
	}
	printf ("%d\n", res.size ());
	for (int i = 0; i < res.size (); i++)
		printf ("%d %d %I64d\n", res[i].first.first + 1, res[i].first.second + 1, res[i].second);
	return 0;
}