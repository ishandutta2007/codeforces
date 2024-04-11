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
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 200200;
vector<int> g[N];
int col[N];
int a[N][2];
ll b[2][N];
map<pii, ll> mapchik;
ll ans;
ll sgn;
ll sz;
int n, m;
int C;

void dfs(int v) {
	col[v] = C;
	sz++;
	for (int u : g[v]) {
		if (col[u] == -1) dfs(u);
	}
}

void solve() {
	int A, B;
	scanf("%d%d%d%d", &n, &m, &A, &B);
	A--;B--;
	for (int i = 0; i < n; i++)
		g[i].clear();
	for (int i = 0; i < m; i++) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	for (int i = 0; i <= n; i++)
		b[0][i] = b[1][i] = 0;
	mapchik.clear();

	for (int i = 0; i < n; i++)
		col[i] = -1;
	C = 0;
	col[A] = C++;
	for (int i = 0; i < n; i++) {
		if (col[i] != -1) continue;
		dfs(i);
		C++;
	}
	for (int i = 0; i < n; i++)
		a[i][0] = col[i];
	
	for (int i = 0; i < n; i++)
		col[i] = -1;
	C = 0;
	col[B] = C++;
	for (int i = 0; i < n; i++) {
		if (col[i] != -1) continue;
		dfs(i);
		C++;
	}
	for (int i = 0; i < n; i++)
		a[i][1] = col[i];

//	for (int i = 0; i < n; i++)
//		printf("%d %d\n", a[i][0], a[i][1]);

	for (int i = 0; i < n; i++) {
		if (i == A || i == B) continue;
		b[0][a[i][0]]++;
		b[1][a[i][1]]++;
		mapchik[mp(a[i][0], a[i][1])]++;
	}
	ans = 0;
	for (int i = 0; i < n; i++) {
		if (i == A || i == B) continue;
		ans += n - 2 - b[0][a[i][0]] - b[1][a[i][1]] + mapchik[mp(a[i][0], a[i][1])];
	}
	printf("%lld\n", ans / 2);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0;
}