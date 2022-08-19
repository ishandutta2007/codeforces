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

const int K = 60;
const int N = 100100;
ll a[N];
int b[K];
vector<int> g[N];
int n;
int dist[N];
int q[N];
int topQ;
int ans = N;

void solve(int v) {
	topQ = 0;
	for (int i = 0; i < n; i++)
		dist[i] = N;
	dist[v] = 0;
	q[topQ++] = v;
	for (int i = 0; i < topQ; i++) {
		v = q[i];
		for (int u : g[v]) {
			if (dist[u] == N) {
				dist[u] = dist[v] + 1;
				q[topQ++] = u;
			} else if (dist[u] >= dist[v]) {
				ans = min(ans, dist[v] + dist[u] + 1);
			}
		}
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		if (a[i] == 0) {
			i--;
			n--;
			continue;
		}
		for (int k = 0; k < K; k++)
			if ((a[i] >> k) & 1) {
				b[k]++;
				if (b[k] >= 3) {
					printf("3\n");
					return 0;
				}
			}
	}
	if (n > 2 * K) throw;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if ((a[i] & a[j]) != 0)
				g[i].push_back(j);
		}
	for (int i = 0; i < n; i++)
		solve(i);
	if (ans == N) ans = -1;
	printf("%d\n", ans);

	return 0;
}