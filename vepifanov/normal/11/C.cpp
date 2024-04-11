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
#define i0 i243573
#define j0 j3847593

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

const int di[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dj[8] = {0, 1, 0, -1, 1, -1, 1, -1};

int n;
int m;
int i0, j0, i2, j2, c, ct;
char g[300][300];
int was[300][300];

int go (int i, int j) {
	c++;
	i0 = min (i0, i);
	j0 = min (j0, j);
	i2 = max (i2, i);
	j2 = max (j2, j);
	was[i][j] = ct;
	for (int k = 0; k < 8; k++) {
		int ni = i + di[k];
		int nj = j + dj[k];
		if (ni >= 0 && nj >= 0 && ni < n && nj < m && was[ni][nj] != ct && g[ni][nj] == '1')
			go (ni, nj);
	}
	return 0;
}

int main() {
	int tt;
	scanf ("%d\n", &tt);
	for (int it = 0; it < tt; it++) {
		scanf ("%d%d\n", &n, &m);
		ct++;
		for (int i = 0; i < n; i++) gets (g[i]);
		int ans = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (g[i][j] == '1' && was[i][j] != ct) {
					i0 = i2 = i;
					j0 = j2 = j;
					c = 0;
					go (i, j);
					if (c % 4 != 0) continue;
					c /= 4;
					if (i0 == i && j0 == j) {
						if (i + c >= n || j + c >= m) continue;
						ans++;
						for (int k = 0; k <= c; k++) 
							if (g[i + k][j] != '1' || g[i][j + k] != '1' || g[i + c][j + k] != '1' || g[i + k][j + c] != '1') {
								ans--;
								break;
							}
					} else {
						if (j - c < 0 || j + c >= m || i + 2 * c >= n) continue;
						ans++;
						for (int k = 0; k <= c; k++) 
							if (g[i + k][j + k] != '1' || g[i + k][j - k] != '1' || g[i + k + c][j + k - c] != '1' || g[i + k + c][j - k + c] != '1') {
								ans--;
								break;
							}
					}
				}

		printf ("%d\n", ans);
	}
	return 0;
}