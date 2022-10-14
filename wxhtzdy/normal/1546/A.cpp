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

const int N = 105;
int n;
int a[N];
int b[N];

void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", b + i);
	}
	vector<int> dec, inc;
	for (int i = 1; i <= n; i++) {
		for (int j = a[i]; j < b[i]; j++) {
			inc.pb(i);
		}
		for (int j = b[i]; j < a[i]; j++) {
			dec.pb(i);
		}
	}
	if (inc.size() != dec.size()) {
		printf("-1\n");
		return;
	}
	printf("%d\n", inc.size());
	for (int i = 0; i < inc.size(); i++) {
		printf("%d %d\n", dec[i], inc[i]);
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