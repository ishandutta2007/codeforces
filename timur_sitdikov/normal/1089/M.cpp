#include <bits/stdc++.h>
using namespace std;

const int N = 9;
int g[N][N];
int used[N], color[N];

void closure(int n) {
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				g[i][j] = max(g[i][j], g[i][k] & g[k][j]);
			}
		}
	}
}

int gg[N][N];

int scc(int n) {
	int colorcnt = 0;
	for (int i = 0; i < n; i++) {
		if (used[i]) {
			continue;
		}
		used[i] = 1;
		color[i] = colorcnt;
		for (int j = 0; j < n; j++) {
			if (g[i][j] && g[j][i]) {
				used[j] = 1;
				color[j] = colorcnt;
			}
		}
		colorcnt++;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (color[i] == color[j] || !g[i][j]) {
				continue;
			}
			gg[color[i]][color[j]] = 1;
		}
	}
	return colorcnt;
}

vector<int> topsort;
void dfs(int v, int n) {
	if (used[v]) {
		return;
	}
	used[v] = 1;
	for (int i = 0; i < n; i++) {
		if (gg[v][i]) {
			dfs(i, n);
		}
	}
	topsort.push_back(v);
}

void tsort(int n) {
	fill(used, used + n, 0);
	for (int i = 0; i < n; i++) {
		dfs(i, n);
	}
	reverse(topsort.begin(), topsort.end());
}

const int M = 30, MM = 200;

char s[M][MM][M];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> g[i][j];
		}
	}

	closure(n);
	int cnt = scc(n);
	tsort(cnt);

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < MM; j++) {
			for (int k = 0; k < M; k++) {
				s[i][j][k] = '#';
			}
		}
	}

	for (int i = 0; i < cnt; i++) {
		int x = topsort[i];
		for (int j = 0; j < cnt; j++) {
			int y = topsort[j];
			if (!gg[x][y]) {
				continue;
			}
			int num = x * 18 + y * 2;
			for (int k = 0; k <= num; k++) {
				s[3 * i][k][0] = s[3 * j][k][0] = '.';
			}
			for (int k = 0; k < 10; k++) {
				s[3 * i][num][k] = s[3 * j][num][k] = '.';
			}
			for (int k = 3 * i; k <= 3 * j; k++) {
				s[k][num][9] = '.';
			}
		}
		int offset = 0;
		for (int j = 0; j < n; j++) {
			if (color[j] == x) {
				s[3 * i][0][offset++] = '0' + j + 1;
			}
		}
	}

	cout << M << " " << MM << " " << M << "\n";

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < MM; j++) {
			for (int k = 0; k < M; k++) {
				cout << s[i][j][k];
			}
			cout << "\n";
		}
		cout << "\n\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	solve();
}