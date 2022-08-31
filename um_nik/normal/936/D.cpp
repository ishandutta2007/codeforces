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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const ll INF = (ll)1e18;
const int N = (int)2e6 + 17;
int xs[N];
int n;
vector<int> blocks[2];
bool field[2][N];
int prefSum[2][N];
ll t;
ll dp[2][N];
int par[2][N];
int bst[2];
ll bstVal[2];
vector<int> shifts;
vector<pii> shots;

void makeShots(int k, ll x, int cnt) {
	x = xs[x] + dp[k][x] + (cnt - 1) * t;
	while(cnt--) {
		shots.push_back(mp((int)x, k));
		x -= t;
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int L;
	scanf("%d", &L);
	xs[n++] = 0;
	xs[n++] = L + 1;
	int m1, m2;
	scanf("%d%d%lld", &m1, &m2, &t);
	while(m1--) {
		int x;
		scanf("%d", &x);
		blocks[0].push_back(x);
		xs[n++] = x;
		xs[n++] = x + 1;
	}
	while(m2--) {
		int x;
		scanf("%d", &x);
		blocks[1].push_back(x);
		xs[n++] = x;
		xs[n++] = x + 1;
	}
	sort(xs, xs + n);
	n = unique(xs, xs + n) - xs;
	for (int k = 0; k < 2; k++)
		for (int x : blocks[k]) {
			int id = lower_bound(xs, xs + n, x) - xs;
			field[k][id] = 1;
		}
	for (int k = 0; k < 2; k++)
		for (int i = 1; i < n; i++)
			prefSum[k][i] = prefSum[k][i - 1] + (int)field[k][i];
	dp[0][0] = t;
	dp[1][0] = t;
	par[1][0] = -1;
	bst[0] = 0;
	bst[1] = 0;
	bstVal[0] = t;
	bstVal[1] = t;

	for (int id = 1; id < n; id++) {
		dp[0][id] = dp[1][id] = INF;
		for (int k = 0; k < 2; k++) {
			dp[k][id] = bstVal[k] + (ll)prefSum[k][id] * t - xs[id];
			if (dp[k][id] >= t) {
				dp[k][id] = INF;
				bst[k] = -1;
				bstVal[k] = INF;
				continue;
			}
			par[k][id] = bst[k];
			if (dp[k][id] < 0) {
				dp[k][id] = 0;
			//	bst[k] = id;
			//	bstVal[k] = dp[k][id] + xs[id] - (ll)prefSum[k][id] * t;
			}
		}
		for (int k = 0; k < 2; k++) {
			if (!field[k][id] && dp[k][id] > dp[k ^ 1][id]) {
				par[k][id] = -1;
				dp[k][id] = dp[k ^ 1][id];
			}
		}
		for (int k = 0; k < 2; k++) {
			ll curVal = dp[k][id] + xs[id] - (ll)prefSum[k][id] * t;
			if (curVal < bstVal[k]) {
				bstVal[k] = curVal;
				bst[k] = id;
			}
		}
	}
/*
	for (int i = 0; i < n; i++)
		printf("%d ", xs[i]);
	printf("\n");
	for (int k = 0; k < 2; k++) {
		for (int i = 0; i < n; i++)
			printf("%lld ", dp[k][i]);
		printf("\n");
	}
*/
	int x = n - 1;
	int k = 0;
	if (dp[k ^ 1][x] < dp[k][x]) k ^= 1;
	if (dp[k][x] == INF) {
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	while(x != 0 || k != 0) {
		//cerr << k << " " << x << endl;
		if (par[k][x] == -1) {
			shifts.push_back(xs[x]);
			k ^= 1;
			continue;
		}
		makeShots(k, par[k][x], prefSum[k][x] - prefSum[k][par[k][x]]);
		x = par[k][x];
	}
	reverse(shifts.begin(), shifts.end());
	printf("%d\n", (int)shifts.size());
	for (int z : shifts)
		printf("%d ", z);
	printf("\n");
	reverse(shots.begin(), shots.end());
	printf("%d\n", (int)shots.size());
	for (pii z : shots)
		printf("%d %d\n", z.first, 1 + z.second);

	return 0;
}