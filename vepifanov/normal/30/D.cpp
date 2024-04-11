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
int x[200000], y, q[200000], e[200000], w[200000], sl[200000], sr[200000];

bool myless (int i, int j) {
	re x[i] < x[j];
}

double dist (double x1, double y1, double x2, double y2) {
	re sqrt (sqr (x2 - x1) + sqr (y2 - y1));
}

int main() {
	scanf ("%d%d", &n, &m); m--;
	for (int i = 0; i <= n; i++) {
		scanf ("%d", &x[i]);
		q[i] = i;
	}
	sort (q, q + n, myless);
	scanf ("%d", &y);
	for (int i = 0; i < n; i++) w[q[i]] = i;
	double ans = 1e30, d = x[q[n - 1]] - x[q[0]];
	if (m == n) {
		ans = min (dist (x[n], y, x[q[0]], 0), dist (x[n], y, x[q[n - 1]], 0)) + d;
	} else {
		ans = min (dist (x[m], 0, x[q[0]], 0) + d + dist (x[q[n - 1]], 0, x[n], y), dist (x[m], 0, x[q[n - 1]], 0) + d + dist (x[q[0]], 0, x[n], y));
		for (int i = 0; i + 1 < n; i++) {
			ans = min (ans, dist (x[m], 0, x[q[0]], 0) + (x[q[i]] - x[q[0]]) + dist (x[q[i]], 0, x[n], y) + min (dist (x[n], y, x[q[i + 1]], 0), dist (x[n], y, x[q[n - 1]], 0)) + (x[q[n - 1]] - x[q[i + 1]]));
			ans = min (ans, dist (x[m], 0, x[q[i]], 0) + (x[q[i]] - x[q[0]]) + dist (x[q[0]], 0, x[n], y) + min (dist (x[n], y, x[q[i + 1]], 0), dist (x[n], y, x[q[n - 1]], 0)) + (x[q[n - 1]] - x[q[i + 1]]));
			ans = min (ans, dist (x[m], 0, x[q[i + 1]], 0) + (x[q[n - 1]] - x[q[i + 1]]) + dist (x[q[n - 1]], 0, x[n], y) + min (dist (x[n], y, x[q[0]], 0), dist (x[n], y, x[q[i]], 0)) + (x[q[i]] - x[q[0]]));
			ans = min (ans, dist (x[m], 0, x[q[n - 1]], 0) + (x[q[n - 1]] - x[q[i + 1]]) + dist (x[q[i + 1]], 0, x[n], y) + min (dist (x[n], y, x[q[0]], 0), dist (x[n], y, x[q[i]], 0)) + (x[q[i]] - x[q[0]]));
		}
	}
	printf ("%.10f\n", ans);
	return 0;
}