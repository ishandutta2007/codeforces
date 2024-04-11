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

const int N = (int)1e6 + 7;
bool p[N];
int ans[N];

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int i = 2; i < N; i++)
		p[i] = 1;
	for (int i = 2; i < N; i++) {
		if (!p[i]) continue;
		for (int j = 2 * i; j < N; j += i)
			p[j] = 0;
	}
	ans[1] = 1;
	for (int i = 2; i < N; i++) {
		if (!p[i]) continue;
		ans[i]++;
		if ((ll)i * i < N) ans[i * i]--;
	}
	for (int i = 2; i < N; i++)
		ans[i] += ans[i - 1];

	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		printf("%d\n", ans[n]);
	}

	return 0;
}