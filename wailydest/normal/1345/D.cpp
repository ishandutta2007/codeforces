#include <cstdio>
#include <queue>
using namespace std;

const int N = 1000;

int n, m;
bool matrix[N][N];
int comp_n = 1;
int comp[N][N];
bool row_zero[N], col_zero[N];

void bfs(int i, int j) 
{
	queue<pair<int, int> > q;
	comp[i][j] = comp_n;
	q.push(make_pair(i, j));
	while (!q.empty()) {
		i = q.front().first;
		j = q.front().second;
		q.pop();
		if (i + 1 < n && matrix[i + 1][j] && !comp[i + 1][j]) {
			comp[i + 1][j] = comp_n;
			q.push(make_pair(i + 1, j));
		}
		if (i > 0 && matrix[i - 1][j] && !comp[i - 1][j]) {
			comp[i - 1][j] = comp_n;
			q.push(make_pair(i - 1, j));
		}
		if (j + 1 < m && matrix[i][j + 1] && !comp[i][j + 1]) {
			comp[i][j + 1] = comp_n;
			q.push(make_pair(i, j + 1));
		}
		if (j > 0 && matrix[i][j - 1] && !comp[i][j - 1]) {
			comp[i][j - 1] = comp_n;
			q.push(make_pair(i, j - 1));
		}
	}
	++comp_n;
}

int main() 
{
	scanf("%d%d", &n, &m);
	char buf[N + 1];
	for (int i = 0; i < n; ++i) {
		scanf("%s", buf);
		for (int j = 0; j < m; ++j) if (buf[j] == '#') matrix[i][j] = true;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) if (matrix[i][j] && !comp[i][j]) bfs(i, j);
	}
	bool ok = true;
	int put_comp;
	for (int i = 0; i < n; ++i) {
		put_comp = 0;
		for (int j = 0; j < m; ++j) {
			if (matrix[i][j]) {
				if (!put_comp) put_comp = 1;
				else if (put_comp == 2) ok = false;
			}
			else if (put_comp == 1) put_comp = 2;
		}
	}
	if (!ok) {
		printf("-1\n");
		return 0;
	}
	for (int j = 0; j < m; ++j) {
		put_comp = 0;
		for (int i = 0; i < n; ++i) {
			if (matrix[i][j]) {
				if (!put_comp) put_comp = 1;
				else if (put_comp == 2) ok = false;
			}
			else if (put_comp == 1) put_comp = 2;
		}
	}
	if (!ok) {
		printf("-1\n");
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		bool z = 1;
		for (int j = 0; j < m; ++j) z = z && !matrix[i][j];
		row_zero[i] = z;
	}
	for (int j = 0; j < m; ++j) {
		bool z = 1;
		for (int i = 0; i < n; ++i) z = z && !matrix[i][j];
		col_zero[j] = z;
	}
	for (int i = 0; i < n; ++i) {
		if (row_zero[i]) {
			bool z = 0;
			for (int j = 0; j < m; ++j) z = z || col_zero[j];
			ok = z;
		}
	}
	if (!ok) {
		printf("-1\n");
		return 0;
	}
	for (int j = 0; j < m; ++j) {
		if (col_zero[j]) {
			bool z = 0;
			for (int i = 0; i < n; ++i) z = z || row_zero[i];
			ok = z;
		}
	}
	if (!ok) {
		printf("-1\n");
		return 0;
	}
	printf("%d\n", comp_n - 1);
	return 0;
}