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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int N = 200200;
int n;
int g[N];
int c[N];
int deg[N];
int q[N];
int topQ;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &c[i]);
	for (int i = 0; i < n; i++) {
		scanf("%d", &g[i]);
		g[i]--;
		deg[g[i]]++;
	}
	for (int v = 0; v < n; v++)
		if (deg[v] == 0)
			q[topQ++] = v;
	for (int i = 0; i < topQ; i++) {
		int v = q[i];
		deg[g[v]]--;
		if (deg[g[v]] == 0)
			q[topQ++] = g[v];
	}
	int ans = 0;
	for (int v = 0; v < n; v++) {
		if (deg[v] == 0) continue;
		int u = v;
		int cur = (int)1e9;
		while(deg[u] != 0) {
			deg[u] = 0;
			cur = min(cur, c[u]);
			u = g[u];
		}
		ans += cur;
	}
	printf("%d\n", ans);

	return 0;
}