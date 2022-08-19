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

const ll INF = (ll)2e18;
const int N = 1010;
char s[N][N];
int n, m;
const int DX[] = {-1, 1, 0, 0};
const int DY[] = {0, 0, -1, 1};
ll dist[N][N];
pii q[N * N];
int topQ;

bool checkCell(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y <= m;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++)
		scanf("%s", s[i]);
	for (int x = 0; x < n; x++)
		for (int y = 0; y < m; y++) {
			dist[x][y] = INF;
			for (int i = 0; i < 4; i++) {
				int xx = x + DX[i], yy = y + DY[i];
				if (!checkCell(xx, yy)) continue;
				if (s[xx][yy] == s[x][y]) dist[x][y] = 0;
			}
			if (dist[x][y] == 0) q[topQ++] = mp(x, y);
		}
	for (int i = 0; i < topQ; i++) {
		int x = q[i].first, y = q[i].second;
		for (int j = 0; j < 4; j++) {
			int xx = x + DX[j], yy = y + DY[j];
			if (!checkCell(xx, yy)) continue;
			if (dist[xx][yy] <= dist[x][y] + 1) continue;
			dist[xx][yy] = dist[x][y] + 1;
			q[topQ++] = mp(xx, yy);
		}
	}
	while(k--) {
		int x, y;
		ll t;
		scanf("%d%d%lld", &x, &y, &t);
		x--;y--;
		char ans = s[x][y];
		if (t >= dist[x][y] && (t - dist[x][y]) % 2 == 1) ans ^= 1;
		printf("%c\n", ans);
	}

	return 0;
}