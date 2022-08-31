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

const int N = (int)2e6 + 7;
int m, n;
int sz[N];
int a[N];
vector<int> b[N];
int par[N];
bool good[N];
int cur[N];
vector<pii> q;
vector<vector<int>> ans;
int ID;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
		scanf("%d", &a[i]);
	sz[0] = n;
	good[0] = 1;
	par[0] = -1;
	ID = 1;
	q.push_back(mp(0, 0));
	int pos = 0;
	for (int i = 0; pos < m; i++) {
		int v = q[i].first, t = q[i].second;
		if (a[pos] > sz[v]) {
			a[pos] -= sz[v];
			b[v].push_back(pos);
			q.push_back(mp(v, t + 1));
			continue;
		}
		if (pos == m - 1) {
			b[v].push_back(pos);
			break;
		}
		int x = a[pos];
		sz[ID] = x;
		sz[ID + 1] = sz[v] - x;
		good[ID] = good[ID + 1] = 1;
		good[v] = 0;
		par[ID] = par[ID + 1] = v;
		b[ID].push_back(pos);
		q.push_back(mp(ID, t + 1));
		q[i].first = ID + 1;
		ID += 2;
		i--;
		pos++;
	}
	/*
	for (int i = 0; i < ID; i++) {
		printf("%d %d\n", par[i], sz[i]);
	}
	*/
	for (int i = 0; i < ID; i++)
		reverse(b[i].begin(), b[i].end());
	int k = 0;
	for (int i = 0; i < ID; i++) {
		if (good[i])
			cur[k++] = i;
	}
	for (int i = 1; i < ID; i++) {
		int v = par[i];
		if (b[v].empty())
			par[i] = par[v];
	}
	while(k < m) cur[k++] = ID++;
	ans.resize(m);
	for (int i = 0; i < m; i++) {
		int v = cur[i];
		if (sz[v] == 0) continue;
		int u = v;
		while(u != -1) {
			for (int x : b[u])
				ans[i].push_back(x);
			u = par[u];
		}
		reverse(ans[i].begin(), ans[i].end());
	}
	int T = 0;
	for (int i = 0; i < m; i++)
		T = max(T, (int)ans[i].size());
	printf("%d\n", T);
	for (int i = 0; i < m; i++)
		printf("%d ", sz[cur[i]]);
	printf("\n");
	for (int t = 0; t < T; t++) {
		for (int i = 0; i < m; i++) {
			if (t < (int)ans[i].size())
				printf("%d ", ans[i][t] + 1);
			else
				printf("1 ");
		}
		printf("\n");
	}

	return 0;
}