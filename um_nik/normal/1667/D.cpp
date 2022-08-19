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
bool dp[N][2];
vector<int> g[N];

void dfs(int v, int par) {
	int z = (int)g[v].size();
	if (par == -1) z++;
	int odd = (z + 1) / 2, even = z / 2;
	for (int u : g[v]) if (u != par) {
		dfs(u, v);
		if (!dp[u][0] && !dp[u][1]) return;
		if (dp[u][0] && dp[u][1]) continue;
		if (dp[u][0])
			even--;
		else
			odd--;
	}
	if (odd < 0 || even < 0) return;
	dp[v][0] = even > 0;
	dp[v][1] = odd > 0;
}

void printAns(int v, int par, int k) {
	vector<int> A, B, C;
	int z = (int)g[v].size();
	int odd = (z + 1) / 2, even = z / 2;
	if (k == 0) {
		even--;
		A.push_back(par);
	} else {
		odd--;
		B.push_back(par);
	}
	for (int u : g[v]) if (u != par) {
		assert(dp[u][0] || dp[u][1]);
		if (dp[u][0] && dp[u][1]) {
			C.push_back(u);
			continue;
		}
		if (dp[u][0]) {
			even--;
			A.push_back(u);
		} else {
			odd--;
			B.push_back(u);
		}
	}
	assert(odd >= 0 && even >= 0);
	while(odd--) {
		B.push_back(C.back());
		C.pop_back();
	}
	while(even--) {
		A.push_back(C.back());
		C.pop_back();
	}
	assert(C.empty());
	while(!B.empty()) {
		if ((int)B.size() > (int)A.size()) {
			C.push_back(B.back());
			B.pop_back();
		} else {
			C.push_back(A.back());
			A.pop_back();
		}
	}
	int zz = (int)g[v].size() & 1;
	for (int u : C) {
		if (u == par) {
			printf("%d %d\n", v + 1, par + 1);
		} else {
			printAns(u, v, zz);
		}
		zz ^= 1;
	}
}

void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		g[i].clear();
		dp[i][0] = dp[i][1] = 0;
	}
	for (int i = 1; i < n; i++) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	dfs(0, -1);
	int z = (int)g[0].size();
	int odd = (z + 1) / 2, even = z / 2;
	vector<int> A, B, C;
	for (int v : g[0]) {
		if (!dp[v][0] && !dp[v][1]) {
			printf("NO\n");
			return;
		}
		if (dp[v][0] && dp[v][1]) {
			C.push_back(v);
			continue;
		}
		if (dp[v][0]) {
			even--;
			A.push_back(v);
		} else {
			odd--;
			B.push_back(v);
		}
	}
	if (odd < 0 || even < 0) {
		printf("NO\n");
		return;
	}
	printf("YES\n");
	while(odd--) {
		B.push_back(C.back());
		C.pop_back();
	}
	while(even--) {
		A.push_back(C.back());
		C.pop_back();
	}
	assert(C.empty());
	while(!B.empty()) {
		if ((int)B.size() > (int)A.size()) {
			C.push_back(B.back());
			B.pop_back();
		} else {
			C.push_back(A.back());
			A.pop_back();
		}
	}
	int zz = (int)g[0].size() & 1;
	for (int v : C) {
		printAns(v, 0, zz);
		zz ^= 1;
	}
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d|", &t);
	while(t--) solve();

	return 0;
}