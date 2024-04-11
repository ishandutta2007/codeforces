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

const int N = 200100;
int n, q;
int a[N];
int cnt[N];

bool solve() {
	if (cnt[8] > 0) return true;
	if (cnt[4] >= 2) return true;
	if (cnt[6] > 0 && cnt[2] >= 2) return true;
	if (cnt[4] > 0 && cnt[2] >= 3) return true;
	return false;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		a[x]++;
		cnt[a[x]]++;
	}
	scanf("%d", &q);
	while(q--) {
		char t;
		int x;
		scanf(" %c %d", &t, &x);
		if (t == '+') {
			a[x]++;
			cnt[a[x]]++;
		} else {
			assert(a[x] > 0);
			cnt[a[x]]--;
			a[x]--;
		}
		if (solve())
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}