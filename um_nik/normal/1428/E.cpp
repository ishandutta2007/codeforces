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

const int N = 100100;
int n, k;
ll a[N];
ll b[N];
set<pli> setik;

ll getScore(ll x, ll y) {
	ll p = x / y;
	return p * p * (y - x % y) + (p + 1) * (p + 1) * (x % y);
}
ll getDelta(ll x, ll y) {
	return getScore(x, y + 1) - getScore(x, y);
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &k);
	k -= n;
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		b[i] = 1;
		if (b[i] < a[i]) setik.insert(mp(getDelta(a[i], b[i]), i));
	}
	while(k--) {
		assert(!setik.empty());
		int v = setik.begin()->second;
		setik.erase(setik.begin());
		b[v]++;
		if (b[v] < a[v]) setik.insert(mp(getDelta(a[v], b[v]), v));
	}
	ll ans = 0;
	for (int i = 0; i < n; i++)
		ans += getScore(a[i], b[i]);
	printf("%lld\n", ans);

	return 0;
}