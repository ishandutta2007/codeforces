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

const int N = 100100;
int n, m;
int a[N];
int ans[N];

int main()
{
	startTime = (double)clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < m; i++) {
		ans[i] = i;
		if (a[i] + i > n) {
			printf("-1\n");
			return 0;
		}
	}
	ans[m] = n;
	for (int i = m - 1; i >= 0; i--) {
		ans[i] = max(ans[i], ans[i + 1] - a[i]);
	}
	if (ans[0] > 0) {
		printf("-1\n");
		return 0;
	}
	for (int i = 0; i < m; i++)
		printf("%d ", ans[i] + 1);
	printf("\n");

	return 0;
}