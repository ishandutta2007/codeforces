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

const int N = (1 << 20) + 3;
int n;
int a[N][2];
int b[N][2];
vector<int> g[N];
bool used[N];
int ord[N];
int ordSz;
int m;
int st;

int getOther(int id, int v) {
	return b[id][0] ^ b[id][1] ^ v;
}
void dfs(int v) {
	while(!g[v].empty()) {
		int id = g[v].back();
		g[v].pop_back();
		if (used[id]) continue;
		used[id] = 1;
		dfs(getOther(id, v));
		ord[ordSz++] = id;
	}
}
bool trySolve(int k) {
	m = 1 << k;
	for (int i = 0; i < m; i++)
		g[i].clear();
	for (int i = 0; i < n; i++)
		used[i] = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			b[i][j] = a[i][j] & (m - 1);
			g[b[i][j]].push_back(i);
		}
	}
	for (int v = 0; v < m; v++) {
		if ((int)g[v].size() % 2 == 1)
			return false;
	}
	ordSz = 0;
	for (int v = 0; v < m; v++) {
		if (g[v].empty()) continue;
		st = v;
		dfs(v);
		if (ordSz != n) return false;
	}
	return true;
}
void printAns(int k) {
	assert(trySolve(k));
	int v = st;
	printf("%d\n", k);
	for (int i = 0; i < n; i++) {
		int id = ord[i];
		if (b[id][0] == v) {
			printf("%d %d ", 2 * id + 1, 2 * id + 2);
			v = b[id][1];
		} else {
			printf("%d %d ", 2 * id + 2, 2 * id + 1);
			v = b[id][0];
		}
	}
	printf("\n");
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 2; j++)
			scanf("%d", &a[i][j]);
	int l = -1, r = 21;
	while(r - l > 1) {
		int x = (l + r) / 2;
		if (trySolve(x))
			l = x;
		else
			r = x;
	}
	printAns(l);

	return 0;
}