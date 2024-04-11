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
int n, m, k;
int ans[N];
int ed[N][2];
vector<int> g[N];
bool a[N];
int cnt;
set<pii> setik;
int deg[N];

void eraseOne(int v, int u) {
	if (!a[v] || !a[u]) return;
	setik.erase(mp(deg[v], v));
	deg[v]--;
	setik.insert(mp(deg[v], v));
}
void eraseEdge(int v, int u) {
	eraseOne(v, u);
	eraseOne(u, v);
}

void solve(int T) {
	while(!setik.empty()) {
		int v = setik.begin()->second;
		if (deg[v] >= k) return;
		for (int id : g[v]) {
			if (id >= T) continue;
			eraseEdge(ed[id][0], ed[id][1]);
		}
		a[v] = false;
		setik.erase(mp(deg[v], v));
		cnt--;
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 2; j++) {
			scanf("%d", &ed[i][j]);
			ed[i][j]--;
			g[ed[i][j]].push_back(i);
			deg[ed[i][j]]++;
		}
	}
	cnt = n;
	for (int i = 0; i < n; i++) {
		a[i] = true;
		setik.insert(mp(deg[i], i));
	}
	for (int i = m - 1; i >= 0; i--) {
		solve(i + 1);
		ans[i] = cnt;
		eraseEdge(ed[i][0], ed[i][1]);
	}
	for (int i = 0; i < m; i++)
		printf("%d\n", ans[i]);

	return 0;
}