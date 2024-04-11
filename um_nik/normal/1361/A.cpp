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

const int N = 500500;
int n, m;
vector<int> g[N];
int c[N];
pii ord[N];
bool used[N];

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	//return 0;
	scanf("%d%d", &n, &m);
	while(m--) {
		int v, u;
		scanf("%d%d", &v, &u);
		//eprintf("%d %d\n", v, u);
		v--;u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &ord[i].first);
		c[i] = ord[i].first;
		ord[i].second = i;
	}
	sort(ord, ord + n);
	for (int i = 0; i < n; i++) {
		int v = ord[i].second;
		//eprintf("v = %d\n", v);
		int k = ord[i].first;
		for (int j = 1; j <= k; j++)
			used[j] = false;
		for (int u : g[v])
			used[c[u]] = 1;
		if (used[k]) {
			printf("-1\n");
			return 0;
		}
		for (int j = 1; j < k; j++)
			if (!used[j]) {
				printf("-1\n");
				return 0;
			}
	}
	for (int i = 0; i < n; i++)
		printf("%d ", ord[i].second + 1);
	printf("\n");

	return 0;
}