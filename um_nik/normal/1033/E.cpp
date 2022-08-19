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

int CNT = 0;

int query(vector<int> q) {
	if ((int)q.size() <= 1) return 0;
	if (CNT == 20000) throw;
	CNT++;
	printf("? %d\n", (int)q.size());
	for (int v : q)
		printf("%d ", v + 1);
	printf("\n");
	fflush(stdout);
	int x;
	scanf("%d", &x);
	return x;
}
bool hasEdgesFromV(int v, vector<int> q) {
//	cerr << "hasEdges" << endl;
	int x = query(q);
	q.push_back(v);
	return query(q) > x;
}
int findNeighbour(int v, vector<int> a) {
//	cerr << "findNeigh" << endl;
	while((int)a.size() > 1) {
		vector<int> q = vector<int>();
		while((int)q.size() < (int)a.size()) {
			q.push_back(a.back());
			a.pop_back();
		}
		if (!hasEdgesFromV(v, a))
			a = q;
	}
	return a[0];
}

const int N = 606;
int col[N];
int par[N];
int n;

void dfs(int v) {
	while(true) {
		vector<int> notUsed;
		for (int u = 0; u < n; u++)
			if (col[u] == -1)
				notUsed.push_back(u);
		if (!hasEdgesFromV(v, notUsed)) break;
		int u = findNeighbour(v, notUsed);
		par[u] = v;
		col[u] = col[v] ^ 1;
		dfs(u);
	}
}

void printEdge(int v, int u) {
	vector<int> p1, p2;
	while(v != -1) {
		p1.push_back(v);
		v = par[v];
	}
	while(u != -1) {
		p2.push_back(u);
		u = par[u];
	}
	while((int)p1.size() >= 2 && (int)p2.size() >= 2 &&
			p1[(int)p1.size() - 2] == p2[(int)p2.size() - 2]) {
		p1.pop_back();
		p2.pop_back();
	}
	p2.pop_back();
	printf("N %d\n", (int)p1.size() + (int)p2.size());
	for (int i = 0; i < (int)p1.size(); i++)
		printf("%d ", p1[i] + 1);
	for (int i = (int)p2.size() - 1; i >= 0; i--)
		printf("%d ", p2[i] + 1);
	printf("\n");
	fflush(stdout);
}

void findContradiction(vector<int> a) {
	while(true) {
		int v = a.back();
		a.pop_back();
		if (!hasEdgesFromV(v, a)) continue;
		int u = findNeighbour(v, a);
		printEdge(v, u);
		return;
	}
	throw;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		col[i] = -1;
	par[0] = -1;
	col[0] = 0;
	dfs(0);

	vector<int> c[2];
	c[0].clear();
	c[1].clear();
	for (int v = 0; v < n; v++) {
		if (col[v] == -1) throw;
		c[col[v]].push_back(v);
	}
	for (int k = 0; k < 2; k++) {
		if (query(c[k]) == 0) continue;
		findContradiction(c[k]);
		return 0;
	}
	printf("Y %d\n", (int)c[0].size());
	for (int v : c[0])
		printf("%d ", v + 1);
	printf("\n");
	fflush(stdout);

	return 0;
}