#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 100010;
vector<int> son[maxn];
int n, m, q, now, ans[maxn];
int a[1005][1005], Q[maxn][3];
bool p[maxn];
void dfs(int x) {
	p[x] = false;
	if (Q[x][0] == 1) {
		int i = Q[x][1], j = Q[x][2];
		if (a[i][j] == 0) p[x] = true, a[i][j] = 1, ++now;
	}
	if (Q[x][0] == 2) {
		int i = Q[x][1], j = Q[x][2];
		if (a[i][j] == 1) p[x] = true, a[i][j] = 0, --now;
	}
	if (Q[x][0] == 3) {
		int row = Q[x][1];
		for (int i = 1; i <= m; ++i) {
			if (a[row][i]) --now;
			else ++now;
			a[row][i] = 1 - a[row][i];
		}
	}
	ans[x] = now;	
	
	for (unsigned int i = 0; i < son[x].size(); ++i)
		dfs(son[x][i]);
		
	if (Q[x][0] == 3) {
		int row = Q[x][1];
		for (int i = 1; i <= m; ++i) {
			if (a[row][i]) --now;
			else ++now;
			a[row][i] = 1 - a[row][i];
		}	
	}
	if (Q[x][0] == 1 && p[x]) {
		int i = Q[x][1], j = Q[x][2];
		a[i][j] = 0; --now;
	}
	if (Q[x][0] == 2 && p[x]) {
		int i = Q[x][1], j = Q[x][2];
		a[i][j] = 1; ++now;
	} 
}
int main() {
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= q; ++i) {
		int type, k;
		scanf("%d", &type);
		Q[i][0] = type;
		if (type == 4) {
			scanf("%d", &k);
			son[k].push_back(i);
		}
		else {
			son[i - 1].push_back(i);
			if (type == 1 || type == 2) 
				scanf("%d%d", &Q[i][1], &Q[i][2]);
			else scanf("%d", &Q[i][1]);
		}
	}
	dfs(0);
	for (int i = 1; i <= q; ++i)
		printf("%d\n", ans[i]);
}