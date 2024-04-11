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
int raa[1000][1000], rab[1000][1000], rba[1000][1000], rbb[1000][1000], pa[1000][1000], pb[1000][1000], g[1000][1000], wa[1000][1000], wb[1000][1000];

int go (int i1, int j1, int i2, int j2) {
	while (i1 < i2) {
		i1++;
		printf ("D");
	}
	while (j1 < j2) {
		j1++;
		printf ("R");
	}
	return 0;
}

int gob (int i, int j);

int goa (int i, int j) {
	if (i == 0 && j == 0) return 0;
	if (pa[i][j] == 1) { goa (i - 1, j); printf ("D"); }
	if (pa[i][j] == 2) { gob (i - 1, j); printf ("D"); }
	if (pa[i][j] == 3) { goa (i, j - 1); printf ("R"); }
	if (pa[i][j] == 4) { gob (i, j - 1); printf ("R"); }
	return 0;
}

int gob (int i, int j) {
	if (i == 0 && j == 0) return 0;
	if (pb[i][j] == 1) { goa (i - 1, j); printf ("D"); }
	if (pb[i][j] == 2) { gob (i - 1, j); printf ("D"); }
	if (pb[i][j] == 3) { goa (i, j - 1); printf ("R"); }
	if (pb[i][j] == 4) { gob (i, j - 1); printf ("R"); }
	return 0;
}

int main() {
	int n;
	scanf ("%d", &n);
	int ai = -1, aj = -1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			scanf ("%d", &g[i][j]);
			if (g[i][j] == 0) {
				ai = i;
				aj = j;
			}
			wa[i][j] = wb[i][j] = 0;
			raa[i][j] = rab[i][j] = rba[i][j] = rbb[i][j] = 1e9;
			if (g[i][j] == 0) { wa[i][j] = 2; wb[i][j] = 2; continue; }
			while (g[i][j] % 2 == 0) {
				wa[i][j]++;
				g[i][j] /= 2;
			}
			while (g[i][j] % 5 == 0) {
				wb[i][j]++;
				g[i][j] /= 5;
			}
		}
	raa[0][0] = rab[0][0] = rba[0][0] = rbb[0][0] = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			raa[i][j] += wa[i][j];
			rba[i][j] += wa[i][j];
			rab[i][j] += wb[i][j];
			rbb[i][j] += wb[i][j];
			if (i + 1 < n) {
				if (raa[i][j] < raa[i + 1][j] || raa[i][j] == raa[i + 1][j] && rab[i][j] < rab[i + 1][j]) {
					raa[i + 1][j] = raa[i][j];
					rab[i + 1][j] = rab[i][j];
					pa[i + 1][j] = 1;
				}
				if (rba[i][j] < raa[i + 1][j] || rba[i][j] == raa[i + 1][j] && rbb[i][j] < rab[i + 1][j]) {
					raa[i + 1][j] = rba[i][j];
					rab[i + 1][j] = rbb[i][j];
					pa[i + 1][j] = 2;
				}
				if (rab[i][j] < rbb[i + 1][j] || rab[i][j] == rbb[i + 1][j] && raa[i][j] < rba[i + 1][j]) {
					rba[i + 1][j] = raa[i][j];
					rbb[i + 1][j] = rab[i][j];
					pb[i + 1][j] = 1;
				}
				if (rbb[i][j] < rbb[i + 1][j] || rbb[i][j] == rbb[i + 1][j] && rba[i][j] < rba[i + 1][j]) {
					rba[i + 1][j] = rba[i][j];
					rbb[i + 1][j] = rbb[i][j];
					pb[i + 1][j] = 2;
				}
			}
			if (j + 1 < n) {
				if (raa[i][j] < raa[i][j + 1] || raa[i][j] == raa[i][j + 1] && rab[i][j] < rab[i][j + 1]) {
					raa[i][j + 1] = raa[i][j];
					rab[i][j + 1] = rab[i][j];
					pa[i][j + 1] = 3;
				}
				if (rba[i][j] < raa[i][j + 1] || rba[i][j] == raa[i][j + 1] && rbb[i][j] < rab[i][j + 1]) {
					raa[i][j + 1] = rba[i][j];
					rab[i][j + 1] = rbb[i][j];
					pa[i][j + 1] = 4;
				}
				if (rab[i][j] < rbb[i][j + 1] || rab[i][j] == rbb[i][j + 1] && raa[i][j] < rba[i][j + 1]) {
					rba[i][j + 1] = raa[i][j];
					rbb[i][j + 1] = rab[i][j];
					pb[i][j + 1] = 3;
				}
				if (rbb[i][j] < rbb[i][j + 1] || rbb[i][j] == rbb[i][j + 1] && rba[i][j] < rba[i][j + 1]) {
					rba[i][j + 1] = rba[i][j];
					rbb[i][j + 1] = rbb[i][j];
					pb[i][j + 1] = 4;
				}
			}
		}
	int ans = 1e9, ak = -1;
	if (min (raa[n - 1][n - 1], rab[n - 1][n - 1]) < ans) {
		ans = min (raa[n - 1][n - 1], rab[n - 1][n - 1]);
		ak = 0;
	}
	if (min (rba[n - 1][n - 1], rbb[n - 1][n - 1]) < ans) {
		ans = min (rba[n - 1][n - 1], rbb[n - 1][n - 1]);
		ak = 1;
	}
	if (ans > 1 && ai != -1) {
		printf ("1\n");
		go (0, 0, ai, aj);
		go (ai, aj, n - 1, n - 1);
	} else {
		printf ("%d\n", ans);
		if (ak == 0)
			goa (n - 1, n - 1);
		else    	
			gob (n - 1, n - 1);
	}
	printf ("\n");
	return 0;
}