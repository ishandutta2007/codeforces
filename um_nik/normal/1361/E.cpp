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

const int N = 100100;
int n, m;
vector<int> g[N];
vector<int> ANS;
int used[N];
int h[N];
int minH[N][2];
int st[N];
bool good[N];

bool dfs(int v) {
	used[v] = 1;
	for (int u : g[v]) {
		if (used[u] == 1) {
			int x = h[u];
			for (int i = 0; i < 2; i++)
				if (x < minH[v][i])
					swap(x, minH[v][i]);
			continue;
		}
		if (used[u] == 2) return false;
		h[u] = h[v] + 1;
		if (!dfs(u)) return false;
		for (int j = 0; j < 2; j++) {
			int x = minH[u][j];
			for (int i = 0; i < 2; i++) {
				if (x < minH[v][i])
					swap(x, minH[v][i]);
			}
		}
	}
	used[v] = 2;
	return true;
}
void dfsGood(int v) {
	st[h[v]] = v;
	if (h[v] > 0) {
		assert(minH[v][0] < h[v]);
		good[v] = minH[v][1] >= h[v] && good[st[minH[v][0]]];
	}
	for (int u : g[v])
		if (h[u] == h[v] + 1)
			dfsGood(u);
}
bool solve(int root) {
	for (int i = 0; i < n; i++) {
		used[i] = 0;
		h[i] = -1;
		minH[i][0] = minH[i][1] = N;
	}
	h[root] = 0;
	if (!dfs(root)) return false;
	for (int i = 0; i < n; i++)
		good[i] = false;
	good[root] = true;
	dfsGood(root);
	for (int v = 0; v < n; v++)
		if (good[v])
			ANS.push_back(v);
	return true;
}

void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		g[i].clear();
	for (int i = 0; i < m; i++) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[v].push_back(u);
	}
	ANS.clear();
	vector<int> ord(n);
	for (int i = 0; i < n; i++)
		ord[i] = i;
	shuffle(all(ord), rng);
	for (int i = 0; i < n && i < 150; i++) {
		if (solve(ord[i])) break;
	}
	if ((int)ANS.size() * 5 < n) {
		printf("-1\n");
	} else {
		sort(all(ANS));
		for (int x : ANS)
			printf("%d ", x + 1);
		printf("\n");
	}
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