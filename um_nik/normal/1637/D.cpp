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

const int N = (int)1e4 + 5;
int n;
int S;
bitset<N> dp;
int a[101];

int solve() {
	scanf("%d", &n);
	S = 0;
	int ans = 0;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	dp.reset();
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d", &y);
		x = a[i];
		ans += x * x + y * y;
		S += x + y;
		dp = (dp << x) | (dp << y);
	}
	int x = S / 2;
	while(!dp[x]) x--;
	ans *= n - 2;
	ans += x * x + (S - x) * (S - x);
	return ans;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) printf("%d\n", solve());

	return 0;
}