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

const int M = 15;
const int N = (1 << M) + 7;
ll curSum[M + 2];
map<ll, int> mapchik;
int n;
vector<pli> trans[N];
int dp[N];
ll want;
ll ans[M + 2][2];

void makeTrans(ll x) {
	vector<pli> res;
	int mask = 0;
	ll st = x;
	while(true) {
		if (mapchik.count(x) == 0) return;
		int p = mapchik[x];
//		mapchik.erase(x);
		res.push_back(mp(x, p));
		ll y = want - (curSum[p] - x);
		if ((mask >> p) & 1) return;
		mask |= 1 << p;
		if (y == st) {
			trans[mask] = res;
			return;
		}
		x = y;
	}
}

void restoreAns(vector<pli> w) {
	w.push_back(w[0]);
	for (int i = 1; i < (int)w.size(); i++) {
		int p = w[i].second, q = w[i - 1].second;
		ans[p][0] = w[i].first;
		ans[p][1] = q + 1;
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	want = 0;
	for (int i = 0; i < n; i++) {
		int k;
		scanf("%d", &k);
		while(k--) {
			ll x;
			scanf("%lld", &x);
			mapchik[x] = i;
			curSum[i] += x;
			want += x;
		}
	}
	if (abs(want) % n != 0) {
		printf("No\n");
		return 0;
	}
	want /= n;
	for (auto t : mapchik) {
		makeTrans(t.first);
	}
	for (int mask = 1; mask < (1 << n); mask++)
		dp[mask] = -1;
	dp[0] = 0;
	for (int mask = 0; mask < (1 << n); mask++) {
		if (dp[mask] == -1) continue;
		int ss = (1 << n) - 1 - mask;
		for (int m2 = ss; m2 > 0; m2 = (m2 - 1) & ss) {
			if (trans[m2].empty()) continue;
			dp[mask | m2] = mask;
		}
	}
	int mask = (1 << n) - 1;
	if (dp[mask] == -1) {
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	while(mask > 0) {
		restoreAns(trans[mask ^ dp[mask]]);
		mask = dp[mask];
	}
	for (int i = 0; i < n; i++)
		printf("%lld %lld\n", ans[i][0], ans[i][1]);

	return 0;
}