#include <cstdio>
#include <numeric>
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
#include <deque>
#include <cassert>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
#define prev PREV
#define j0 j1347829
#define j1 j234892
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

int n;
int m;
int g[2][1 << 18][64];
int gt[2][1 << 18];
int gc[2][1 << 18];
int o[2];
ii v[2][1 << 18];
int cv[6][6];
int mask[6];
int a[6];
int b[6];
int cost[1 << 6];


int go (int t, int i, int j, int cur, int li, int ri) {
	if (j == m) {
		i++;
		j = 0;
	}
	if (i == ri - li) {
		int k = o[t];
		int tot = 0;
		int ok = 1;
		for (int e = 0; e < (1 << m); e++) {
			int c = 0;
			for (int s = li; s < ri; s++)
				if ((mask[s] & e) == mask[s])
					c += a[s];
//			printf ("%d = %d\n", e, c);
			if (c > cost[e]) {
				ok = 0;
				break;
			}
			g[t][k][e] = c;
			tot += c;
		}
		if (ok) {
//			printf ("%d %d %d = %d %d\n", t, cur, tot, mask[li], g[t][k][4]);
			v[t][k] = mp (cur, k);
			gt[t][k] = tot;
			gc[t][k] = cur;
			o[t]++;
		}
		re 0;
	}
	go (t, i, j + 1, cur, li, ri);
	mask[li + i] ^= 1 << j;
	go (t, i, j + 1, cur + cv[li + i][j], li, ri);
	mask[li + i] ^= 1 << j;
	re 0;
}

int main () {
	scanf ("%d%d", &n, &m);
	int sa = 0, sb = 0;
	for (int i = 0; i < n; i++) {
		scanf ("%d", &a[i]);
		sa += a[i];
	}
	for (int i = 0; i < m; i++) {
		scanf ("%d", &b[i]);
		sb += b[i];
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf ("%d", &cv[i][j]);
	cerr << sa << " " << sb << endl;
	if (sa > sb) {
		printf ("-1\n");
		re 0;
	}
	int ctot = 0;
	for (int i = 0; i < (1 << m); i++) {
		cost[i] = 0;
		for (int j = 0; j < m; j++)
			if ((i >> j) & 1)
				cost[i] += b[j];
		ctot += cost[i];
	}
	int n1 = (n + 1) / 2;
	int n2 = n - n1;
	go (0, 0, 0, 0, 0, n1);
	go (1, 0, 0, 0, n1, n1 + n2);
//	cerr << o[0] << " " << o[1] << endl;
	sort (v[0], v[0] + o[0]);
	sort (v[1], v[1] + o[1]);
	int ans = 1e9;
	for (int i = 0; i < o[0]; i++)
		for (int j = 0; j < o[1] && v[0][i].fi + v[1][j].fi < ans; j++) {
			int ci = v[0][i].se;
			int cj = v[1][j].se;
//			printf ("%d %d = %d %d\n", ci, cj, v[0][i].fi, v[1][j].fi);
			int ok = int (gt[0][ci] + gt[1][cj] <= ctot);
			for (int k = 0; k < (1 << m) && ok; k++)
				if (g[0][ci][k] + g[1][cj][k] > cost[k])
					ok = 0;
			if (ok) ans = v[0][i].fi + v[1][j].fi;
		}
	printf ("%d\n", ans);
    return 0;
}