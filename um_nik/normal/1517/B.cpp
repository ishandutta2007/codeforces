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

const int N = 111;
int n, m;
vector<ll> a[N];
ll ans[N][N];

void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		a[i] = vector<ll>(m, 0);
		for (int j = 0; j < m; j++)
			scanf("%lld", &a[i][j]);
		sort(all(a[i]));
	}
//	ll ans = 0;
	for (int it = 0; it < m; it++) {
		int p = 0;
		for (int i = 0; i < n; i++)
			if (a[i][0] < a[p][0]) p = i;
//		ans += a[p][0];
		for (int i = 0; i < n; i++) {
			if (i == p) {
				ans[it][i] = a[i][0];
//				printf("%lld ", a[i][0]);
				a[i].erase(a[i].begin());
			}
			else {
				ans[it][i] = a[i].back();
//				printf("%lld ", a[i].back());
				a[i].pop_back();
			}
		}
//		printf("\n");
	}
//	printf("%lld\n", ans);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			printf("%lld ", ans[j][i]);
		printf("\n");
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