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

const int N = 100100;
int k;
ll a[N];

bool solve(ll n, ll m) {
	ll res = 0;
	ll mx = 0;
	for (int i = 0; i < k; i++) {
		ll x = a[i] / n;
		if (x <= 1) continue;
		mx = max(mx, x);
		res += x;
	}
	if (res < m) return false;
	if (mx == 2 && m % 2 == 1) return false;
	return true;
}
void solve() {
	ll n, m;
	scanf("%lld%lld%d", &n, &m, &k);
	for (int i = 0; i < k; i++)
		scanf("%lld", &a[i]);
	if (solve(n, m) || solve(m, n)) 
		printf("Yes\n");
	else
		printf("No\n");
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0;
}