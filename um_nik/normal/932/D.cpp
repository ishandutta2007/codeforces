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

const int LOG = 19;
const int N = 400400;
int n;
ll w[N];
ll par[N][LOG][2];

int getPar(int v, ll X) {
	if (w[v] >= X) return v;
	for (int k = LOG - 1; k >= 0; k--) {
		if (par[v][k][0] <= 0) continue;
		if (w[par[v][k][0]] < X)
			v = par[v][k][0];
	}
	return par[v][0][0];
}

void makeEdge(int v, int u) {
	par[v][0][0] = u;
	par[v][0][1] = w[v];
	for (int k = 0; k < LOG - 1; k++) {
		u = par[v][k][0];
		if (u == -1) continue;
		par[v][k + 1][0] = par[u][k][0];
		par[v][k + 1][1] = par[v][k][1] + par[u][k][1];
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	n = 2;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < LOG; j++)
			par[i][j][0] = -1;
	par[1][0][0] = 0;

	int q;
	scanf("%d", &q);
	ll ans = 0;
	while(q--) {
		int t;
		ll R, X;
		scanf("%d%lld%lld", &t, &R, &X);
		R ^= ans;
		X ^= ans;
		if (t == 1) {
			w[n] = X;
			makeEdge(n, getPar(R, X));
			n++;
		} else {
			int v = R;
			ans = 0;
			for (int k = LOG - 1; k >= 0; k--) {
				if (par[v][k][0] == -1) continue;
				if (par[v][k][1] > X) continue;
				X -= par[v][k][1];
				ans += 1 << k;
				v = par[v][k][0];
			}
			printf("%lld\n", ans);
		}
	}

	return 0;
}