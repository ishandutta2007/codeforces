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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1010;
int n, m;
bool g[N][N];
int a[N][3];
int b[N][3];
int pts[N][2];
int k;
map<int, vector<int>> forX, forY;
int mt[N];
bool used[N];
bool tak[2][N];

struct Segm {
	int x1, y1, x2, y2;

	Segm() : x1(), y1(), x2(), y2() {}
	Segm(int _x1, int _y1, int _x2, int _y2) : x1(_x1), y1(_y1), x2(_x2), y2(_y2) {}

	void print() {
		printf("%d %d %d %d\n", x1, y1, x2, y2);
	}
};

vector<Segm> ans[2];

bool dfs(int x) {
	if (used[x]) return false;
	used[x] = 1;
	for (int y = 0; y < m; y++) {
		if (!g[x][y]) continue;
		if (mt[y] == -1 || dfs(mt[y])) {
			mt[y] = x;
			return true;
		}
	}
	return false;
}

int kuhn() {
	for (int i = 0; i < m; i++)
		mt[i] = -1;
	int res = 0;
	for (int x = 0; x < n; x++) {
		if (dfs(x)) {
			for (int i = 0; i < n; i++)
				used[i] = false;
			res++;
		}
	}
	return res;
}

void connectHor(int x, int y1, int y2) {
	y1--;
	y2++;
	for (int i = 0; i < (int)ans[0].size(); i++) {
		if (ans[0][i].x1 == x && ans[0][i].y2 == y1) {
			y1 = ans[0][i].y1;
			swap(ans[0][i], ans[0].back());
			break;
		}
	}
	ans[0].pop_back();
	for (int i = 0; i < (int)ans[0].size(); i++) {
		if (ans[0][i].x1 == x && ans[0][i].y1 == y2) {
			y2 = ans[0][i].y2;
			swap(ans[0][i], ans[0].back());
			break;
		}
	}
	ans[0].pop_back();
	ans[0].push_back(Segm(x, y1, x, y2));
}
void connectVert(int y, int x1, int x2) {
	x1--;
	x2++;
	for (int i = 0; i < (int)ans[1].size(); i++) {
		if (ans[1][i].y1 == y && ans[1][i].x2 == x1) {
			x1 = ans[1][i].x1;
			swap(ans[1][i], ans[1].back());
			break;
		}
	}
	ans[1].pop_back();
	for (int i = 0; i < (int)ans[1].size(); i++) {
		if (ans[1][i].y1 == y && ans[1][i].x1 == x2) {
			x2 = ans[1][i].x2;
			swap(ans[1][i], ans[1].back());
			break;
		}
	}
	ans[1].pop_back();
	ans[1].push_back(Segm(x1, y, x2, y));
}



int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		pts[i][0] = x;
		pts[i][1] = y;
		forX[x].push_back(y);
		forY[y].push_back(x);
	}
	for (auto t : forX) {
		int x = t.first;
		vector<int> ys = t.second;
		sort(ys.begin(), ys.end());
		for (int i = 0; i < (int)ys.size() - 1; i++) {
			a[n][0] = x;
			a[n][1] = ys[i] + 1;
			a[n][2] = ys[i + 1] - 1;
			n++;
		}
	}
	for (auto t : forY) {
		int y = t.first;
		vector<int> xs = t.second;
		sort(xs.begin(), xs.end());
		for (int i = 0; i < (int)xs.size() - 1; i++) {
			b[m][0] = y;
			b[m][1] = xs[i] + 1;
			b[m][2] = xs[i + 1] - 1;
			m++;
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (a[i][0] < b[j][1] || a[i][0] > b[j][2]) continue;
			if (b[j][0] < a[i][1] || b[j][0] > a[i][2]) continue;
			g[i][j] = 1;
		}

	int mtSz = kuhn();
//	printf("%d\n", 2 * k - (n + m - mtSz));

	for (int i = 0; i < n; i++)
		used[i] = false;
	for (int i = 0; i < n; i++)
		tak[0][i] = true;
	for (int i = 0; i < m; i++)
		if (mt[i] != -1)
			tak[0][mt[i]] = false;
	for (int i = 0; i < n; i++)
		if (tak[0][i])
			dfs(i);

	for (int i = 0; i < n; i++)
		tak[0][i] = true;
	for (int i = 0; i < m; i++)
		tak[1][i] = true;
	for (int i = 0; i < m; i++) {
		if (mt[i] == -1) continue;
		if (used[mt[i]])
			tak[1][i] = false;
		else
			tak[0][mt[i]] = false;
	}

	for (int i = 0; i < k; i++) {
		int x = pts[i][0], y = pts[i][1];
		ans[0].push_back(Segm(x, y, x, y));
		ans[1].push_back(Segm(x, y, x, y));
	}

	for (int i = 0; i < n; i++)
		if (tak[0][i])
			connectHor(a[i][0], a[i][1], a[i][2]);
	for (int i = 0; i < m; i++)
		if (tak[1][i])
			connectVert(b[i][0], b[i][1], b[i][2]);

	for (int it = 1; it >= 0; it--) {
		printf("%d\n", (int)ans[it].size());
		for (Segm S : ans[it])
			S.print();
	}

	return 0;
}