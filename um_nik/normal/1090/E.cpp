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

const int INF = 1000;

const int N = 1600;
int ans[N][4];
int ansSz;
int dist[10][10];
int par[10][10][2];
int t[10][10];
pii q[100];
int topQ;
const int DX[] = {-1, -2, -2, -1, 1, 2, 2, 1};
const int DY[] = {2, 1, -1, -2, -2, -1, 1, 2};

void addAns(int x, int y, int z, int u) {
	ans[ansSz][0] = x;
	ans[ansSz][1] = y;
	ans[ansSz][2] = z;
	ans[ansSz][3] = u;
	ansSz++;
}

bool checkCell(int x, int y) {
	return min(x, y) >= 0 && max(x, y) < 8;
}

void BFS(int x, int y) {
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			dist[i][j] = INF;
	dist[x][y] = 0;
	topQ = 0;
	q[topQ++] = mp(x, y);
	for (int i = 0; i < topQ; i++) {
		x = q[i].first;
		y = q[i].second;
		for (int j = 0; j < 8; j++) {
			int nx = x + DX[j], ny = y + DY[j];
			if (!checkCell(nx, ny)) continue;
			if (dist[nx][ny] <= dist[x][y] + 1) continue;
			par[nx][ny][0] = x;
			par[nx][ny][1] = y;
			dist[nx][ny] = dist[x][y] + 1;
			q[topQ++] = mp(nx, ny);
		}
	}
}

void solve(int sx, int sy, int tx, int ty) {
//	eprintf("solve %d %d %d %d\n", sx, sy, tx, ty);
	BFS(sx, sy);
	vector<pii> path;
	while(true) {
//		eprintf("%d %d\n", tx, ty);
		if (t[tx][ty] == 1) {
			int cx = tx, cy = ty;
			while(!path.empty()) {
				int nx = path.back().first, ny = path.back().second;
				addAns(cx, cy, nx, ny);
				swap(t[cx][cy], t[nx][ny]);
				cx = nx;
				cy = ny;
				path.pop_back();
			}
		}
		if (tx == sx && ty == sy) break;
		path.push_back(mp(tx, ty));
		int nx = par[tx][ty][0], ny = par[tx][ty][1];
		tx = nx;
		ty = ny;
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		int x = (int)(s[1] - '1'), y = (int)(s[0] - 'a');
		t[x][y] = 1;
	}
	for (int x = 7; x >= 0; x--)
		for (int y = 7; y >= 0; y--) {
			if (x * 8 + y < m) break;
			if (t[x][y] == 0) continue;
			bool ok = false;
			for (int i = 0; !ok && i < 8; i++)
				for (int j = 0; !ok && j < 8; j++) {
					if (t[i][j] == 1) continue;
					ok = true;
					solve(x, y, i, j);
				}
		}
	printf("%d\n", ansSz);
	for (int i = 0; i < ansSz; i++)
		printf("%c%d-%c%d\n", (char)('a' + ans[i][1]), 1 + ans[i][0], (char)('a' + ans[i][3]), 1 + ans[i][2]);

	return 0;
}