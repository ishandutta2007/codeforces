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

const int N = 1010;
int a[N];
int ans[2 * N];
int ansSz;
int n;
bool used[N];

int getMex() {
	for (int i = 0; i <= n; i++)
		used[i] = false;
	for (int i = 0; i < n; i++)
		used[a[i]] = true;
	int x = 0;
	while(used[x]) x++;
	return x;
}

void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	ansSz = 0;
	while(true) {
		int x = getMex();
		if (x == n) {
			int p = -1;
			for (int i = 0; p == -1 && i < n; i++)
				if (a[i] != i)
					p = i;
			if (p == -1) break;
			ans[ansSz++] = p;
			a[p] = x;
		} else {
			assert(a[x] != x);
			ans[ansSz++] = x;
			a[x] = x;
		}
	}
	printf("%d\n", ansSz);
	for (int i = 0; i < ansSz; i++)
		printf("%d ", ans[i] + 1);
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