#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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

const int N = 100100;
ll len[N];
ll block[N];

int getLen(int x) {
	int len = 0;
	while(x > 0) {
		x /= 10;
		len++;
	}
	return len;
}

int getDig(int x, int k) {
	vector<int> a;
	while(x > 0) {
		a.push_back(x % 10);
		x /= 10;
	}
	reverse(all(a));
	return a[k];
}

void solve() {
	ll t;
	scanf("%lld", &t);
	t--;
	for (int i = 1;; i++) {
		if (t < block[i]) {
			for (int j = 1;; j++) {
				if (t < len[j]) {
					printf("%d\n", getDig(j, t));
					return;
				} else {
					t -= len[j];
				}
			}
		} else {
			t -= block[i];
		}
	}
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int i = 1; i < N; i++)
		len[i] = getLen(i);
	for (int i = 1; i < N; i++)
		block[i] = block[i - 1] + len[i];

	int t;
	scanf("%d", &t);
	while(t--) {
		solve();
	}

	return 0;
}