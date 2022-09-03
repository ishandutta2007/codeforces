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
int m = 0;
int g[20][20], p[20], was[1001];

int go (int i, int j) {
	if (j == n) {
		re 1;
	}
	for (int k = 1; k <= 1000; k++)
		if (!was[k]) {
			g[j][i] = g[i][j] = k;
			int ok = 1;
			for (int a = 0; a < j && ok; a++)
				for (int b = a + 1; b < j && ok; b++)
					for (int c = b + 1; c < j && ok; c++) {
						int d = j;
						if (g[a][b] && g[c][d] && g[a][c] && g[b][d] && g[a][b] + g[c][d] != g[a][c] + g[b][d]) ok = 0;
						if (g[a][b] && g[c][d] && g[a][d] && g[b][c] && g[a][b] + g[c][d] != g[a][d] + g[b][c]) ok = 0;
						if (g[a][c] && g[b][d] && g[a][b] && g[c][d] && g[a][c] + g[b][d] != g[a][b] + g[c][d]) ok = 0;
						if (g[a][c] && g[b][d] && g[a][d] && g[b][c] && g[a][c] + g[b][d] != g[a][d] + g[b][c]) ok = 0;
						if (g[a][d] && g[b][c] && g[a][b] && g[c][d] && g[a][d] + g[b][c] != g[a][b] + g[c][d]) ok = 0;
						if (g[a][d] && g[b][c] && g[a][c] && g[b][d] && g[a][d] + g[b][c] != g[a][c] + g[b][d]) ok = 0;

					}
			if (ok) {
				was[k] = 1;
				int tmp;
				if (i + 1 == j) tmp = go (0, j + 1); else tmp = go (i + 1, j);
				if (tmp) re 1;
				was[k] = 0;
			}
			g[j][i] = g[i][j] = 0;
		}
	re 0;
}

int main() {
	scanf ("%d", &n);
	go (0, 1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf ("%d ", g[i][j]);
		printf ("\n");
	}
	return 0;
}