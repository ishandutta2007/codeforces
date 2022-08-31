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

const int N = 500500;
int n, m;
vector<int> a[N];
vector<int> b[N];
int myId[N];
vector<int> g[N];
int ans[2][N];
bool used[N];

void addAns(vector<int> z) {
	for (int v : z)
		myId[v] = m;
	b[m++] = z;
}

void dfs(int v) {
	used[v] = 1;
	vector<int> tt;
	for (int u : g[v]) {
		if (used[u]) continue;
		dfs(u);
		if (myId[u] == -1)
			tt.push_back(u);
	}
	if (!tt.empty()) {
		tt.push_back(v);
		reverse(all(tt));
		addAns(tt);
	}
}

void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		a[i].clear();
		b[i].clear();
		g[i].clear();
		myId[i] = -1;
		used[i] = 0;
	}
	while(m--) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		a[v].push_back(u);
		a[u].push_back(v);
	}
	m = 0;
	for (int v = 0; v < n; v++) {
		sort(all(a[v]));
		a[v].resize(unique(a[v].begin(), a[v].end()) - a[v].begin());
		if ((int)a[v].size() == n - 1) continue;
		int u = 0;
		for (int x : a[v]) {
			if (u == v) u++;
			if (u == x) {
				u++;
			} else {
				break;
			}
		}
		if (u == v) u++;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	for (int v = 0; v < n; v++) {
		if (used[v] || g[v].empty()) continue;
		dfs(v);
		if (myId[v] == -1) {
			assert(m > 0);
			b[m - 1].push_back(v);
			myId[v] = m - 1;
		}
	}
	int k = 1;
	for (int v = 0; v < n; v++) {
		if (myId[v] != -1) continue;
		assert(g[v].empty());
		ans[0][v] = ans[1][v] = k++;
	}
	for (int i = 0; i < m; i++) {
		for (int j = 1; j < (int)b[i].size(); j++) {
			int v = b[i][j];
			ans[0][v] = k + j - 1;
			ans[1][v] = k + j;
		}
		int v = b[i][0];
		ans[0][v] = k + (int)b[i].size() - 1;
		ans[1][v] = k;
		k += (int)b[i].size();
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++)
			printf("%d ", ans[i][j]);
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