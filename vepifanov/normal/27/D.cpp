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
int g[100][100];
int u[100], v[100];
int was[100];

int _in (int a, int b, int c) {
	if (a == b || a == c) re 0;
	if (c < b) c += n;
	if (a > b && a < c || a + n > b && a + n < c) re 1;
	re -1;
}

int go (int x, int c) {
	was[x] = c;
	for (int i = 0; i < m; i++)
		if (g[x][i]) {
			if (was[i] == c) re 1;
			if (!was[i] && go (i, 3 - c)) re 1;
		}
	re 0;
}

int main() {
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf ("%d%d", &a, &b); a--; b--;
		u[i] = a;
		v[i] = b;
	}

	for (int i = 0; i < m; i++)
		for (int j = i + 1; j < m; j++)
			if (abs (_in (u[i], u[j], v[j]) - _in (v[i], u[j], v[j])) == 2)
				g[i][j] = g[j][i] = 1;
	memset (was, 0, sizeof (was));	
	for (int i = 0; i < m; i++)
		if (!was[i])
			if (go (i, 1)) {
				printf ("Impossible\n");
				re 0;
			}
	for (int i = 0; i < m; i++)
		if (was[i] == 1) printf ("i"); else printf ("o");
	printf ("\n");
	return 0;
}