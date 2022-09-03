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
string s[1000];
int gd[1000][1000];
int gr[1000][1000];
int grt[1000][1000][10];

int main () {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> s[i];
	for (int i = n - 1; i >= 0; i--)
		for (int j = m - 1; j >= 0; j--) {
			gd[i][j] = gr[i][j] = 1;
			if (i + 1 < n && s[i + 1][j] == s[i][j]) gd[i][j] = gd[i + 1][j] + 1;
			if (j + 1 < m && s[i][j + 1] == s[i][j]) gr[i][j] = gr[i][j + 1] + 1;
			grt[i][j][0] = gr[i][j];
			for (int t = 1; t < 10; t++) {
				grt[i][j][t] = grt[i][j][t - 1];
				if (i + (1 << (t - 1)) < n) {
					grt[i][j][t] = min (grt[i][j][t], grt[i + (1 << (t - 1))][j][t - 1]);
//					printf ("upd grt %d %d = %d\n", i + (1 << t), j, grt[i + (1 << t)][j][t - 1]);
				}	
//				printf ("grt %d = %d | %d\n", t, grt[i][j][t], gr[i][j]);
			}
//			printf ("%d %d = %d %d\n", i, j, gr[i][j], gd[i][j]);
		}
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			int i1 = i;
			int i2 = i1 + gd[i1][j];
			int len = i2 - i1;
			if (i2 < n) {
				int i3 = i2 + gd[i2][j];
				if (i3 < n && i3 - i2 == len) {
					int i4 = i3 + gd[i3][j];
					if (i4 - i3 >= len) {
						i4 = i3 + len;
						int tmp = 0;
						while ((1 << (tmp + 1)) < 3 * len) tmp++;
						int cur = min (grt[i][j][tmp], grt[i + 3 * len - (1 << tmp)][j][tmp]);
//						printf ("%d %d %d %d\n", i1, j, i1 + 3 * len, j + 1);
						ans += cur;
					}
				}
			}
		}
	printf ("%d\n", ans);
	re 0;
}