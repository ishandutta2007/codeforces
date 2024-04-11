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

const int N = 500500;
int n;
int a[N];
char str[N];

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%s", str);
	long long ans = 0;
	for (int i = 0; i < n; i++)
		ans += (str[i] == 'B' ? a[i] : 0);
	long long tmp = ans;
	long long s = 0;
	for (int i = 0; i < n; i++) {
		if (str[i] == 'B')
			s -= a[i];
		if (str[i] == 'A')
			s += a[i];
		ans = max(ans, tmp + s);
	}
	s = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (str[i] == 'B')
			s -= a[i];
		if (str[i] == 'A')
			s += a[i];
		ans = max(ans, tmp + s);
	}
	printf("%lld\n", ans);

	return 0;
}