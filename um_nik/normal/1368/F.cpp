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

const int N = 1010;
int a[N];

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);
	int bst = n;
	int k = 1;
	for (int i = 1; i <= n; i++) {
		int cur = (n - 1) / i + i;
		if (cur < bst) {
			bst = cur;
			k = i;
		}
	}
	//printf("k = %d\n", k);
	//fflush(stdout);
	vector<int> want;
	for (int i = 1; i <= n; i++) {
		if (i % k != 0) want.push_back(i);
	}
	if (!want.empty() && want.back() == n) want.pop_back();

	while((int)want.size() >= k) {
		printf("%d", k);
		for (int i = 0; i < k; i++) {
			int x = want.back();
			want.pop_back();
			a[x] = 1;
			printf(" %d", x);
		}
		printf("\n");
		fflush(stdout);
		int z;
		scanf("%d", &z);
		assert(z != -1);
		for (int i = 0; i < k; i++) {
			if (a[z]) {
				want.push_back(z);
				a[z] = 0;
			}
			z++;
			if (z > n) z -= n;
		}
	}
	printf("0\n");
	fflush(stdout);

	return 0;
}