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

const int N = 2020;
const int M = N * N;
const int S = (int)1e6 + 7;
int n, m;
int a[N][2];
int b[N][2];
int c[S];
pii d[M], e[M];
int ans = S;
bool good[N][N];

int getFirst(int pos) {
	if (pos == 0) return 0;
	int p = d[pos - 1].first, q = d[pos - 1].second;
	return max(0, b[q][0] - a[p][0]);
}
int getSecond(int pos) {
	if (pos == 0) return 0;
	int p = e[pos - 1].first, q = e[pos - 1].second;
	return max(0, b[q][1] - a[p][1]);
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &a[i][0], &a[i][1]);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &b[i][0], &b[i][1]);
		b[i][0]++;
		b[i][1]++;
	}

	for (int i = 0; i < S; i++)
		c[i] = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			int x = max(0, b[j][0] - a[i][0]);
			c[x + 1]++;
		}
	for (int i = 1; i < S; i++)
		c[i] += c[i - 1];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			int x = max(0, b[j][0] - a[i][0]);
			d[c[x]++] = mp(i, j);
		}
	

	for (int i = 0; i < S; i++)
		c[i] = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			int x = max(0, b[j][1] - a[i][1]);
			c[x + 1]++;
		}
	for (int i = 1; i < S; i++)
		c[i] += c[i - 1];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			int x = max(0, b[j][1] - a[i][1]);
			e[c[x]++] = mp(i, j);
		}
	
	int pos = 0;
	for (int i = n * m - 1; i >= 0; i--) {
		int p = d[i].first, q = d[i].second;
		ans = min(ans, getFirst(i + 1) + getSecond(pos));
		while(!good[p][q]) {
			good[e[pos].first][e[pos].second] = 1;
			pos++;
		}
		ans = min(ans, getFirst(i) + getSecond(pos));
	}
	printf("%d\n", ans);

	return 0;
}