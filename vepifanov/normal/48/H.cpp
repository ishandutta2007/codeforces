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
int a, b, c;
char g[201][201];

int put (int i, int j, string s) {
	g[2 * i][2 * j] = s[0];
	g[2 * i][2 * j + 1] = s[1];
	g[2 * i + 1][2 * j] = s[2];
	g[2 * i + 1][2 * j + 1] = s[3];
	re 0;
}

int swap2 (char &a, char &b) {
	char c = a, d = b;
	if (a == '\\') c = '/';
	if (a == '/') c = '\\';
	if (b == '\\') d = '/';
	if (b == '/') d = '\\';
	a = d;
	b = c;
	re 0;
}

int rv (int i, int j) {
	swap2 (g[2 * i][2 * j], g[2 * i + 1][2 * j]);
	swap2 (g[2 * i][2 * j + 1], g[2 * i + 1][2 * j + 1]);
}

int rh (int i, int j) {
	swap2 (g[2 * i][2 * j], g[2 * i][2 * j + 1]);
	swap2 (g[2 * i + 1][2 * j], g[2 * i + 1][2 * j + 1]);
}

int main() {
	scanf ("%d%d", &n, &m);
	scanf ("%d%d%d", &a, &b, &c);
	memset (g, '.', sizeof (g));
	int i = 0, j = 0, ok = 1;
	for (int k = 0; k < a; k++)  {
		put (i, j, "####");
		j++;
		if (j == m) { j = 0; i++; }
	}
	if (j > 0) {
		for (int k = j; k < m; k++)
			if ((k & 1) == (j & 1)) put (i, k, "#//."); else put (i, k, "\\#.\\");
		for (int k = 0; k < j; k++)
			if ((k & 1) != (j & 1)) put (i + 1, k, "#//."); else put (i + 1, k, "\\#.\\");
	} else {
		for (int k = 0; k < m; k++)
			if (k & 1) put (i, k, "#//."); else put (i, k, "\\#.\\");
	}
	c -= m;
	i = n - 1;
	j = m - 1;
	while (c > 0) {
		if (c == 1) {
			for (int k = j + 1; k < m; k++)
				rh (i, k);
			for (int k = i + 1; k < n; k++)
				rv (k, j);
			c--;
			put (i, j, ".//#");
		} else {
			if (j > 0) {
				for (int k = i + 1; k < n; k++) {
					rv (k, j - 1);
					rv (k, j);
				}
				put (i, j - 1, ".//#");
				put (i, j, "\\.#\\");
				c -= 2;
				j--;
			} else {
				for (int k = i + 1; k < n; k++) rv (k, j);
				put (i, j, "\\.#\\");
				c--;
			}
		}
		j--;
		if (j < 0) { j = m - 1; i--; }
	}
	for (int i = 0; i < 2 * n; i++) {
		for (int j = 0; j < 2 * m; j++)
			printf ("%c", g[i][j]);
		printf ("\n");
	}
	return 0;
}