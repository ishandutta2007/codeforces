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

const int B = 400;
//const int B = 2;
const int N = 100100;
vector<int> g[N];
vector<int> toBig[N];
bool isBig[N];
double sumForBig[N];
double p[N];
double ANS;
int n;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lf", &p[i]);
		p[i] = 1 - p[i];
	}
	for (int i = 1; i < n; i++) {
		int v, u;
		scanf("%d%d", &v, &u);
		g[v].push_back(u);
		g[u].push_back(v);
	}
	for (int v = 0; v < n; v++)
		isBig[v] = (int)g[v].size() > B;
	for (int v = 0; v < n; v++)
		for (int u : g[v])
			if (isBig[u])
				toBig[v].push_back(u);
	for (int v = 0; v < n; v++) {
		ANS += p[v];
		for (int u : g[v])
			if (u > v)
				ANS -= p[v] * p[u];
		if (!isBig[v]) continue;
		for (int u : g[v])
			sumForBig[v] += p[u];
	}
	int q;
	scanf("%d", &q);
	while(q--) {
		int v;
		double x;
		scanf("%d%lf", &v, &x);
		x = 1 - x;
		ANS -= p[v];
		ANS += x;
		if (isBig[v])
			ANS -= (x - p[v]) * sumForBig[v];
		else {
			for (int u : g[v])
				ANS -= (x - p[v]) * p[u];
		}
		for (int u : toBig[v])
			sumForBig[u] += x - p[v];
		p[v] = x;
		printf("%.12lf\n", ANS);
	}

	return 0;
}