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
double g[18][18];
double res[1 << 18];
int q[18];
double ans[18];

int main() {
	int n;
	scanf ("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf ("%lf", &g[i][j]);
	int nn = 1 << n;
	memset (res, 0, sizeof (res));
	res[0] = 1;
	for (int i = 0; i < nn; i++) {
		int k = 0;
		for (int j = 0; j < n; j++)
			if (((i >> j) & 1) == 0)
				q[k++] = j;
		if (k == 1) ans[q[0]] = res[i];
		if (k > 1) {
			int s = k * (k - 1) / 2;
			for (int x = 0; x < k; x++)
				for (int y = 0; y < k; y++)
					if (x != y)
						res[i + (1 << q[y])] += res[i] * g[q[x]][q[y]] / s;
		}
	}
	for (int i = 0; i < n; i++) printf ("%.10f ", ans[i]);
	printf ("\n");
	return 0;
}