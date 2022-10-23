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
#include <bitset>
#include <array>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) {fprintf(stderr, __VA_ARGS__);fflush(stderr);}
#else
	#define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

const int N = 200200;
int n;
vector<int> g[N];
ll a[N];
ll b[N];
ll dp[N][2];

void dfs(int v) {
	int k = (int)g[v].size();
	if (k == 0) {
		for (int i = 0; i < 2; i++)
			dp[v][i] = a[v] * (b[v] + i);
		return;
	}
	ll res = 0;
	vector<ll> c;
	for (int u : g[v]) {
		b[u] = b[v] / k;
		dfs(u);
		res += dp[u][0];
		c.push_back(dp[u][1] - dp[u][0]);
	}
	sort(all(c));
	reverse(all(c));
	k = b[v] % k;
	for (int i = 0; i < k; i++)
		res += c[i];
	dp[v][0] = res + b[v] * a[v];
	dp[v][1] = res + c[k] + (b[v] + 1) * a[v];
}

void solve() {
	scanf("%d%lld", &n, &b[0]);
	for (int i = 0; i < n; i++)
		g[i].clear();
	for (int i = 1; i < n; i++) {
		int v;
		scanf("%d", &v);
		v--;
		g[v].push_back(i);
	}
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	dfs(0);
	printf("%lld\n", dp[0][0]);
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0;
}