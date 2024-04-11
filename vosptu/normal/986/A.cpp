#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <cstdlib>
#include <set>
#include <algorithm>
#include <ctime>
using namespace std;

int dis[110][110000];
int n, m, k, s, a[110000], b[110000], qu[110000];
vector <int> ve[110000];

void bfs(int x) {
	int l = 1, r = 0;
	for (int i = 1; i <= n; i++)
		if (a[i] == x) {
			r++;
			qu[r] = i;
			dis[x][i] = 1;
		}
	while (l <= r) {
		int p = qu[l];
		for (int i = 0; i < (int) ve[p].size(); i++) {
			int q = ve[p][i];
			if (!dis[x][q]) {
				r ++;
				qu[r] = q;
				dis[x][q] = dis[x][p] + 1;
			}
		}
		l += 1;
	}
}

int main() {
	scanf("%d%d%d%d", &n, &m, &k, &s);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	while (m--) {
		int x, y;
		scanf("%d%d", &x, &y);
		ve[x].push_back(y);
		ve[y].push_back(x);
	}
	// printf("xx\n");
	for (int i = 1; i <= k; i++)
		bfs(i);
	// printf("xx\n");
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++)
			b[j] = dis[j][i];
		sort(b + 1, b + k + 1);
		int ans = 0;
		for (int j = 1; j <= s; j++)
			ans += b[j] - 1;
		printf("%d ", ans);
	}
	printf("\n");
}