#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <numeric>
#include <memory.h>
#define mp make_pair
#define pii pair <int, int>
#define ll long long
#define ui unsigned int
#define ld double
#define pll pair <ll, ll> 
 
using namespace std;

const int maxn = 3010;
vector <int> ed[maxn], red[maxn];
int dst[maxn][maxn], rdst[maxn][maxn];

void bfs(int v, int pos) {
	if (pos == 0) {
		dst[v][v] = 0;

		queue <int> q;

		q.push(v);

		while (!q.empty()) {
			int x = q.front();
			q.pop();

			for (int i = 0; i < (int)ed[x].size(); i++) {
				int u = ed[x][i];

				if (dst[v][u] == -1) {
					dst[v][u] = dst[v][x] + 1;
					q.push(u);
				}
			}
		}
	} else {
		rdst[v][v] = 0;

		queue <int> q;

		q.push(v);

		while (!q.empty()) {
			int x = q.front();
			q.pop();

			for (int i = 0; i < (int)red[x].size(); i++) {
				int u = red[x][i];

				if (rdst[v][u] == -1) {
					rdst[v][u] = rdst[v][x] + 1;
					q.push(u);
				}
			}
		}
	}
}

pii ans[maxn][maxn], rans[maxn][maxn];

int main() {
	int n, m;

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y;

		scanf("%d %d", &x, &y);

		ed[x].push_back(y);
		red[y].push_back(x);
	}

	memset(dst, -1, sizeof dst);
	memset(rdst, -1, sizeof rdst);

	for (int i = 1; i <= n; i++) {
		bfs(i, 0);
		bfs(i, 1);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ans[i][j] = mp(dst[i][j], j);
			rans[i][j] = mp(rdst[i][j], j);
		}

		sort(ans[i] + 1, ans[i] + n + 1);
		sort(rans[i] + 1, rans[i] + n + 1);
	}

	int res = 0;
	int a, b, c, d;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = n; k >= n - 2; k--) {
				if (ans[i][k].first == -1) {
					break;
				}

				for (int x = n; x >= n - 2; x--) {
					if (rans[j][x].first == -1) {
						break;
					}

					if (dst[j][i] != -1 && i != j && i != ans[i][k].second && i != rans[j][x].second && j != ans[i][k].second && j != rans[j][x].second && ans[i][k].second != rans[j][x].second) {
						if (res < dst[j][i] + ans[i][k].first + rans[j][x].first) {
							res = dst[j][i] + ans[i][k].first + rans[j][x].first;
							a = rans[j][x].second;
							b = j;
							c = i;
							d = ans[i][k].second;
						}
					}
				}
			}
		}
	}

	cout << a << ' ' << b << ' ' << c << ' ' << d << endl;

	return 0;
}