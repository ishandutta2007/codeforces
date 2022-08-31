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

const int N = 2020;
int n;
int a[N];
int b[N];
vector<pii> ans;

void query(int v) {
	printf("? %d\n", v);
	fflush(stdout);
	for (int i = 1; i <= n; i++)
		scanf("%d", &b[i]);
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	query(1);
	int even = 0;
	for (int i = 1; i <= n; i++) {
		a[i] = b[i];
		if (a[i] % 2 == 0) even++;
	}
	if (2 * even <= n + 1) {
		for (int i = 1; i <= n; i++)
			if (a[i] == 1)
				ans.push_back(mp(1, i));
		for (int v = 2; v <= n; v++) {
			if (a[v] & 1) continue;
			query(v);
			for (int i = 1; i <= n; i++)
				if (b[i] == 1)
					ans.push_back(mp(v, i));
		}
	} else {
		for (int v = 2; v <= n; v++) {
			if (a[v] % 2 == 0) continue;
			query(v);
			for (int i = 1; i <= n; i++)
				if (b[i] == 1)
					ans.push_back(mp(v, i));
		}
	}
	assert((int)ans.size() == n - 1);
	printf("!\n");
	for (pii t : ans)
		printf("%d %d\n", t.first, t.second);
	fflush(stdout);

	return 0;
}