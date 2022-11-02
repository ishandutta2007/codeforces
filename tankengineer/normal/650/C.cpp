#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1000005;

int n, m;

vector<vector<int> > table;

vector<int> edge[N];

int dgr[N];

int fa[N];

int getID(int a, int b) {
	return a * m + b;
}

int find(int u) {
	return u == fa[u] ? u : fa[u] = find(fa[u]);
}

void merge(int u, int v) {
	fa[u] = v;
}

int curR, curC;

bool byC(const int &i, const int &j) {
	return table[curR][i] < table[curR][j] || (table[curR][i] == table[curR][j] && i < j);
}

bool byR(const int &i, const int &j) {
	return table[i][curC] < table[j][curC] || (table[i][curC] == table[j][curC] && i < j);
}

int ord[N];

int qhead, qtail, q[N];

int ans[N];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		vector<int> line(m);
		for (int j = 0; j < m; ++j) {
			scanf("%d", &line[j]);
		}
		table.push_back(line);
	}
	for (int i = 0; i < n * m; ++i) {
		fa[i] = i;
	}
	for (int i = 0; i < n; ++i) {
		curR = i;
		for (int j = 0; j < m; ++j) {
			ord[j] = j;
		}
		sort(ord, ord + m, byC);	
		for (int j = 0; j + 1 < m; ++j) {
			int u = getID(i, ord[j]), v = getID(i, ord[j + 1]);
			if (table[i][ord[j]] == table[i][ord[j + 1]]) {
				merge(find(u), find(v));
			}
		}
	}
	for (int i = 0; i < m; ++i) {
		curC = i;
		for (int j = 0; j < n; ++j) {
			ord[j] = j;
		}
		sort(ord, ord + n, byR);
		for (int j = 0; j + 1 < n; ++j) {
			int u = getID(ord[j], i), v = getID(ord[j + 1], i);
			if (table[ord[j]][i] == table[ord[j + 1]][i]) {
				merge(find(u), find(v));
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		curR = i;
		for (int j = 0; j < m; ++j) {
			ord[j] = j;
		}
		sort(ord, ord + m, byC);	
		for (int j = 0; j + 1 < m; ++j) {
			int u = getID(i, ord[j]), v = getID(i, ord[j + 1]);
			if (table[i][ord[j]] != table[i][ord[j + 1]]) {
				edge[find(u)].push_back(find(v));
				++dgr[find(v)];
			}
		}
	}
	for (int i = 0; i < m; ++i) {
		curC = i;
		for (int j = 0; j < n; ++j) {
			ord[j] = j;
		}
		sort(ord, ord + n, byR);
		for (int j = 0; j + 1 < n; ++j) {
			int u = getID(ord[j], i), v = getID(ord[j + 1], i);
			if (table[ord[j]][i] != table[ord[j + 1]][i]) {
				edge[find(u)].push_back(find(v));
				++dgr[find(v)];
			}
		}
	}
	qhead = qtail = 0;
	for (int i = 0; i < n * m; ++i) {
		if (find(i) == i && dgr[i] == 0) {
			q[qtail++] = i;
		}
	}
	while (qhead < qtail) {
		int u = q[qhead++];
		for (int i = 0; i < (int)edge[u].size(); ++i) {
			int v = edge[u][i];
			ans[v] = max(ans[v], ans[u] + 1);
			if (--dgr[v] == 0) {
				q[qtail++] = v;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			printf("%d%c", ans[find(i * m + j)] + 1, j == m - 1 ? '\n' : ' ');
		}
	}
	return 0;
}