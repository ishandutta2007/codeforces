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
int d[N];
int ans[N][3];


int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int i = 2; i < N; i++) {
		if (d[i]) continue;
		for (int j = i; j < N; j += i)
			if (d[j] == 0)
				d[j] = i;
	}
	for (int i = 0; i < N; i++)
		ans[i][0] = ans[i][1] = 100;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		while(x > 1) {
			int p = d[x];
			int t = 0;
			while(x % p == 0) {
				x /= p;
				t++;
			}
			for (int j = 0; j < 2; j++) {
				if (t < ans[p][j])
					swap(t, ans[p][j]);
			}
			ans[p][2]++;
		}
	}
	ll res = 1;
	for (int p = 2; p < N; p++) {
		if (ans[p][2] <= n - 2) continue;
		int t = 0;
		if (ans[p][2] == n - 1)
			t = ans[p][0];
		else
			t = ans[p][1];
		while(t--) res *= p;
	}
	printf("%lld\n", res);

	return 0;
}