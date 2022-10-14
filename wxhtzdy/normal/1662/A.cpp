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

int n;
int mx[15];

void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= 10; i++)
		mx[i] = -1;
	for (int i = 0; i < n; i++) {
		int b, d;
		scanf("%d%d", &b, &d);
		mx[d] = max(mx[d], b);
	}
	bool ok = true;
	for (int i = 1; i <= 10; i++)
		ok &= (mx[i] != -1);
	if (!ok) {
		printf("MOREPROBLEMS\n");
		return;
	}
	int ans = 0;
	for (int i = 1; i <= 10; i++)
		ans += mx[i];
	printf("%d\n", ans);
}

int main()
{
	startTime = clock();

	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0;
}