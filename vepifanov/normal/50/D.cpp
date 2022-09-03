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
int e;
int x0, y0, x1, y1;
double res[101][101];
int d[101];
double p[101];

int main() {
	scanf ("%d%d%d", &n, &m, &e);
	scanf ("%d%d", &x0, &y0);
	for (int i = 0; i < n; i++) {
		scanf ("%d%d", &x1, &y1);
		d[i] = sqr (x1 - x0) + sqr (y1 - y0);
	}
	double l = 0, r = 10000;
	for (int it = 0; it < 100; it++) {
		double s = (l + r) / 2;
		memset (res, 0, sizeof (res));
		res[0][0] = 1000;
		for (int i = 0; i < n; i++)
			if (d[i] < s * s + 1e-7)
				p[i] = 1;
			else
				p[i] = exp (1 - d[i] / (s * s));
		for (int i = 0; i < n; i++)
			for (int j = 0; j <= i; j++) {
				res[i + 1][j] += res[i][j] * (1 - p[i]);
				res[i + 1][j + 1] += res[i][j] * p[i];
			}
		double ce = 0;
		for (int i = 0; i < m; i++) ce += res[n][i];
		if (ce > e) l = s; else r = s;
	}
	printf ("%.10f\n", (l + r) / 2);
	return 0;
}