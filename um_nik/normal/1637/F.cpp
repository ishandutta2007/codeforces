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

const int N = 200200;
vector<int> g[N];
int a[N];
pii ord[N];
int m;
int n;
int deg[N];
bool on[N];

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i < n; i++) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	for (int i = 0; i < n; i++)
		ord[i] = mp(a[i], i);
	sort(ord, ord + n);
	for (int i = 0; i < n; i++) {
		deg[i] = (int)g[i].size();
		on[i] = true;
	}
	ll ans = ord[n - 1].first * 2;
	for (int i = 0; i < n - 1; i++) {
		int v = ord[i].second;
		on[v] = 0;
		if (deg[v] > 1) continue;
		while(deg[v] == 1 && !on[v]) {
			int p = 0;
			while(deg[g[v][p]] == -1) p++;
			deg[v] = -1;
			v = g[v][p];
			deg[v]--;
		}
		if (deg[v] >= 2)
			ans += ord[i].first;
	}
	printf("%lld\n", ans);

	return 0;
}