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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

double startTime;
double getCurrentTime() {
	return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}

const int N = 1010;
int n;
vector<int> g[N];
bool bad[N];

bool find(int v, int p, int V, int U) {
	if (v == V || v == U) return true;
	for (int u : g[v]) {
		if (u == p) continue;
		if (find(u, v, V, U)) return true;
	}
	return false;
}
void markBad(int v, int p) {
	bad[v] = true;
	for (int u : g[v])
		if (u != p)
			markBad(u, v);
}

int main()
{
	startTime = (double)clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int v, u;
		scanf("%d%d", &v, &u);
		g[v].push_back(u);
		g[u].push_back(v);
	}
	while(true) {
		int V = -1, U = -1;
		for (int v = 1; v <= n; v++) {
			if (bad[v]) continue;
			int d = 0;
			for (int u : g[v])
				if (!bad[u])
					d++;
			if (d == 0) {
				printf("! %d\n", v);
				fflush(stdout);
				return 0;
			}
			if (d != 1) continue;
			if (V == -1) {
				V = v;
			} else if (U == -1) {
				U = v;
			}
		}
		if (U == -1) throw;
		printf("? %d %d\n", V, U);
		fflush(stdout);
		int Z;
		scanf("%d", &Z);
		if (V == Z || U == Z) {
			printf("! %d\n", Z);
			fflush(stdout);
			return 0;
		}
		for (int v : g[Z]) {
			if (find(v, Z, V, U)) markBad(v, Z);
		}
	}

	return 0;
}