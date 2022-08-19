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

const int N = 100200;
const int K = 42;
int n, k;
vector<int> g[N];
int a[N];
int b[N][K];
int c[N][K];
int ans[N];

void dfs1(int v, int par) {
	b[v][0] ^= a[v];
	for (int u : g[v]) {
		if (u == par) continue;
		dfs1(u, v);
		for (int i = 0; i < k; i++)
			b[v][(i + 1) % k] ^= b[u][i];
	}
}
void dfs2(int v, int par) {
	for (int i = k / 2; i < k; i++)
		ans[v] ^= b[v][i] ^ c[v][i];
	for (int u : g[v]) {
		if (u == par) continue;
		for (int i = 0; i < k; i++) {
			int x = b[v][i] ^ c[v][i];
			x ^= b[u][(i + k - 1) % k];
			c[u][(i + 1) % k] ^= x;
		}
		dfs2(u, v);
	}
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &k);
	k *= 2;
	for (int i = 1; i < n; i++) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	dfs1(0, -1);
	dfs2(0, -1);
	for (int i = 0; i < n; i++)
		printf("%d ", min(1, ans[i]));
	printf("\n");

	return 0;
}