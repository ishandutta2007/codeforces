#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define j0 j5743892
#define j1 j542893
#define prev PREV
#define next NEXT
                         
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }
template<class T> T gcd(T a, T b) { re a ? gcd (b % a, a) : b; }
template<class T> T sqr(T a) { re a * a; }
template<class T> T sgn(T a) { re a > 0 ? 1 : (a < 0 ? -1 : 0); }

#define filename ""

int n;
int m;
int g[1010][1010];
int w[10][10][1010][1010];

int calc (int x1, int y1, int x2, int y2) {
	int a = 0, b = 0;
	while ((1 << (a + 1)) <= x2 - x1 + 1) a++;
	while ((1 << (b + 1)) <= y2 - y1 + 1) b++;
	int la = 1 << a;
	int lb = 1 << b;
	re max (max (w[a][b][x1][y1], w[a][b][x2 - la + 1][y1]), max (w[a][b][x1][y2 - lb + 1], w[a][b][x2 - la + 1][y2 - lb + 1]));
}

int main () {
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf ("%d", &g[i][j]);
	for (int i = n - 1; i >= 0; i--)
		for (int j = m - 1; j >= 0; j--)
			w[0][0][i][j] = (g[i][j] ? min (w[0][0][i + 1][j + 1], min (w[0][0][i + 1][j], w[0][0][i][j + 1])) + 1 : 0);
	for (int a = 0; a < 10; a++) {
		if (a > 0) {
			int la = 1 << (a - 1);
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					w[a][0][i][j] = max (w[a - 1][0][i][j], i + la < n ? w[a - 1][0][i + la][j] : 0);
		}
		for (int b = 1; b < 10; b++) {
			int lb = 1 << (b - 1);
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					w[a][b][i][j] = max (w[a][b - 1][i][j], j + lb < m ? w[a][b - 1][i][j + lb] : 0);
		}
	}
	int q;
	scanf ("%d", &q);
	for (int i = 0; i < q; i++) {
		int x1, y1, x2, y2;
		scanf ("%d%d%d%d", &x1, &y1, &x2, &y2); x1--; y1--; x2--; y2--;
		int l = 0, r = min (x2 - x1 + 1, y2 - y1 + 1) + 1;
		while (r - l > 1) {
			int s = (l + r) / 2;
			if (calc (x1, y1, x2 - s + 1, y2 - s + 1) >= s) l = s; else r = s;
		}
		printf ("%d\n", l);
	}
	return 0;
}