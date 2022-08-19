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

const int N = 5050;
int n;
ll a[N][2];
bool used[N];

ll sqr(ll x) {
	return x * x;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld%lld", &a[i][0], &a[i][1]);
	used[0] = 1;
	printf("1");
	int v = 0;
	for (int it = 1; it < n; it++) {
		int u = -1;
		ll val = -1;
		for (int i = 0; i < n; i++) {
			if (used[i]) continue;
			ll z = sqr(a[v][0] - a[i][0]) + sqr(a[v][1] - a[i][1]);
			if (z > val) {
				val = z;
				u = i;
			}
		}
		used[u] = 1;
		printf(" %d", u + 1);
		v = u;
	}
	printf("\n");

	return 0;
}