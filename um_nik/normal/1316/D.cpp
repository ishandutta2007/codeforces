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
pii a[N][N];
char ans[N][N];
const int DX[] = {-1, 1, 0, 0};
const int DY[] = {0, 0, -1, 1};
const char DD[] = "UDLR";

bool checkCell(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

void dfs(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int xx = x + DX[i], yy = y + DY[i];
		if (!checkCell(xx, yy)) continue;
		if (a[xx][yy] != a[x][y]) continue;
		if (ans[xx][yy] != '.') continue;
		ans[xx][yy] = DD[i ^ 1];
		dfs(xx, yy);
	}
}

int main()
{
	startTime = (double)clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			scanf("%d%d", &a[i][j].first, &a[i][j].second);
			if (a[i][j].first != -1) {
				a[i][j].first--;
				a[i][j].second--;
			}
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			ans[i][j] = '.';
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (a[i][j].first == i && a[i][j].second == j) {
				ans[i][j] = 'X';
				dfs(i, j);
			}
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (a[i][j].first != -1) continue;
			for (int d = 0; d < 4; d++) {
				int x = i + DX[d], y = j + DY[d];
				if (!checkCell(x, y)) continue;
				if (a[x][y] == mp(-1, -1)) ans[i][j] = DD[d];
			}
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (ans[i][j] == '.') {
				printf("INVALID\n");
				return 0;
			}
	printf("VALID\n");
	for (int i = 0; i < n; i++) {
		ans[i][n] = '\0';
		printf("%s\n", ans[i]);
	}

	return 0;
}