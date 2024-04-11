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

int a[4][2];

void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 2; j++)
			scanf("%d", &a[i][j]);
	int x, y;
	scanf("%d%d", &x, &y);
	if (a[0][0] > n / 2) {
		for (int i = 0; i < 3; i++)
			a[i][0] = n + 1 - a[i][0];
		x = n + 1 - x;
	}
	if (a[0][1] > n / 2) {
		for (int i = 0; i < 3; i++)
			a[i][1] = n + 1 - a[i][1];
		y = n + 1 - y;
	}
	for (int i = 0; i < 3; i++) {
		if (x == a[i][0] && y == a[i][1]) {
			printf("YES\n");
			return;
		}
	}
	int cntX = 0, cntY = 0;
	for (int i = 0; i < 3; i++) {
		if (x == a[i][0]) cntX++;
		if (y == a[i][1]) cntY++;
	}
	if (cntX >= 2 || cntY >= 2) {
		printf("YES\n");
		return;
	}
	/*
	for (int i = 0; i < 3; i++) {
		if (a[i][0] == 1 && a[i][1] == 1) {
			printf("NO\n");
			return;
		}
	}
	*/
	int cnt1 = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 2; j++)
			if (a[i][j] == 1) cnt1++;
	if (cnt1 == 4) {
		printf("NO\n");
		return;
	}
	for (int i = 0; i < 3; i++) {
		if (abs(x - a[i][0]) % 2 == 0 && abs(y - a[i][1]) % 2 == 0) {
			printf("YES\n");
			return;
		}
	}
	printf("NO\n");
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