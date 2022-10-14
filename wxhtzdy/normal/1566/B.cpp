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
#include <iomanip>
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
char s[N];

void solve() {
	scanf("%s", s);
	int ans = 0;
	int n = strlen(s);
	int cnt = 1;
	for (int i = 0; i + 1 < n; i++) {
		if (s[i] != s[i + 1]) {
			cnt += 1;
		}
	}
	if (cnt > 3) {
		printf("2\n");
	} else if (cnt == 3) {
		printf("%d\n", 1 + (1 - (s[0] - '0')));
	} else if (cnt == 2) {
		printf("1\n");
	} else {
		printf("%d\n", 1 - (s[0] - '0'));
	}
}

int main()
{
	startTime = clock();

	int t;
	scanf("%d", &t);
	while(t--) {
		solve();
	}
	return 0;
}