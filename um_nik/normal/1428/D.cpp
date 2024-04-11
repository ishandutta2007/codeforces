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
int n;
int a[N];
int b[N];
vector<pii> ans;

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int X = n + 1;
	vector<int> ones;
	int lst23 = n + 1;
	for (int i = n; i > 0; i--) {
		if (a[i] == 0) continue;
		if (X == n + 1 && a[i] > 1) {
			printf("-1\n");
			return 0;
		}
		if (a[i] == 1) {
			X--;
			ans.push_back(mp(X, i));
			b[i] = X;
			ones.push_back(i);
		} else if (a[i] == 2) {
			if (ones.empty()) {
				printf("-1\n");
				return 0;
			}
			int v = ones.back();
			ones.pop_back();
			b[i] = b[v];
			ans.push_back(mp(b[i], i));
			lst23 = i;
		} else if (a[i] == 3) {
			X--;
			int v = n + 1;
			if (lst23 != n + 1) {
				v = lst23;
			} else if (!ones.empty()) {
				v = ones.back();
				ones.pop_back();
			} else {
				printf("-1\n");
				return 0;
			}
			ans.push_back(mp(X, v));
			ans.push_back(mp(X, i));
			b[i] = X;
			lst23 = i;
		} else throw;
		assert(X >= 1);
	}
	printf("%d\n", (int)ans.size());
	for (pii t : ans)
		printf("%d %d\n", t.first, t.second);

	return 0;
}