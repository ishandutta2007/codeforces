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

const int N = 1500500;
int n;
ll a[N];
int dp[N];
set<pli> s1, s2, s3;

void myAdd1(int p) {
	ll key = a[p];
	int val = dp[p] - p;
	auto it = s1.lower_bound(mp(key, N));
	if (it != s1.begin() && prev(it)->second >= val) return;
	while(true) {
		it = s1.lower_bound(mp(key, -N));
		if (it == s1.end()) break;
		if (it->second > val) break;
		s1.erase(it);
	}
	s1.insert(mp(key, val));
}
void myAdd2(int p) {
	ll key = a[p];
	int val = dp[p];
	auto it = s2.lower_bound(mp(key, -N));
	if (it != s2.end() && it->first == key) {
		if (it->second >= val) return;
		s2.erase(it);
		s2.insert(mp(key, val));
	} else {
		s2.insert(mp(key, val));
	}
}
void myAdd3(int p) {
	ll key = a[p];
	int val = dp[p] + p;
	auto it = s3.lower_bound(mp(key, -N));
	if (it != s3.end() && it->second >= val) return;
	while(true) {
		it = s3.lower_bound(mp(key, N));
		if (it == s3.begin()) break;
		it--;
		if (it->second > val) break;
		s3.erase(it);
	}
	s3.insert(mp(key, val));
}


void myAdd(int p) {
	myAdd1(p);
	myAdd2(p);
	myAdd3(p);
}

void solve() {
	scanf("%d", &n);
	ll x;
	a[0] = 0;
	for (int i = 0; i < n; i++) {
		scanf("%lld", &x);
		a[i + 1] = a[i] + x;
	}
	for (int i = 1; i <= n; i++)
		dp[i] = -n;
	dp[0] = 0;
	s1.clear();
	s2.clear();
	s3.clear();
	myAdd(0);
	for (int i = 1; i <= n; i++) {
		auto it = s1.lower_bound(mp(a[i], -N));
		if (it != s1.begin()) {
			it--;
			dp[i] = max(dp[i], it->second + i);
		}
		it = s2.lower_bound(mp(a[i], -N));
		if (it != s2.end() && it->first == a[i])
			dp[i] = max(dp[i], it->second);
		it = s3.lower_bound(mp(a[i], N));
		if (it != s3.end())
			dp[i] = max(dp[i], it->second - i);
		myAdd(i);
	}
	printf("%d\n", dp[n]);
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