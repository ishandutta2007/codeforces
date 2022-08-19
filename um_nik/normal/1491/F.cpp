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

bool readAns() {
	int x;
	scanf("%d", &x);
	assert(abs(x) <= 1);
	return x != 0;
}

void solve() {
	int n;
	scanf("%d", &n);
	int p = 2;
	while(true) {
		printf("? %d 1\n", p - 1);
		for (int i = 1; i < p; i++)
			printf("%d ", i);
		printf("\n%d\n", p);
		fflush(stdout);
		if (readAns()) break;
		p++;
	}
	vector<int> ans;
	for (int i = p + 1; i <= n; i++) {
		printf("? 1 1\n%d\n%d\n", p, i);
		fflush(stdout);
		if (!readAns()) ans.push_back(i);
	}
	int l = 1, r = p;
	while(l + 1 < r) {
		int mid = (l + r) / 2;
		printf("? %d 1\n", mid - l);
		for (int i = l; i < mid; i++)
			printf("%d ", i);
		printf("\n%d\n", p);
		fflush(stdout);
		if (readAns())
			r = mid;
		else
			l = mid;
	}
	for (int i = 1; i < p; i++)
		if (i != l)
			ans.push_back(i);
	printf("! %d ", (int)ans.size());
	for (int x : ans)
		printf("%d ", x);
	printf("\n");
	fflush(stdout);
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