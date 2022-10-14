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

const int N = 1005;
int n;
int a[N];
ll val[N];
vector<int> ids[13];

ll query(vector<int> v) {
	if (v.empty()) return 0;
	printf("? %d ", v.size());
	for (int i : v) printf("%d ", i);
	fflush(stdout);
	ll x;
	scanf("%lld", &x);
	return x;
}

int main() 
{
	startTime = clock();

	scanf("%d", &n);
	for (int i = 0, j = 0; i < (1 << 13) && j < n; i++) {
		if (__builtin_popcount(i) == 6) {
			a[j++] = i;
			for (int b = 0; b < 13; b++)
				if (i >> b & 1)
					ids[b].pb(j);
		}
	}
	for (int i = 0; i < 13; i++)
		val[i] = query(ids[i]);
	printf("! ");
	for (int i = 0; i < n; i++) {
		ll ans = 0;
		for (int j = 0; j < 13; j++)
			if ((a[i] >> j & 1) == 0)
				ans |= val[j];
		printf("%lld ", ans);
	}
	fflush(stdout);

	return 0;
}