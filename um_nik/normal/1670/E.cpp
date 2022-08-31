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
int a[N], b[N];
int n;
int ed[N][2];
vector<int> g[N];
int m;

void dfs(int v, int par, int t) {
	for (int id : g[v]) if (id != par) {
		int u = ed[id][0] ^ ed[id][1] ^ v;
		b[id] = m + n * (t ^ 1);
		a[u] = m + n * t;
		m++;
		dfs(u, id, t ^ 1);
	}
}

void solve() {
	scanf("%d", &n);
	n = 1 << n;
	for (int i = 0; i < n; i++)
		g[i].clear();
	m = 1;
	for (int i = 1; i < n; i++) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[v].push_back(i);
		g[u].push_back(i);
		ed[i][0] = v;
		ed[i][1] = u;
	}
	a[0] = n;
	dfs(0, -1, 0);
	printf("1\n");
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
	for (int i = 1; i < n; i++)
		printf("%d ", b[i]);
	printf("\n");
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