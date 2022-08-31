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

const int N = 200200;
const int M = 101;
int a[N];
int d[N];
int n;
int cnt[N];
int ans = 0;

void solve(int b, int c) {
	for (int i = 0; i <= n; i++)
		d[i] = -1;
	int bal = cnt[b];
	d[bal] = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == b)
			bal--;
		else if (a[i] == c) bal++;
		if (d[bal] == -1) {
			d[bal] = i + 1;
		} else {
			ans = max(ans, i + 1 - d[bal]);
		}
	}
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		cnt[a[i]]++;
	}
	int b = 0;
	for (int i = 0; i < M; i++) {
		if (cnt[i] > cnt[b])
			b = i;
	}
	for (int i = 0; i < M; i++) {
		if (i == b) continue;
		solve(b, i);
	}
	printf("%d\n", ans);

	return 0;
}