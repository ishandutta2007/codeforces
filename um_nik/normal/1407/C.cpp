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

int query(int p, int q) {
	printf("? %d %d\n", p, q);
	fflush(stdout);
	int x;
	scanf("%d", &x);
	return x;
}

const int N = 10100;
int n;
int ans[N];

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	vector<int> unknown;
	for (int i = 1; i <= n; i++)
		unknown.push_back(i);
	while((int)unknown.size() > 1) {
		int p = unknown.back();
		unknown.pop_back();
		int q = unknown.back();
		unknown.pop_back();
		int x = query(p, q);
		int y = query(q, p);
		if (x < y) {
			swap(x, y);
			swap(p, q);
		}
		ans[p] = x;
		unknown.push_back(q);
	}
	ans[unknown[0]] = n;
	printf("!");
	for (int i = 1; i <= n; i++) {
		printf(" %d", ans[i]);
	}
	printf("\n");
	fflush(stdout);

	return 0;
}