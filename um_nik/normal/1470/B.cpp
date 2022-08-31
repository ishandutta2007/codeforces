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

const int N = (int)1e6 + 7;
int n;
int a[N];
int p[N];
int b[N];
int cnt[N];

void solve() {
	int ans0 = 0, ans1 = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		a[i] = b[a[i]];
		cnt[a[i]]++;
		ans0 = max(ans0, cnt[a[i]]);
	}
	for (int i = 0; i < n; i++) {
		int x = a[i];
		if (cnt[x] == 0) continue;
		if (x == 1 || cnt[x] % 2 == 0) {
			ans1 += cnt[x];
		}
		cnt[x] = 0;
	}
	ans1 = max(ans1, ans0);
	int q;
	scanf("%d", &q);
	while(q--) {
		int x;
		scanf("%d", &x);
		if (x == 0)
			printf("%d\n", ans0);
		else
			printf("%d\n", ans1);
	}
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int i = 2; i < N; i++) {
		if (p[i] != 0) continue;
		for (int j = i; j < N; j += i)
			if (p[j] == 0)
				p[j] = i;
	}
	b[1] = 1;
	for (int i = 2; i < N; i++) {
		int x = i / p[i];
		if (b[x] % p[i] == 0)
			b[i] = b[x] / p[i];
		else
			b[i] = b[x] * p[i];
	}

	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0;
}