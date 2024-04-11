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

const int N = 1010;
const int M = (1 << 18) + 5;
int U[M];
int ans[5555][3];
int ansSz;
int n, s;
int nim[N];
vector<int> W;
vector<int> g[N];
char sss[111];

void addAns(int x, int y, int z) {
	ans[ansSz][0] = x;
	ans[ansSz][1] = y;
	ans[ansSz][2] = z;
	ansSz++;
}

void solve() {
	int mask = 0;
	int ans = -1;
	for (int i = 0; i < s; i++) {
		printf("? 1 %d\n", W[i]);
		fflush(stdout);
		scanf("%s", sss);
		if (sss[0] == 'W') {
			mask ^= 1 << i;
		} else if (sss[0] == 'L') {
			ans = W[i];
		} else if (sss[0] == 'D') {

		} else if (sss[0] == 'S') {
			throw;
		} else throw;
	}
	if (ans == -1) {
		assert(U[mask] != 0);
		ans = U[mask];
	}
	printf("! %d\n", ans);
	fflush(stdout);
	scanf("%s", sss);
	if (sss[0] == 'C') return;
	exit(0);
}

int findBestMask(int mask) {
	vector<int> Q;
	Q.push_back(mask);
	for (int i = 0; i < (int)Q.size(); i++) {
		int v = Q[i];
		if (U[v] == 0) return v;
		for (int j = 0; j < s; j++) {
			int u = v ^ (1 << j);
			Q.push_back(u);
		}
	}
	throw;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int m, t;
	scanf("%d%d%d", &n, &m, &t);
	while(m--) {
		int v, u;
		scanf("%d%d", &v, &u);
		g[v].push_back(u);
	}
	s = min(18, n);
	vector<pii> ord;
	for (int v = 1; v <= n; v++)
		ord.push_back(mp((int)g[v].size(), v));
	sort(all(ord));
	W.resize(n);
	for (int v = 1; v <= n; v++)
		nim[v] = -1;
	for (int i = 0; i < s; i++) {
		int v = ord[i].second;
		W[i] = v;
		nim[v] = i;
		for (int u : g[v]) {
			addAns(-1, v, u);
		}
		g[v].clear();
	}
	for (int i = 0; i < s; i++)
		for (int j = i + 1; j < s; j++)
			addAns(1, W[j], W[i]);
	for (int v = 1; v <= n; v++) {
		if (nim[v] != -1) continue;
		addAns(1, v, v);
		int mask = 0;
		for (int u : g[v]) {
			if (nim[u] != -1)
				mask |= 1 << nim[u];
		}
		int nmask = findBestMask(mask);
		U[nmask] = v;
		for (int i = 0; i < s; i++) {
			if (((mask ^ nmask) >> i) & 1) {
				if ((mask >> i) & 1) {
					addAns(-1, v, W[i]);
				} else {
					addAns(1, v, W[i]);
				}
			}
		}
	}

	printf("%d\n", ansSz);
	for (int i = 0; i < ansSz; i++) {
		if (ans[i][0] == -1)
			printf("-");
		else
			printf("+");
		printf(" %d %d\n", ans[i][1], ans[i][2]);
	}
	fflush(stdout);

	while(t--) solve();

	return 0;
}