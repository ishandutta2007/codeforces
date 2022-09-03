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
int m, k;
int x1[100], y1[100], x2[100], y2[100], was[100][100];
vi res;

int check (int ai, int aj, int bi, int bj) {
	if (bi < 0 || bj < 0 || bi >= n || bj >= m || was[bi][bj]) re 0;
	if (ai > bi) swap (ai, bi);
	if (aj > bj) swap (aj, bj);
	if (ai != bi) {
		ai++;
		bj++;
	} else {
		aj++;
		bi++;
	}
	for (int i = 0; i < k; i++) {
		int ci = max (ai, x1[i]);
		int cj = max (aj, y1[i]);
		int di = min (bi, x2[i]);
		int dj = min (bj, y2[i]);
		if (ci < di && cj <= dj || ci <= di && cj < dj) re 0;
	}
	re 1;
}

int go (int i, int j) {
	was[i][j] = 1;
	int t = 1;
	if (check (i, j, i + 1, j)) t += go (i + 1, j);
	if (check (i, j, i - 1, j)) t += go (i - 1, j);
	if (check (i, j, i, j + 1)) t += go (i, j + 1);
	if (check (i, j, i, j - 1)) t += go (i, j - 1);
	re t;
}

int main() {
        scanf ("%d%d%d", &n, &m, &k);
        for (int i = 0; i < k; i++) scanf ("%d%d%d%d", &x1[i], &y1[i], &x2[i], &y2[i]);
        memset (was, 0, sizeof (was));
        for (int i = 0; i < n; i++)
        	for (int j = 0; j < m; j++)
        		if (!was[i][j]) res.pb (go (i, j));
	sort (all (res));	
	rep (i, sz (res)) printf ("%d ", res[i]);
	printf ("\n");
	return 0;
}