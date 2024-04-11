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
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__);fflush(stderr);
#else
	#define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

const int N = 1005;
int a[N][N];
int n;
bool used[N];
int c[N];
int ed[N][2];
int edSz;

void addEdge(int v, int u) {
	ed[edSz][0] = v;
	ed[edSz][1] = u;
	edSz++;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	for (int i = 0; i < n; i++)
		c[i] = a[i][i];
	while(true) {
		vector<int> all;
		for (int i = 0; i < n; i++)
			if (!used[i])
				all.push_back(i);
		int m = (int)all.size();
		if (m == 1) break;
		int V = -1, BST = (int)1e9 + 7;
		for (int i = 0; i < m; i++)
			for (int j = i + 1; j < m; j++) {
				if (a[all[i]][all[j]] < BST) {
					BST = a[all[i]][all[j]];
					V = all[i];
				}
			}
		c[n] = BST;
		addEdge(V, n);
		used[V] = 1;
		for (int v : all) {
			a[v][n] = a[n][v] = a[v][V];
			if (a[V][v] == BST) {
				addEdge(v, n);
				used[v] = 1;
			}
		}
		n++;
	}
	printf("%d\n", n);
	for (int i = 0; i < n; i++)
		printf("%d ", c[i]);
	printf("\n");
	for (int i = 0; i < n; i++)
		if (!used[i])
			printf("%d\n", i + 1);
	assert(edSz == n - 1);
	for (int i = 0; i < edSz; i++)
		printf("%d %d\n", ed[i][0] + 1, ed[i][1] + 1);

	return 0;
}