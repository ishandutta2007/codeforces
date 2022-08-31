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
ll a[N];
int n;
int par[N];
int deg[N];
vector<int> q;
vector<int> ord1, ord2;
ll ans = 0;

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	for (int i = 0; i < n; i++) {
		scanf("%d", &par[i]);
		if (par[i] != -1) {
			par[i]--;
			deg[par[i]]++;
		}
	}
	for (int v = 0; v < n; v++)
		if (deg[v] == 0)
			q.push_back(v);
	while(!q.empty()) {
		int v = q.back();
		q.pop_back();
		ans += a[v];
		if (a[v] > 0) {
			ord1.push_back(v);
			if (par[v] != -1) {
				a[par[v]] += a[v];
			}
		} else {
			ord2.push_back(v);
		}
		if (par[v] != -1) {
			deg[par[v]]--;
			if (deg[par[v]] == 0)
				q.push_back(par[v]);
		}
	}
	while(!ord2.empty()) {
		ord1.push_back(ord2.back());
		ord2.pop_back();
	}
	printf("%lld\n", ans);
	for (int x : ord1)
		printf("%d ", x + 1);
	printf("\n");

	return 0;
}