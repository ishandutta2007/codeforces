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

const int N = 300300;
int n;
int a[N];
int cnt[N];
int ans[N];

void solve() {
	scanf("%d", &n);
	for (int i = 0; i <= n; i++)
		cnt[i] = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		cnt[a[i]]++;
	}
	for (int i = 0; i < n; i++)
		ans[i] = 0;
	int l = 0, r = n - 1;
	for (int x = 1; x < n; x++) {
		if (cnt[x] == 0) break;
		ans[n - x] = 1;
		if ((a[l] != x && a[r] != x) || cnt[x] != 1) break;
		if (a[l] == x)
			l++;
		else
			r--;
	}
	ans[0] = 1;
	for (int x = 1; x <= n; x++)
		ans[0] &= (int)(cnt[x] == 1);
	for (int i = 0; i < n; i++)
		printf("%d", ans[i]);
	printf("\n");
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