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

const int N = 1010;
bool g[N][N];
int n, m, k;
vector<int> a, b;
int mt[N];
bool used[N];

bool dfs(int x) {
	if (used[x]) return false;
	used[x] = 1;
	for (int y = 0; y < k; y++) if (g[x][y]) {
		if (mt[y] == -1) {
			mt[y] = x;
			return true;
		}
	}
	for (int y = 0; y < k; y++) if (g[x][y]) {
		if (dfs(mt[y])) {
			mt[y] = x;
			return true;
		}
	}
	return false;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	while(n--) {
		int x;
		scanf("%d", &x);
		if (2 * x >= m) {
			printf("-1\n");
			return 0;
		}
		if (3 * x <= m)
			b.push_back(x);
		else
			a.push_back(x);
	}
	n = (int)a.size();
	k = (int)b.size();
	if (n > k) {
		printf("-1\n");
		return 0;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < k; j++) {
			if (a[i] % b[j] == 0 && 2 * a[i] + b[j] <= m)
				g[i][j] = 1;
		}
	for (int i = 0; i < k; i++)
		mt[i] = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			used[j] = 0;
		if (!dfs(i)) {
			printf("-1\n");
			return 0;
		}
	}
	printf("%d\n", k);
	for (int i = 0; i < k; i++) {
		if (mt[i] == -1) {
			printf("%d %d\n", 3 * b[i], 2 * b[i]);
		} else {
			printf("%d %d\n", 2 * a[mt[i]] + b[i], a[mt[i]] + b[i]);
		}
	}

	return 0;
}