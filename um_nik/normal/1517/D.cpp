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

const int INF = (int)5e7;
const int K = 15;
const int N = 555;
const int DX[] = {-1, 1, 0, 0};
const int DY[] = {0, 0, -1, 1};
int e[N][N][4];
int w[K][2 * K][2 * K];
int n, m, k;

inline void upd(int &x, int y) {
	x = min(x, y);
}

int solve(int X, int Y) {
	for (int i = 0; i <= k; i++)
		for (int x = -i; x <= i; x++) {
			int d = i - abs(x);
			for (int y = -d; y <= d; y++)
				w[i][K + x][K + y] = INF;
		}
	w[0][K][K] = 0;
	for (int i = 0; i < k; i++)
		for (int x = -i; x <= i; x++) {
			int d = i - abs(x);
			for (int y = -d; y <= d; y++) {
				for (int j = 0; j < 4; j++)
					upd(w[i + 1][K + x + DX[j]][K + y + DY[j]],
						w[i][K + x][K + y] + e[X + x][Y + y][j]);
			}
		}
	int ans = INF;
	for (int x = -k; x <= k; x++) {
		int d = k - abs(x);
		for (int y = -d; y <= d; y++)
			ans = min(ans, w[k][K + x][K + y]);
	}
	return 2 * ans;
}

void read() {

	scanf("%d%d%d", &n, &m, &k);
//	n = m = 500;
//	k = 20;
	
	for (int i = 0; i < n + 2 * K; i++)
		for (int j = 0; j < m + 2 * K; j++)
			for (int d = 0; d < 4; d++)
				e[i][j][d] = INF;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m - 1; j++) {
			int w;
			scanf("%d", &w);
//			w = myRand((int)1e6);
			e[i + K][j + K][3] = e[i + K][j + 1 + K][2] = w;
		}
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < m; j++) {
			int w;
			scanf("%d", &w);
//			w = myRand((int)1e6);
			e[i + K][j + K][1] = e[i + 1 + K][j + K][0] = w;
		}

}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	read();

	if (k & 1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				printf("-1 ");
			printf("\n");
		}
		return 0;
	}
	k /= 2;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			printf("%d ", solve(i + K, j + K));
		printf("\n");
	}

	return 0;
}