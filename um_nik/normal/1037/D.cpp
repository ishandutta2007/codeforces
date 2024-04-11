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
#include <queue>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 200200;
int n;
vector<pii> g[N];
int a[N];
int ord[N];
int q[N];
int topQ;
bool used[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int v, u;
		scanf("%d%d", &v, &u);
		g[v].push_back(mp(0, u));
		g[u].push_back(mp(0, v));
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		ord[a[i]] = i;
	}
	for (int v = 1; v <= n; v++) {
		for (int i = 0; i < (int)g[v].size(); i++) {
			g[v][i].first = ord[g[v][i].second];
		}
		sort(g[v].begin(), g[v].end());
	}
	q[topQ++] = 1;
	used[1] = true;
	for (int i = 0; i < topQ; i++) {
		int v = q[i];
		for (pii e : g[v]) {
			int u = e.second;
			if (used[u]) continue;
			q[topQ++] = u;
			used[u] = 1;
		}
	}
	for (int i = 0; i < n; i++)
		if (a[i] != q[i]) {
			printf("No\n");
			return 0;
		}
	printf("Yes\n");

	return 0;
}