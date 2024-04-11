#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin (),(x).end()
#define sqrt(x) sqrt(abs(x))
#define re return
#define sz(x) ((int)(x).size ())
#define prev PREV
#define next NEXT

using ll = long long;
using ii = pair<int, int>;
using ld = long double;
using D = double;
using vi = vector<int>;
using vii = vector<ii>;
using vvi = vector<vi>;
using vs = vector<string>;

template<typename T> T abs (T x) { re x < 0 ? -x : x; }
template<typename T> T sgn (T x) { re x < 0 ? -1 : (x > 0 ? 1 : 0); }
template<typename T> T sqr (T x) { re x * x; }
template<typename T> T gcd (T a, T b) { re a ? gcd (b % a, a) : b; }

int n;
int m;
char g[2001][2001];
int x1[26];
int y1[26];
int x2[26];
int y2[26];

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf ("%d%d", &n, &m);
		for (int i = 0; i < 26; i++) {
			x1[i] = n + 1;
			y1[i] = m + 1;
			x2[i] = -1;
			y2[i] = -1;
		}
		for (int i = 0; i < n; i++) {
			scanf (" %s", g[i]);
			for (int j = 0; j < m; j++)
				if (g[i][j] != '.') {
					int c = g[i][j] - 'a';
					x1[c] = min (x1[c], i);
					y1[c] = min (y1[c], j);
					x2[c] = max (x2[c], i);
					y2[c] = max (y2[c], j);
				}
		}
		int ok = 1;
		for (int i = 0; i < 26; i++) {
			if (x2[i] == -1) continue;
			if (int (x2[i] > x1[i]) + int (y2[i] > y1[i]) == 2) {
				ok = 0;
				break;
			}
			for (int x = x1[i]; x <= x2[i] && ok; x++)
				for (int y = y1[i]; y <= y2[i] && ok; y++)
					if (g[x][y] == '.' || g[x][y] < i + 'a')
						ok = 0;
		}
		int cnt = 26;
		while (cnt > 0 && x2[cnt - 1] == -1) cnt--;
		if (ok) {
			printf ("YES\n%d\n", cnt);
			for (int i = 0; i < cnt; i++) {
				int j = i;
				while (x2[j] == -1) j++;
				printf ("%d %d %d %d\n", x1[j] + 1, y1[j] + 1, x2[j] + 1, y2[j] + 1);
			}
		} else printf ("NO\n");
	}
	re 0;
}