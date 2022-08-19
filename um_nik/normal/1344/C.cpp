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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

double startTime;
double getCurrentTime() {
	return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}

const int N = 200200;
vector<int> g[2][N];
int col[2][N];
int n, m;
int ans[N];

bool dfs(int k, int v) {
	col[k][v] = 1;
	for (int u : g[k][v]) {
		if (col[k][u] == 0) {
			if (!dfs(k, u)) return false;
		} else if (col[k][u] == 1) {
			return false;
		}
	}
	col[k][v] = 2;
	return true;
}

int main()
{
	startTime = (double)clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	while(m--) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[0][v].push_back(u);
		g[1][u].push_back(v);
	}
	for (int v = 0; v < n; v++) {
		if (col[0][v] == 0 && col[1][v] == 0)
			ans[v] = 1;
		for (int i = 0; i < 2; i++) {
			if (col[i][v] != 0) continue;
			if (!dfs(i, v)) {
				printf("-1\n");
				return 0;
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
		cnt += ans[i];
	printf("%d\n", cnt);
	for (int i = 0; i < n; i++)
		if (ans[i] == 1)
			printf("A");
		else
			printf("E");
	printf("\n");

	return 0;
}