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

const int N = 200050;
const int MOD = 998244353;
int n;
int a[N];

ll sub(ll x, ll y) {
	x -= y;
	return x >= 0 ? x : x + MOD;
}
ll mul(ll x, ll y) {
	return x * y % MOD;
}
ll bin_pow(ll x, ll y) {
	if(y == 0) return 1;
	if(y & 1) return mul(x, bin_pow(mul(x, x), y >> 1));
	else return bin_pow(mul(x, x), y >> 1);
}
ll inv(ll x) {
	return bin_pow(x, MOD - 2);
}

void solve() {
	scanf("%d", &n);
	int mx = 0;
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]), mx = max(mx, a[i]);
	int cnt = 0;
	for(int i = 0; i < n; i++)
		if(a[i] == mx)
			cnt++;
	ll ans = 1;
	for(int i = 2; i <= n; i++)
		ans *= i, ans %= MOD;
	if(cnt > 1) {
		printf("%lld\n", ans);
		return;	
	}
	cnt = 0;
	for (int i = 0; i < n; i++)
		if(a[i] == mx - 1)
			cnt++;
	printf("%lld\n", sub(ans, mul(ans, inv(cnt + 1))));
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