#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Item {
	int c;
	int x;

	Item() : c(), x() {}
	Item(int _c, int _x) : c(_c), x(_x) {}
};

const ll INF = (ll)1e16;
const int N = 505;
int n, m, k;
vector<Item> a[N][N];
vector<Item> b[N][N];
ll s[N][N];
ll dp[N][N];
int DX[] = {0, 1, 1, 0};
int DY[] = {0, -1, 0, 1};

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &m, &k);
	while(k--) {
		int x, y, d, t, c;
		scanf("%d%d%d%d%d", &x, &y, &d, &t, &c);
		vector<pii> cur;
		for (int i = 0; i < 4; i++) {
			int xx = x + d * DX[i], yy = y + d * DY[i];
			int tt = xx + yy;
			if (tt < t || (tt - t) % 4 != i) continue;
			cur.push_back(mp(xx, yy));
		}
		if ((int)cur.size() > 2) throw;
		for (int i = 0; i < (int)cur.size(); i++) {
			s[cur[i].first][cur[i].second] += c;
			if (i == 1) {
				if (cur[0].first == cur[1].first)
					a[cur[1].first][cur[1].second].push_back(Item(c, cur[0].second));
				else if (cur[0].second == cur[1].second)
					b[cur[1].first][cur[1].second].push_back(Item(c, cur[0].first));
			}
		}
	}
	for (int x = 0; x < n; x++)
		for (int y = 0; y < m; y++)
			dp[x][y] = INF;
	dp[0][0] = 0;
	for (int x = 0; x < n; x++)
		for (int y = 0; y < m; y++) {
			ll w;
			w = dp[x][y];
			for (int xx = x + 1; xx < n; xx++) {
				for (Item I : b[xx][y]) {
					if (I.x >= x)
						w -= I.c;
				}
				w += s[xx][y];
				dp[xx][y] = min(dp[xx][y], w);
			}
			w = dp[x][y];
			for (int yy = y + 1; yy < m; yy++) {
				for (Item I : a[x][yy]) {
					if (I.x >= y)
						w -= I.c;
				}
				w += s[x][yy];
				dp[x][yy] = min(dp[x][yy], w);
			}
		}
	printf("%lld\n", dp[n - 1][m - 1]);

	return 0;
}