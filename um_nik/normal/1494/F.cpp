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

const int N = 7030;
int n, m;
vector<int> g[N];
int pos[N];
bool used[N];
int ed[N][2];
int ans[N];
int ansSz;

int getOther(int id, int v) {
	return ed[id][0] ^ ed[id][1] ^ v;
}

void clear() {
	for (int i = 0; i < m; i++)
		used[i] = 0;
	for (int v = 1; v <= n; v++)
		pos[v] = 0;
	ansSz = 0;
}

void dfs(int v) {
	while(pos[v] < (int)g[v].size()) {
		int id = g[v][pos[v]];
		pos[v]++;
		if (used[id]) {
			continue;
		}
		used[id] = 1;
		dfs(getOther(id, v));
		ans[ansSz++] = id;
	}
}

void findEuler(int v) {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		int deg = 0;
		for (int id : g[i])
			if (!used[id])
				deg ^= 1;
		if (deg && i != v) cnt++;
	}
	if (cnt >= 2) return;
	dfs(v);
}

void printAns(int v, vector<int> toOdd) {
	eprintf("printAns\n");
	eprintf("v = %d\n", v);
	eprintf("toOdd: ");
	for (int id : toOdd)
		eprintf("%d ", id);
	eprintf("\n");
	for (int i = ansSz - 1; i >= 0; i--)
		v = getOther(ans[i], v);
	printf("%d\n", 1 + ansSz + 1 + 2 * (int)toOdd.size());
	printf("%d", v);
	for (int i = 0; i < ansSz; i++) {
		v = getOther(ans[i], v);
		printf(" %d", v);
	}
	printf(" -1");
	for (int id : toOdd) {
		printf(" %d %d", getOther(id, v), v);
	}
	printf("\n");
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 2; j++) {
			scanf("%d", &ed[i][j]);
			g[ed[i][j]].push_back(i);
		}
	}
	for (int v = 1; v <= n; v++) {
		vector<int> toOdd;
		for (int id : g[v]) {
			int u = getOther(id, v);
			if ((int)g[u].size() & 1)
				toOdd.push_back(id);
		}
		clear();
		for (int id : toOdd)
			used[id] = 1;
		findEuler(v);
		if (ansSz + (int)toOdd.size() == m) {
			printAns(v, toOdd);
			return 0;
		}
		for (int i = 0; i < (int)toOdd.size(); i++) {
			clear();
			for (int j = 0; j < (int)toOdd.size(); j++)
				if (j != i)
					used[toOdd[j]] = 1;
			findEuler(v);
			if (ansSz + (int)toOdd.size() - 1 == m) {
				toOdd.erase(toOdd.begin() + i);
				printAns(v, toOdd);
				return 0;
			}
		}
	}
	printf("0\n");

	return 0;
}