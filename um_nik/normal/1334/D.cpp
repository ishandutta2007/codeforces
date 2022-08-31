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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

double startTime;
double getCurrentTime() {
	return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}

/*
n = 5
1 2 1 3 1 4 1 5 2 3 2 4 2 5 3 4 3 5 4 5 1
*/

void solve() {
	int n;
	ll L, R;
	scanf("%d%lld%lld", &n, &L, &R);
	L--;
	ll S = 0;
	for (int v = 1; L < R && v < n; v++) {
		ll len = n - v;
		if (S + 2 * len <= L) {
			S += 2 * len;
			continue;
		}
		for (int u = v + 1; u <= n; u++) {
			if (S == L && L < R) {
				printf("%d ", v);
				L++;
			}
			S++;
			if (S == L && L < R) {
				printf("%d ", u);
				L++;
			}
			S++;
		}
	}
	if (L < R) printf("1 ");
	printf("\n");
}

int main()
{
	startTime = (double)clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) solve();


	return 0;
}