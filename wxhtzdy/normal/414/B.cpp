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

const int N = 2005;
const int MOD = 1e9 + 7;
int n, k;
int dp[N][N];
vector<int> divs[N];

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int i = 1; i < N; i++)
		for(int j = i; j < N; j += i)
			divs[j].push_back(i);

	scanf("%d%d", &n, &k);
	dp[0][1] = 1;
	for(int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			for(int prv : divs[j]) {
				dp[i][j] += dp[i - 1][prv];
				if(dp[i][j] >= MOD)
					dp[i][j] -= MOD;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += dp[k][i];
		if(ans >= MOD)
			ans -= MOD;
	}
	printf("%d", ans);

	return 0;
}