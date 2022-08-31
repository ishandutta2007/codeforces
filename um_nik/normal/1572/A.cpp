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
int n;
int deg[N];
vector<int> g[N];
set<int> setik;

void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		deg[i] = 0;
		g[i].clear();
	}
	setik.clear();
	for (int i = 0; i < n; i++) {
		scanf("%d", &deg[i]);
		for (int j = 0; j < deg[i]; j++) {
			int v;
			scanf("%d", &v);
			v--;
			g[v].push_back(i);
		}
		if (deg[i] == 0) setik.insert(i);
	}
	int lft = n;
	int ans = 0;
	int v = n + 1;
	while(!setik.empty()) {
		auto it = setik.lower_bound(v);
		if (it == setik.end()) {
			ans++;
			v = *setik.begin();
		} else {
			v = *it;
		}
		lft--;
		setik.erase(v);
		for (int u : g[v]) {
			deg[u]--;
			if (deg[u] == 0) setik.insert(u);
		}
	}
	if (lft > 0) {
		printf("-1\n");
	} else {
		printf("%d\n", ans);
	}
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