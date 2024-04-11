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

const int N = 100100;
int n, m;
vector<int> g[N];
bool used[N];

void printAns(int a, int b) {
	int cur = 3;
	printf("YES\n");
	for (int i = 0; i < n; i++) {
		if (i == a) {
			printf("1 ");
		} else if (i == b) {
			printf("2 ");
		} else
			printf("%d ", cur++);
	}
	printf("\n");
	cur = 3;
	for (int i = 0; i < n; i++) {
		if (i == a) {
			printf("1 ");
		} else if (i == b) {
			printf("1 ");
		} else
			printf("%d ", cur++);
	}
	printf("\n");
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	while(m--) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	for (int i = 0; i < n; i++) {
		if ((int)g[i].size() == n - 1) continue;
		for (int x : g[i])
			used[x] = 1;
		used[i] = 1;
		int p = 0;
		while(used[p]) p++;
		printAns(i, p);
		return 0;
	}
	printf("NO\n");

	return 0;
}