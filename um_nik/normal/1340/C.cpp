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

const int N = 10010;
const int K = 1004;
const int M = 2 * N * K;
int dist[N][K];
pii q[M];
int L, R;
int n, m;
int a[N];
int g, r;

void pushBack(pii t) {
	if (R == M) R = 0;
	q[R++] = t;
}
void pushFront(pii t) {
	if (L == 0) L = M;
	q[--L] = t;
}

int main()
{
	startTime = (double)clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
		scanf("%d", &a[i]);
	sort(a, a + m);
	scanf("%d%d", &g, &r);
	for (int i = 0; i < m; i++)
		for (int x = 0; x <= g; x++)
			dist[i][x] = N;
	dist[0][0] = 0;
	pushBack(mp(0, 0));
	while(L != R) {
		int v = q[L].first, x = q[L].second;
		L++;
		if (L == M) L = 0;
		if (x == g) {
			if (dist[v][0] <= dist[v][x] + 1) continue;
			dist[v][0] = dist[v][x] + 1;
			pushBack(mp(v, 0));
		}
		if (v + 1 < m) {
			int y = x + a[v + 1] - a[v];
			if (y <= g && dist[v + 1][y] > dist[v][x]) {
				dist[v + 1][y] = dist[v][x];
				pushFront(mp(v + 1, y));
			}
		}
		if (v > 0) {
			int y = x + a[v] - a[v - 1];
			if (y <= g && dist[v - 1][y] > dist[v][x]) {
				dist[v - 1][y] = dist[v][x];
				pushFront(mp(v - 1, y));
			}
		}
	}
	int ans = (int)1e9;
	for (int x = 0; x <= g; x++)
		if (dist[m - 1][x] != N)
			ans = min(ans, dist[m - 1][x] * (r + g) + x);
	if (ans == (int)1e9) {
		printf("-1\n");
	} else {
		printf("%d\n", ans);
	}

	return 0;
}