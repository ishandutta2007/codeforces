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
int n, m;
char s[N][N];
bool used[N][N];
const int DX[] = {-1, 1, 0, 0};
const int DY[] = {0, 0, -1, 1};

bool checkCell(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}
void dfs(int x, int y) {
	used[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int xx = x + DX[i], yy = y + DY[i];
		if (!checkCell(xx, yy) || s[xx][yy] == '.') continue;
		if (used[xx][yy]) continue;
		dfs(xx, yy);
	}
}

int main()
{
	startTime = (double)clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", s[i]);
	int A = 0, B = 0;
	for (int x = 0; x < n; x++) {
		int l = m, r = -2, cnt = 0;
		for (int y = 0; y < m; y++) {
			if (s[x][y] == '#') {
				l = min(l, y);
				r = max(r, y);
				cnt++;
			}
		}
		if (cnt > 0 && cnt != (r - l + 1)) {
			printf("-1\n");
			return 0;
		}
		if (cnt == 0) A++;
	}
	for (int y = 0; y < m; y++) {
		int l = n, r = -2, cnt = 0;
		for (int x = 0; x < n; x++) {
			if (s[x][y] == '#') {
				l = min(l, x);
				r = max(r, x);
				cnt++;
			}
		}
		if (cnt > 0 && cnt != (r - l + 1)) {
			printf("-1\n");
			return 0;
		}
		if (cnt == 0) B++;
	}
	if ((A == 0) ^ (B == 0)) {
		printf("-1\n");
		return 0;
	}
	int ans = 0;
	for (int x = 0; x < n; x++)
		for (int y = 0; y < m; y++) {
			if (s[x][y] == '#' && !used[x][y]) {
				ans++;
				dfs(x, y);
			}
		}
	printf("%d\n", ans);

	return 0;
}