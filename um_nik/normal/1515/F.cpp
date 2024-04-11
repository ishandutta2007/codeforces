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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__);fflush(stderr);
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

const int N = 300300;
int n, m;
ll a[N];
ll X;
vector<int> g[N];
bool used[N];
int ed[N][2];
int ans[N];
int L, R;

int getOther(int id, int v) {
	return ed[id][0] ^ ed[id][1] ^ v;
}

void dfs(int v, int par) {
	used[v] = 1;
	for (int id : g[v]) {
		int u = getOther(id, v);
		if (used[u]) continue;
		dfs(u, id);
	}
	if (par != -1) {
		if (a[v] >= X) {
			ans[L++] = par;
			a[getOther(par, v)] += a[v] - X;
		} else {
			ans[--R] = par;
		}
	}
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d%lld", &n, &m, &X);
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		sum += a[i];
	}
	if (sum < X * (n - 1)) {
		printf("NO\n");
		return 0;
	}
	L = 0;
	R = n - 1;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 2; j++) {
			scanf("%d", &ed[i][j]);
			ed[i][j]--;
			g[ed[i][j]].push_back(i);
		}
	}
	dfs(0, -1);
	assert(L == R);
	printf("YES\n");
	for (int i = 0; i < n - 1; i++)
		printf("%d\n", ans[i] + 1);

	return 0;
}