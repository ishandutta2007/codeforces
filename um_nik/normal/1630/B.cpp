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

const int N = 200200;
int n;
int a[N];
int cnt[N];
int k;

void solve() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		cnt[i] = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		cnt[a[i]]++;
	}
	int w = (n + k + 1) / 2;
	int L = 1, R = n + 1;
	int r = 1, sum = 0;
	for (int l = 1; l <= n; l++) {
		while(r <= n && sum < w) {
			sum += cnt[r];
			r++;
		}
		if (sum < w) break;
		if (r - l < R - L) {
			L = l;
			R = r;
		}
		sum -= cnt[l];
	}
	printf("%d %d\n", L, R - 1);
	int lst = 0;
	int p = 0;
	sum = 0;
	for (int i = 0; i < n; i++) {
		if (L <= a[i] && a[i] < R) {
			sum++;
		} else {
			sum--;
		}
		if (p + 1 < k && sum > p) {
			p++;
			printf("%d %d\n", lst + 1, i + 1);
			lst = i + 1;
		}
	}
	printf("%d %d\n", lst + 1, n);
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