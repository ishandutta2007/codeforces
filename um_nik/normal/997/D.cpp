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

const int MOD = 998244353;
int add(int x, int y) {
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
int sub(int x, int y) {
	x -= y;
	if (x < 0) return x + MOD;
	return x;
}
int mult(int x, int y) {
	return ((ll)x * y) % MOD;
}

const int N = 4020;
const int K = 80;
int C[K][K];
int ans[K];
int ans2[K];
int n, nnn, m;
vector<int> g[N];
vector<int> rev[N];
vector<bool> used[N];
int q[2 * N];
int topQ;
int deg[N];
vector< vector< int > > dp[N];
int inner[K];
int forInner[K];
int sumV[K];

void read() {
	for (int i = 0; i <= m; i++)
		ans[i] = 0;
	for (int i = 0; i < n; i++) {
		g[i].clear();
		rev[i].clear();
		used[i].clear();
		deg[i] = 0;
		dp[i].clear();
	}
	topQ = 0;
	for (int i = 1; i < n; i++) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		rev[v].push_back((int)g[u].size());
		rev[u].push_back((int)g[v].size());
		g[v].push_back(u);
		g[u].push_back(v);
	}
	for (int v = 0; v < n; v++) {
		used[v].resize(g[v].size());
		for (int i = 0; i < (int)used[v].size(); i++)
			used[v][i] = false;
		dp[v].resize(g[v].size());
		for (int i = 0; i < (int)g[v].size(); i++) {
			dp[v][i].resize(m + 1);
			for (int j = 0; j <= m; j++)
				dp[v][i][j] = 0;
		}
		deg[v] = (int)g[v].size();
		if (deg[v] <= 1) q[topQ++] = v;
	}
}

void setUsed(int v, int id) {
	used[v][id] = 1;
	int u = g[v][id];
	deg[u]--;
	if (deg[u] <= 1) q[topQ++] = u;
}

void calcInner() {
	for (int i = 0; i <= m; i++)
		inner[i] = 0;
	inner[0] = 1;
	for (int i = 0; i < m; i++)
		for (int j = 1; i + j <= m; j++)
			inner[i + j] = add(inner[i + j], mult(inner[i], forInner[j]));
}

void solve(int v) {
	if (deg[v] == 0) {

		for (int i = 0; i <= m; i++)
			sumV[i] = 0;
		for (int i = 0; i < (int)g[v].size(); i++) {
			int u = g[v][i];
			int id = rev[v][i];
			for (int j = 0; j <= m; j++)
				sumV[j] = add(sumV[j], dp[u][id][j]);
		}
		for (int i = 0; i < (int)g[v].size(); i++) {
			if (used[v][i]) continue;
			setUsed(v, i);
			int u = g[v][i];
			int id = rev[v][i];
			for (int j = 0; j <= m; j++)
				forInner[j] = 0;
			for (int j = 0; j < m; j++)
				forInner[j + 1] = sub(sumV[j], dp[u][id][j]);
			calcInner();
			for (int j = 0; j <= m; j++)
				dp[v][i][j] = inner[j];
		}

	} else {

		for (int i = 0; i <= m; i++)
			sumV[i] = 0;
		for (int i = 0; i < (int)g[v].size(); i++) {
			int u = g[v][i];
			int id = rev[v][i];
			if (!used[u][id]) continue;
			for (int j = 0; j <= m; j++)
				sumV[j] = add(sumV[j], dp[u][id][j]);
		}
		for (int i = 0; i < (int)g[v].size(); i++) {
			int u = g[v][i];
			int id = rev[v][i];
			if (used[u][id]) continue;
			setUsed(v, i);
			for (int j = 0; j <= m; j++)
				forInner[j] = 0;
			for (int j = 0; j < m; j++)
				forInner[j + 1] = sub(sumV[j], dp[u][id][j]);
			calcInner();
			for (int j = 0; j <= m; j++)
				dp[v][i][j] = inner[j];
		}

	}
}

void solve() {
	read();
	for (int it = 0; it < topQ; it++) {
		solve(q[it]);
	}
	for (int v = 0; v < n; v++) {
		for (int i = 0; i <= m; i++)
			forInner[i] = 0;
		for (int i = 0; i < (int)g[v].size(); i++) {
			int u = g[v][i];
			int id = rev[v][i];
			for (int j = 0; j < m; j++)
				forInner[j + 1] = add(forInner[j + 1], dp[u][id][j]);
		}
		calcInner();
		for (int i = 0; i <= m; i++)
			ans[i] = add(ans[i], inner[i]);
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int i = 0; i < K; i++)
		C[i][0] = C[i][i] = 1;
	for (int i = 0; i < K; i++)
		for (int j = 1; j < i; j++)
			C[i][j] = add(C[i - 1][j], C[i - 1][j - 1]);

	scanf("%d%d%d", &n, &nnn, &m);
	if (m & 1) {
		printf("0\n");
		return 0;
	}
	m /= 2;

	solve();

	for (int i = 0; i <= m; i++)
		ans2[i] = ans[i];

	n = nnn;
	solve();

	int ANS = 0;
	for (int i = 0; i <= m; i++) {
		ANS = add(ANS, mult(C[2 * m][2 * i], mult(ans[i], ans2[m - i])));
	}
	printf("%d\n", ANS);

	return 0;
}