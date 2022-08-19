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

const int N = (int)1e6 + 7;
int a[N];
int pref[N];
int n, m;

bool solve() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i <= m + 1; i++)
		a[i] = pref[i] = 0;
	while(n--) {
		int x;
		scanf("%d", &x);
		a[x] = 1;
	}
	for (int i = 0; i <= m; i++)
		pref[i + 1] = pref[i] + a[i];
	for (int x = 1; x <= m; x++) if (a[x])
		for (int y = 1; x * y <= m; y++) if (!a[y])
			if (pref[min(m + 1, x * (y + 1))] > pref[x * y])
				return false;
	return true;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) {
		if (solve())
			printf("Yes\n");
		else
			printf("No\n");
	}

	return 0;
}