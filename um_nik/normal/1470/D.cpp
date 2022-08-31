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

const int N = 300300;
vector<int> g[N];
int n, m;
bool a[N];
bool used[N];
int q[N];
int topQ;

void solve() {
	scanf("%d%d", &n, &m);
	for (int v = 0; v < n; v++) {
		a[v] = 0;
		used[v] = 0;
		g[v].clear();
	}
	topQ = 0;
	for (int i = 0; i < m; i++) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	q[topQ++] = 0;
	used[0] = 1;
	for (int i = 0; i < topQ; i++) {
		int v = q[i];
		bool ok = true;
		for (int u : g[v])
			ok &= !a[u];
		a[v] = ok;
		for (int u : g[v]) {
			if (used[u]) continue;
			used[u] = 1;
			q[topQ++] = u;
		}
	}
	if (topQ != n) {
		printf("NO\n");
		return;
	}
	printf("YES\n");
	int cnt = 0;
	for (int i = 0; i < n; i++)
		cnt += (int)a[i];
	printf("%d\n", cnt);
	for (int i = 0; i < n; i++)
		if (a[i])
			printf("%d ", i + 1);
	printf("\n");
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