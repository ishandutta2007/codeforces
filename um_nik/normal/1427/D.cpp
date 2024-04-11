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

const int N = 55;
int n;
int a[N];
vector<vector<int>> ans;

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		a[i]--;
	}
	for (int x = 0; x < n - (n & 1); x++) {
		int p = 0;
		while(a[p] != x) p++;
		assert(x <= p);
		p++;
		vector<int> cur;
		for (int i = 0; i < x; i++)
			cur.push_back(1);
		cur.push_back(p - x);
		for (int i = p; i < n; i++)
			cur.push_back(1);
		if (x & 1) reverse(all(cur));
		if ((int)cur.size() > 1) ans.push_back(cur);
		reverse(a + x, a + p);
	}
	printf("%d\n", (int)ans.size());
	for (int i = 0; i < (int)ans.size(); i++) {
		printf("%d", (int)ans[i].size());
		for (int x : ans[i])
			printf(" %d", x);
		printf("\n");
	}

	return 0;
}