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
#include <iomanip>
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

const int N = 105;
int n;
int d[N];
int s;
int t;

int main()
{
	startTime = clock();

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", d + i);
	}
	scanf("%d%d", &s, &t);
	int ss = s, tot = 0;
	while (s != t) {
		tot += d[s];
		s += 1;
		if (s > n) s = 1;
	}
	int ans = tot;
	tot = 0;
	s = ss;
	swap(s, t);
	while (s != t) {
		tot += d[s];
		s += 1;
		if (s > n) s = 1;
	}
	ans = min(ans, tot);
	printf("%d", ans);
	return 0;
}