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
int res[1 << 24], pa[1 << 24], pb[1 << 24];
int x[24], y[24], g[24], gg[24][24], q[24];

int out (int x) {
	if (x == 0) printf ("0\n"); else {
		if (pb[x] == -1) {
			printf ("0 %d ", pa[x] + 1);
			out (x - (1 << pa[x]));
		} else {
			printf ("0 %d %d ", pa[x] + 1, pb[x] + 1);
			out (x - (1 << pa[x]) - (1 << pb[x]));
		}
	}
}

int main() {
	int X, Y, n;
	scanf ("%d%d%d", &X, &Y, &n);
	for (int i = 0; i < n; i++) scanf ("%d%d", &x[i], &y[i]);
	for (int i = 0; i < n; i++) g[i] = 2 * ((x[i] - X) * (x[i] - X) + (y[i] - Y) * (y[i] - Y));
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			gg[i][j] = g[i] / 2 + g[j] / 2 + (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);

	res[0] = 0;
	int nn = 1 << n;
	for (int i = 1; i < nn; i++) {
		res[i] = 1e9;
		int o = 0;
		for (int j = 0; j < n; j++)
			if (i & (1 << j))
				q[o++] = j;
		int j = q[0];
		if (res[i] > res[i - (1 << j)] + g[j]) {
			res[i] = res[i - (1 << j)] + g[j];
			pa[i] = j;
			pb[i] = -1;
		}
		int ii = i - (1 << j);
		for (int b = 1; b < o; b++) {
			int k = q[b];
			if (res[i] > res[ii - (1 << k)] + gg[j][k]) {
				res[i] = res[ii - (1 << k)] + gg[j][k];
				pa[i] = j;
				pb[i] = k;
			}
		}
	}
	printf ("%d\n", res[nn - 1]);
	out (nn - 1);
	return 0;
}