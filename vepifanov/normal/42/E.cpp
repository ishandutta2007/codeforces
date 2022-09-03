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
int p[400000];
pair<int, ii> v[400000];
int anc[400000][20];
int del[400000][20];
int tin[400000];
int tout[400000];
int ct = 0;
int was[400000];
vii w[400000];

int gp (int x) {
	if (p[x] != x) p[x] = gp (p[x]);
	re p[x];
}

int go (int x, int p, int l) {
	tin[x] = ct++;
	anc[x][0] = p;
	del[x][0] = l;
	was[x] = 1;
	for (int i = 0; i < 19; i++) {
		anc[x][i + 1] = anc[anc[x][i]][i];
		del[x][i + 1] = max (del[x][i], del[anc[x][i]][i]);
	}
	for (int i = 0; i < sz (w[x]); i++) {
		int y = w[x][i].fi;
		int z = w[x][i].se;
		if (y != p) go (y, x, z);
	}
	tout[x] = ct++;
	re 0;
}

inline int isanc (int a, int b) {
	re tin[a] <= tin[b] && tout[a] >= tout[b];
}

int up (int a, int b) {
	int j = 19, tmp = 0;
	while (!isanc (a, b))
		if (!isanc (anc[a][j], b) || j == 0) {
			tmp = max (tmp, del[a][j]);
			a = anc[a][j];
		} else j--;
	re tmp;
}

int main() {
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf ("%d%d%d", &a, &b, &c); a--; b--;
		v[i] = mp (c, mp (a, b));
	}
	for (int i = 0; i < n; i++) p[i] = i;
	sort (v, v + m);
	int k = n;
	long long ans = 0;
	for (int i = 0; i < m; i++) {
		int a = v[i].se.fi;
		int b = v[i].se.se;
		int c = v[i].fi;
		int aa = gp (a);
		int bb = gp (b);
		if (aa != bb) {
			k--;
			ans += c;
			if (rand () & 1) p[aa] = bb; else p[bb] = aa;
			w[a].pb (mp (b, c));
			w[b].pb (mp (a, c));
		}
	}
	memset (was, 0, sizeof (was));
	for (int i = 0; i < n; i++)
		if (!was[i])
			go (i, i, 0);
	int s;
	scanf ("%d", &s);
	for (int i = 0; i < s; i++) {
		int a, b;
		scanf ("%d%d", &a, &b); a--; b--;
		int aa = gp (a);
		int bb = gp (b);
		if (aa == bb) {	
			if (k > 1) printf ("-1\n"); else {
				int tmp = max (up (a, b), up (b, a));
				printf ("%I64d\n", ans - tmp);
			}
		} else {
			if (k > 2) printf ("-1\n"); else printf ("%I64d\n", ans);
		}
	}
	return 0;
}