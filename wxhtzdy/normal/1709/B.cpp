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

const int N = 100005;
int n, q;
int a[N];
ll pref[N][2];

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i < n; i++)
		pref[i][0] = pref[i - 1][0] + max(0, a[i - 1] - a[i]);
	for (int i = n - 2; i >= 0; i--)
		pref[i][1] = pref[i + 1][1] + max(0, a[i + 1] - a[i]);
	while(q--) {
		int s, t;
		scanf("%d%d", &s, &t);
		--s;
		--t;
		if (s < t)
			printf("%lld\n", pref[t][0] - pref[s][0]);
		else
			printf("%lld\n", pref[t][1] - pref[s][1]);
	}
	return 0;
}