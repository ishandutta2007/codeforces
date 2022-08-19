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

vector<vector<int>> a;
int n, m;

bool check(int v, int u) {
	for (int i = 0; i < n; i++) {
		vector<int> b = a[i];
		swap(b[v], b[u]);
		for (int j = 1; j < m; j++)
			if (b[j] < b[j - 1])
				return false;
	}
	return true;
}

void solve() {
	scanf("%d%d", &n, &m);
	a = vector<vector<int>>(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &a[i][j]);
	for (int i = 0; i < n; i++) {
		vector<int> b = a[i];
		sort(all(b));
		int v = -1, u = -1;
		for (int j = 0; j < m; j++) {
			if (b[j] == a[i][j]) continue;
			if (v == -1)
				v = j;
			else if (u == -1)
				u = j;
			else
				v = u = -2;
		}
		if (v == -2) {
			printf("-1\n");
			return;
		}
		if (v == -1) continue;
		if (check(v, u)) {
			printf("%d %d\n", v + 1, u + 1);
			return;
		}
		printf("-1\n");
		return;
	}
	printf("1 1\n");
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