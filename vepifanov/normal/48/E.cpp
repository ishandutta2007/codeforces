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
int m, k;
int was[201][201], d[201][201], qn[80000], qm[80000], np[201], nq[201], MP[201], mq[201], cnt[201][201], res[201][201];
int p, q;
vector<ii> v[201][201];

int main() {
	scanf ("%d%d%d", &n, &m, &k);
	scanf ("%d", &p);
	for (int i = 1; i <= p; i++) scanf ("%d%d", &np[i], &MP[i]);
	scanf ("%d", &q);
	for (int i = 1; i <= q; i++) scanf ("%d%d", &nq[i], &mq[i]);
	int l = 0, r = 1;
	qn[0] = n;
	qm[0] = m;
	was[n][m] = 1;
	d[n][m] = 0;
	while (l < r) {
		int n = qn[l];
		int m = qm[l];
		l++;
		for (int i = 1; i <= p && i <= n; i++) {
			int nn = n - i + np[i];
			int nm = m + MP[i];
			if (nn + nm <= k) {
				v[nn][nm].pb (mp (n, m));
				cnt[n][m]++;
	                }
			if (nn + nm <= k && !was[nn][nm]) {
				was[nn][nm] = 1;
				d[nn][nm] = d[n][m] + 1;
				qn[r] = nn;
				qm[r++] = nm;
			}
		}
		for (int i = 1; i <= q && i <= m; i++) {
			int nn = n + nq[i];
			int nm = m - i + mq[i];
			if (nn + nm <= k) {
				v[nn][nm].pb (mp (n, m));
				cnt[n][m]++;
	                }
			if (nn + nm <= k && !was[nn][nm]) {
				was[nn][nm] = 1;
				d[nn][nm] = d[n][m] + 1;
				qn[r] = nn;
				qm[r++] = nm;
			}
		}
	}
	if (was[0][0]) printf ("Ivan\n%d\n", d[0][0]); else {
		int l = 0, r = 0;
		for (int i = 0; i <= k; i++)
			for (int j = 0; i + j <= k; j++)
				if (was[i][j] && cnt[i][j] == 0) {
					res[i][j] = 1;
					was[i][j] = 3;
					qn[r] = i;
					qm[r++] = j;
				}
		while (l < r) {
			int n = qn[l];
			int m = qm[l++];
			for (int i = 0; i < sz (v[n][m]); i++) {
				int pn = v[n][m][i].fi;
				int pm = v[n][m][i].se;
				if (was[pn][pm] < 3 || res[pn][pm] < res[n][m] + 1) {
					was[pn][pm] = 3;
					res[pn][pm] = res[n][m] + 1;
				}
				cnt[pn][pm]--;
				if (cnt[pn][pm] == 0) {
					qn[r] = pn;
					qm[r++] = pm;
				}
			}
		}
		if (cnt[n][m]) printf ("Draw\n"); else printf ("Zmey\n%d\n", res[n][m]);
	}
	return 0;
}