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

const int N = 1100;
int n;
vector<int> g[N];
int ed[N][3];
int ans[10 * N][3];
int ansSz;

void addAns(int v, int u, int x) {
	ans[ansSz][0] = v + 1;
	ans[ansSz][1] = u + 1;
	ans[ansSz][2] = x;
	ansSz++;
}

int getLeaf(int v, int par, int u) {
	if (v == u) return -1;
	if ((int)g[v].size() == 1) return v;
	int res = -2;
	for (int w : g[v]) {
		if (w == par) continue;
		int z = getLeaf(w, v, u);
		if (z == -1) return -1;
		res = z;
	}
	return res;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int v, u, w;
		scanf("%d%d%d", &v, &u, &w);
		v--;u--;
		ed[i][0] = v;
		ed[i][1] = u;
		ed[i][2] = w;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	for (int v = 0; v < n; v++) {
		if ((int)g[v].size() == 2) {
			printf("NO\n");
			return 0;
		}
	}

	for (int i = 1; i < n; i++) {
		int v = ed[i][0], u = ed[i][1], x = ed[i][2] / 2;
		vector<int> vv, uu;
		if ((int)g[v].size() == 1) {
			vv.push_back(v);
		} else {
			for (int w : g[v]) {
				int z = getLeaf(w, v, u);
				if (z != -1)
					vv.push_back(z);
				if ((int)vv.size() == 2) break;
			}
		}
		if ((int)g[u].size() == 1) {
			uu.push_back(u);
		} else {
			for (int w : g[u]) {
				int z = getLeaf(w, u, v);
				if (z != -1)
					uu.push_back(z);
				if ((int)uu.size() == 2) break;
			}
		}
		if ((int)uu.size() == 1) swap(vv, uu);
		if ((int)uu.size() == 1) {
			addAns(vv[0], uu[0], 2 * x);
		} else if ((int)vv.size() == 1) {
			addAns(vv[0], uu[0], x);
			addAns(vv[0], uu[1], x);
			addAns(uu[0], uu[1], -x);
		} else {
			addAns(vv[0], uu[0], x);
			addAns(vv[1], uu[1], x);
			addAns(vv[0], vv[1], -x);
			addAns(uu[0], uu[1], -x);
		}
	}

	printf("YES\n");
	printf("%d\n", ansSz);
	for (int i = 0; i < ansSz; i++)
		printf("%d %d %d\n", ans[i][0], ans[i][1], ans[i][2]);

	return 0;
}