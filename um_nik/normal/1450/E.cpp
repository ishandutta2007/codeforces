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

const int N = 222;
int n, m;
vector<pii> g[N];
int a[N];
int q[N * N];
int topQ;
bool inQ[N];
int ANS[N];
int BST = -1;

bool dfs(int v) {
	for (pii e : g[v]) {
		int u = e.first;
		int w = a[v];
		if (e.second >= 0)
			w++;
		else
			w--;
		if (a[u] == 0) {
			a[u] = w;
			if (!dfs(u)) return false;
		} else if (a[u] % 2 != w % 2)
			return false;
	}
	return true;
}

void solve(int v) {
	for (int i = 0; i < n; i++)
		a[i] = 0;
	a[v] = N;
	if (!dfs(v)) return;
	topQ = 0;
	for (int v = 0; v < n; v++) {
		inQ[v] = 1;
		q[topQ++] = v;
	}
	for (int i = 0; i < topQ; i++) {
		v = q[i];
		if (a[v] < N) return;
		inQ[v] = false;
		for (pii e : g[v]) {
			int u = e.first;
			int w = a[v];
			if (e.second >= 0)
				w++;
			else
				w--;
			if (a[u] <= w) continue;
			a[u] = w;
			if (!inQ[u]) {
				inQ[u] = 1;
				q[topQ++] = u;
			}
		}
	}
	int res = N;
	for (int i = 0; i < n; i++) {
		assert(a[i] >= N);
		res = max(res, a[i]);
	}
	res -= N;
	if (res > BST) {
		BST = res;
		for (int i = 0; i < n; i++)
			ANS[i] = a[i];
	}
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	while(m--) {
		int v, u, t;
		scanf("%d%d%d", &v, &u, &t);
		v--;u--;
		g[v].push_back(mp(u, t));
		g[u].push_back(mp(v, -t));
	}
	for (int i = 0; i < n; i++)
		solve(i);
	if (BST == -1) {
		printf("NO\n");
	} else {
		printf("YES\n");
		printf("%d\n", BST);
		for (int i = 0; i < n; i++)
			printf("%d ", ANS[i]);
		printf("\n");
	}

	return 0;
}