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

const int N = 1234;
int n, m;
char s[N][N];
int ansSz;
array<int, 4> ans[10101];

void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", s[i]);
	if (s[0][0] == '1') {
		printf("-1\n");
		return;
	}
	ansSz = 0;
	for (int x = n - 1; x >= 0; x--)
		for (int y = m - 1; y >= 0; y--) {
			if (s[x][y] == '0') continue;
			if (x > 0) {
				ans[ansSz++] = {x, y + 1, x + 1, y + 1};
			} else {
				ans[ansSz++] = {x + 1, y, x + 1, y + 1};
			}
		}
	printf("%d\n", ansSz);
	for (int i = 0; i < ansSz; i++) {
		for (int j = 0; j < 4; j++)
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
	while(t--) {
		solve();
	}

	return 0;
}