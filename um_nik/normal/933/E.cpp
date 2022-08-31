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

const ll INF = (ll)1e16;
const int N = 900300;
const int K = 40;
int n;
ll a[N];
ll sum[N];
ll dp[N][2];
int par[N][2][3];
int intPoint[N];
int m;
vector<int> ans;

ll getCost(int L, int R, int f1, int f2) {
	int len = R - L;
	if (len == 1) {
		if (a[L] == 0) return 0;
		if (f1 == 0 || f2 == 0) return -1;
		return a[L];
	}
	if (len == 2) {
		if (a[L] == a[L + 1]) return 0;
		if (a[L] < a[L + 1]) {
			if (f2 == 0) return -1;
			return abs(a[L + 1] - a[L]);
		} else {
			if (f1 == 0) return -1;
			return abs(a[L + 1] - a[L]);
		}
	}
	if (f1 == 0 && a[L] > a[L + 1]) return -1;
	if (f2 == 0 && a[R - 1] > a[R - 2]) return -1;
	ll cost = abs(sum[R] - sum[L]);
	if (len == 3) {
		if (a[L] + a[L + 2] <= a[L + 1]) return cost;
		if (f1 == 1 && f2 == 1) return cost;
		if (f1 == 0 && f2 == 0) return -1;
		return cost;
	}
	return cost;
}

void restoreAns(int L, int R, int f1, int f2) {
	//eprintf("restore %d %d %d %d\n", L, R, f1, f2);
	int len = R - L;
	if (len == 1) {
		return;
	}
	if (len == 2) {
		if (a[L] == 0 || a[L + 1] == 0) return;
		ans.push_back(L);
		return;
	}
	if (f1 == 0 && a[L] != 0 && a[L + 1] != 0) {
		ll x = min(a[L], a[L + 1]);
		ans.push_back(L);
		a[L] -= x;
		a[L + 1] -= x;
	}
	if (f2 == 0 && a[R - 1] != 0 && a[R - 2] != 0) {
		ll x = min(a[R - 1], a[R - 2]);
		ans.push_back(R - 2);
		a[R - 2] -= x;
		a[R - 1] -= x;
	}
	for (int i = L; i < R - 1; i++) {
		if (a[i] != 0 && a[i + 1] != 0) {
			ll x = min(a[i], a[i + 1]);
			ans.push_back(i);
			a[i] -= x;
			a[i + 1] -= x;
		}
	}
}
	
int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		sum[i + 1] = sum[i];
		if (i % 2 == 0)
			sum[i + 1] += a[i];
		else
			sum[i + 1] -= a[i];
	}
	for (int i = 0; i <= n; i++) {
		if (i < 5 || i > n - 5) {
			intPoint[m++] = i;
			continue;
		}
		if (a[i - 1] <= a[i - 2] || a[i] <= a[i + 1])
			intPoint[m++] = i;
	}
	for (int i = 0; i <= m; i++)
		dp[i][0] = dp[i][1] = -INF;
	dp[0][0] = 0;
	dp[0][1] = 0;
	for (int i = 0; i < m; i++)
		for (int f1 = 0; f1 < 2; f1++) {
			if (dp[i][f1] < 0) continue;
			for (int j = i + 1; j < min(m, i + K); j++) {
				for (int f2 = 0; f2 < 2 - f1; f2++)
					for (int f3 = 0; f3 < 2; f3++) {
						ll cost = getCost(intPoint[i], intPoint[j], f2, f3);
						if (cost == -1) continue;
						if (dp[i][f1] + cost > dp[j][f3]) {
							dp[j][f3] = dp[i][f1] + cost;
							par[j][f3][0] = i;
							par[j][f3][1] = f1;
							par[j][f3][2] = f2;
						}
					}
			}
		}
	int x = m - 1;
	int f = 0;
	if (dp[x][1] > dp[x][0])
		f = 1;
	while(x > 0) {
		restoreAns(intPoint[par[x][f][0]], intPoint[x], par[x][f][2], f);
		int nx = par[x][f][0];
		f = par[x][f][1];
		x = nx;
	}
	printf("%d\n", (int)ans.size());
	for (int y : ans)
		printf("%d\n", 1 + y);

	return 0;
}