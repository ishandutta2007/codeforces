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

const int INF = (int)1e7;
const int N = 100010;
const int K = 302;
vector<int> g[N];
vector<int> forCol[K];
int q[N];
int topQ;
int dist[N];
int ans[N][K];
int n, m, k, s;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d%d%d", &n, &m, &k, &s);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		x--;
		forCol[x].push_back(i);
	}
	while(m--) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	for (int c = 0; c < k; c++) {
		for (int i = 0; i < n; i++)
			dist[i] = INF;
		topQ = 0;
		for (int x : forCol[c]) {
			dist[x] = 0;
			q[topQ++] = x;
		}
		for (int i = 0; i < topQ; i++) {
			int v = q[i];
			for (int u : g[v]) {
				if (dist[u] <= dist[v] + 1) continue;
				dist[u] = dist[v] + 1;
				q[topQ++] = u;
			}
		}
		for (int i = 0; i < n; i++)
			ans[i][c] = dist[i];
	}
	for (int i = 0; i < n; i++) {
		nth_element(ans[i], ans[i] + s, ans[i] + k);
		int res = 0;
		for (int j = 0; j < s; j++)
			res += ans[i][j];
		printf("%d ", res);
	}
	printf("\n");

	return 0;
}