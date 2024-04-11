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
char w[31][31];
int o, p[14], q[14], e, f[14];
int ai[28], aj[28], bi[28], bj[28];
int was[31][31];
int c[31][31];
int cnt[7][7];
int use[7], col[14];

int go (int i, int j) {
	if (i == 14) {
		memset (cnt, 0, sizeof (cnt));
		for (int i = 0; i < 28; i++) {
			int a = col[c[ai[i]][aj[i]]];
			int b = col[c[bi[i]][bj[i]]];
			if (a > b) swap (a, b);
			cnt[a][b]++;
		}
		for (int i = 0; i < 7; i++)
			for (int j = i; j < 7; j++)
				if (cnt[i][j] != 1)
					re 0;
		for (int i = 0; i < 14; i++)
			for (int a = 0; a < 2; a++)
				for (int b = 0; b < 2; b++)
					w[p[i] + a][q[i] + b] = col[i] + '0';
		re 1;
	}
	int ans = 0;
	for (int k = 0; k <= j; k++)
		if (use[k] < 2) {
			col[i] = k;
			use[k]++;
			ans += go (i + 1, min (6, j + int (j == k)));
			use[k]--;
		}
	re ans;
}

int main() {
	scanf ("%d%d", &n, &m);	
	gets (w[0]);
	for (int i = 0; i < n; i++) gets (w[i]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (w[i][j] != '.' && !was[i][j]) {
				was[i][j] = was[i + 1][j] = was[i][j + 1] = was[i + 1][j + 1] = 1;
				c[i][j] = c[i + 1][j] = c[i][j + 1] = c[i + 1][j + 1] = o;
				p[o] = i;
				q[o++] = j;
			}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (i + 1 < n && w[i][j] != '.' && w[i][j] == w[i + 1][j]) {
				ai[e] = i;
				aj[e] = j;
				bi[e] = i + 1;
				bj[e++] = j;
			}
			if (j + 1 < m && w[i][j] != '.' && w[i][j] == w[i][j + 1]) {
				ai[e] = i;
				aj[e] = j;
				bi[e] = i;
				bj[e++] = j + 1;
			}
		}
	ll ans = go (0, 0);
	for (int i = 2; i <= 7; i++) ans *= i;
	cout << ans << endl;
	for (int i = 0; i < n; i++)
		printf ("%s\n", w[i]);
	return 0;
}