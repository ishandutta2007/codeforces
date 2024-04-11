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
#define uniq(x) (x).resize(unique(all(x))-(x).begin())
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

#define filename ""

int n;
int m;
int d;
int a[300];
int b[300];
int t[300];
ll res[2][150000];
pair<ll, int> q[150000];

int main () {
	scanf ("%d%d%d", &n, &m, &d);
	for (int i = 0; i < m; i++) scanf ("%d%d%d", &a[i], &b[i], &t[i]);
	for (int i = 0; i < n; i++) res[0][i] = 0;
	for (int i = 0; i < m; i++) {
		int ci = i & 1;
		int ni = 1 - ci;
		for (int j = 0; j < n; j++) res[ni][j] = -1e18;
		int dif = t[i];
		if (i > 0) dif -= t[i - 1]; else dif -= 1;
		dif = min ((ll)n, (ll)dif * d);
		{
			int l = 0, r = 0;
			for (int j = 0; j < n; j++) {
				while (r > 0 && q[r - 1].fi <= res[ci][j]) r--;
				q[r++] = mp (res[ci][j], j);
				while (q[l].se < j - dif) l++;
				res[ni][j] = max (res[ni][j], q[l].fi);
			}
		}
		{
			int l = 0, r = 0;
			for (int j = n - 1; j >= 0; j--) {
				while (r > 0 && q[r - 1].fi <= res[ci][j]) r--;
				q[r++] = mp (res[ci][j], j);
				while (q[l].se > j + dif) l++;
				res[ni][j] = max (res[ni][j], q[l].fi);
			}
		}
		for (int j = 0; j < n; j++)
			res[ni][j] += b[i] - abs (a[i] - 1 - j);
	}
	ll ans = -1e18;
	for (int i = 0; i < n; i++)
		ans = max (ans, res[m & 1][i]);
	cout << ans << endl;
	return 0;
}