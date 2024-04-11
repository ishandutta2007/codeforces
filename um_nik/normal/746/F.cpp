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
int n, m, T;
int a[N];
int b[N];
multiset<int> small, big;
int sumAll = 0, sumBig = 0;
int ans = 0;

void addOne(int x) {
	eprintf("addOne %d\n", x);
	sumAll += x;
	if (big.empty() || x < *big.begin()) {
		small.insert(x);
	} else {
		sumBig += x / 2;
		big.insert(x);
	}
	while((int)big.size() > m) {
		x = *big.begin();
		big.erase(big.begin());
		sumBig -= x / 2;
		small.insert(x);
	}
	while(!small.empty() && (int)big.size() < m) {
		x = *small.rbegin();
		small.erase(small.find(x));
		sumBig += x / 2;
		big.insert(x);
	}
}
void remOne(int x) {
	eprintf("remOne %d\n", x);
	sumAll -= x;
	if (small.find(x) != small.end()) {
		small.erase(small.find(x));
	} else {
		sumBig -= x / 2;
		big.erase(big.find(x));
	}
	while((int)big.size() > m) {
		x = *big.begin();
		big.erase(big.begin());
		sumBig -= x / 2;
		small.insert(x);
	}
	while(!small.empty() && (int)big.size() < m) {
		x = *small.rbegin();
		small.erase(small.find(x));
		sumBig += x / 2;
		big.insert(x);
	}
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &m, &T);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		b[i + 1] = b[i] + x;
	}
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	int r = 0;
	for (int l = 0; l < n; l++) {
		while(r < n && sumAll - sumBig <= T) {
			addOne(a[r]);
			r++;
		}
		if (sumAll - sumBig <= T)
			ans = max(ans, b[r] - b[l]);
		else
			ans = max(ans, b[r - 1] - b[l]);
		remOne(a[l]);
	}
	printf("%d\n", ans);

	return 0;
}