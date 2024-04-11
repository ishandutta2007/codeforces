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

const int N = 200300;
const int MOD = 998244353;
int n;
int k;
int a[N];
int order[N];

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		order[i] = i;
	}
	sort(order, order + n, [&](int i, int j) {
		return a[i] > a[j];
	});
	vector<int> vec;
	for(int i = 0; i < k; i++)
		vec.push_back(order[i]);
	sort(vec.begin(), vec.end());
	ll sum = 0;
	for(int i = 0; i < k; i++)
		sum += a[vec[i]];
	printf("%lld ", sum);
	ll p = 1;
	for(int i = 0; i + 1 < k; i++)
		p *= (vec[i + 1] - vec[i]), p %= MOD;
	printf("%lld", p);
	return 0;
}