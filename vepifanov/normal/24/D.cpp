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
double g[1001][1001], w[1001][1001];

int main() {
	int n, m, p, q;
	scanf ("%d%d%d%d", &n, &m, &p, &q); p--; q--; 
	p = n - p;
	for (int i = 1; i < p; i++) {
		for (int j = 0; j < m; j++) {
			int k = 2;
			if (j > 0) { w[j][j - 1] = -1; k++; }
			if (j + 1 < m) { w[j][j + 1] = -1; k++; }
			w[j][j] = k - 1;
			w[j][m] = g[i - 1][j] + k;
		}
		for (int j = 0; j + 1 < m; j++) {
			if (fabs (w[j][j] < 1e-8)) {
				for (int k = max (j - 1, 0); k <= min (j + 2, m - 1); k++) swap (w[j][k], w[j + 1][k]);
				swap (w[j][m], w[j + 1][m]);
			}
			double tmp = w[j + 1][j] / w[j][j];
			for (int k = max (j - 1, 0); k <= min (j + 2, m - 1); k++) w[j + 1][k] -= w[j][k] * tmp;
			w[j + 1][m] -= w[j][m] * tmp;
		}
		for (int j = m - 1; j > 0; j--) {
			double tmp = w[j - 1][j] / w[j][j];
			for (int k = max (j - 2, 0); k <= min (j + 1, m - 1); k++) w[j - 1][k] -= w[j][k] * tmp;
			w[j - 1][m] -= w[j][m] * tmp;
		}
		for (int j = 0; j < m; j++)
			g[i][j] = w[j][m] / w[j][j];
	}
	printf ("%.10f\n", g[p - 1][q]);
	return 0;
}