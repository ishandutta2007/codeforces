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
int a[N];
int ANS;
set<int> setik[N];
int id[N];
int X[N];

void dfs(int v, int par) {
	int big = -1;
	for (int u : g[v]) if (u != par) {
		dfs(u, v);
		if (big == -1 || (int)setik[id[big]].size() < (int)setik[id[u]].size())
			big = u;
	}
	if (big == -1) {
		id[v] = v;
		X[v] = 0;
		setik[v].insert(a[v]);
		return;
	}
	id[v] = id[big];
	bool bad = false;
	X[id[v]] ^= a[v];
	if (setik[id[v]].count(X[id[v]])) bad = true;
	setik[id[v]].insert(X[id[v]] ^ a[v]);
	for (int u : g[v]) if (u != par && u != big) {
		for (int z : setik[id[u]]) {
			int w = z ^ X[id[u]] ^ X[id[v]];
			if (setik[id[v]].count(w)) bad = true;
		}
		for (int z : setik[id[u]]) {
			int w = z ^ X[id[u]] ^ X[id[v]] ^ a[v];
			setik[id[v]].insert(w);
		}
	}
	if (bad) {
		ANS++;
		setik[id[v]].clear();
	}
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i < n; i++) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	dfs(0, -1);
	printf("%d\n", ANS);

	return 0;
}