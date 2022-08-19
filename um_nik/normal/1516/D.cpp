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

const int K = 17;
const int N = 100100;
int d[N];
int cnt[N];
int bad;
int a[N];
int jump[N][K];
int n;

void add(int x, int dx) {
	while(x > 1) {
		int p = d[x];
		while(x % p == 0) x /= p;
		if (cnt[p] >= 2) bad--;
		cnt[p] += dx;
		if (cnt[p] >= 2) bad++;
	}
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int i = 2; i < N; i++)
		d[i] = -1;
	for (int x = 2; x < N; x++) {
		if (d[x] != -1) continue;
		for (int y = x; y < N; y += x)
			if (d[y] == -1)
				d[y] = x;
	}

	int q;
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int r = 0;
	for (int l = 0; l < n; l++) {
		while(r < n && bad == 0) {
			add(a[r], 1);
			r++;
		}
		if (bad == 0)
			jump[l][0] = r;
		else
			jump[l][0] = r - 1;
		add(a[l], -1);
	}
	jump[n][0] = n;
	for (int k = 0; k < K - 1; k++) {
		for (int i = 0; i <= n; i++)
			jump[i][k + 1] = jump[jump[i][k]][k];
	}
	while(q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		l--;
		int ans = 0;
		for (int k = K - 1; k >= 0; k--) {
			if (jump[l][k] < r) {
				ans += 1 << k;
				l = jump[l][k];
			}
		}
		ans++;
		printf("%d\n", ans);
	}

	return 0;
}