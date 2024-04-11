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

const int N = 1000100;
int n, m;
int a[N];
int cnt[N];
int dp[N];
bool ok[N];
int ans[N];
int ansSz;

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (a[i] <= m)
			cnt[a[i]]++;
	}
	for (int i = 1; i <= m; i++)
		for (int j = i; j <= m; j += i)
			dp[j] += cnt[i];
	int id = 0;
	for (int i = 1; i <= m; i++)
		if (dp[i] > dp[id])
			id = i;
	if (id == 0)
		id = 1;
	for (int i = 1; i <= m; i++)
		if (id % i == 0)
			ok[i] = true;
	for (int i = 0; i < n; i++)
		if (a[i] <= m && ok[a[i]])
			ans[ansSz++] = i + 1;
	printf("%d %d\n", id, ansSz);
	for (int i = 0; i < ansSz; i++)
		printf("%d ", ans[i]);

	return 0;
}