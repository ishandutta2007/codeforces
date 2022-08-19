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

const int N = 100100;
const int M = 303;
int n, m;
pii ord[N];
int b[N];
int a[M][M];

void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n * m; i++) {
		scanf("%d", &ord[i].first);
		ord[i].second = -i;
	}
	sort(ord, ord + n * m);
	for (int i = 0; i < n * m; i++) {
		b[-ord[i].second] = i;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			a[i][j] = 0;
	int ans = 0;
	for (int i = 0; i < n * m; i++) {
		int x = b[i] / m;
		int y = b[i] % m;
		for (int j = 0; j < y; j++)
			ans += a[x][j];
		a[x][y] = 1;
	}
	printf("%d\n", ans);
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