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
int n, k;
char s[N];

void solve() {
	scanf("%d%d %s", &n, &k, s);
	int sum = 0, p = -1, q = -1;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') {
			if (p == -1) p = i;
			q = i;
			sum++;
		}
	}
	if (p == -1) {
		printf("0\n");
	} else if (p == q) {
		if (n - 1 - p <= k) {
			printf("1\n");
		} else if (p <= k) {
			printf("10\n");
		} else {
			printf("11\n");
		}
	} else {
		sum *= 11;
		if (n - 1 - q <= k) {
			k -= n - 1 - q;
			sum -= 10;
		}
		if (p <= k) {
			sum--;
		}
		printf("%d\n", sum);
	}
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