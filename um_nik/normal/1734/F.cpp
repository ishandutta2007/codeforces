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

const int K = 62;
ll n, m;
ll dp[K + 1][2][2][2];

void solve() {
	scanf("%lld%lld", &n, &m);
	for (int i = 0; i <= K; i++)
		for (int x = 0; x < 2; x++)
			for (int y = 0; y < 2; y++)
				for (int z = 0; z < 2; z++)
					dp[i][x][y][z] = 0;
	dp[0][1][0][0] = 1;
	for (int i = 0; i < K; i++)
		for (int x = 0; x < 2; x++)
			for (int y = 0; y < 2; y++)
				for (int z = 0; z < 2; z++) {
					ll w = dp[i][x][y][z];
					for (int c = 0; c < 2; c++) {
						int nx = x;
						int cc = (m >> i) & 1;
						if (c < cc) nx = 0;
						if (c > cc) nx = 1;
						int d = c + z + ((n >> i) & 1);
						int nz = (int)(d >= 2);
						int ny = y ^ c ^ (d & 1);
						dp[i + 1][nx][ny][nz] += w;
					}
				}
	printf("%lld\n", dp[K][0][1][0]);
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