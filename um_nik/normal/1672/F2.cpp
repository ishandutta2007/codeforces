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
pii a[N];
vector<int> g[N];
int id[N];
int m;
bool used[N];

void dfs(int v) {
	used[v] = 1;
	for (int u : g[v])
		if (!used[u])
			dfs(u);
	id[v] = m++;
}

void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i].first);
		a[i].first--;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i].second);
		a[i].second--;
	}
	sort(a, a + n);
	int k = 0;
	int Y = -1;
	int l = 0;
	while(l < n) {
		int r = l;
		while(r < n && a[l].first == a[r].first) r++;
		if (r - l > k) {
			k = r - l;
			Y = a[l].first;
		}
		l = r;
	}
	for (int v = 0; v < n; v++)
		g[v].clear();
	for (int i = 0; i < n; i++) {
		int v = a[i].first, u = a[i].second;
		if (v == Y || u == Y) continue;
		g[v].push_back(u);
	}
	m = 0;
	for (int i = 0; i < n; i++)
		used[i] = 0;
	for (int i = 0; i < n; i++)
		if (!used[i])
			dfs(i);
	for (int v = 0; v < n; v++)
		for (int u : g[v]) {
			if (id[v] <= id[u]) {
				printf("WA\n");
				return;
			}
		}
	printf("AC\n");
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