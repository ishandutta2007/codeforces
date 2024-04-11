
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int n, m, q, p;
char in[252][252];
int sound[252][252];
bool visited[252][252];

void init() {
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) visited[i][j] = 0;
}

struct node {
	int x, y, s;
	node(int x_=0, int y_=0, int s_=0) {
		x = x_;
		y = y_;
		s = s_;
	}
	bool isin() {
		return x >= 0 && x < n && y >= 0 && y < m && in[x][y] != '*' && !visited[x][y] && s != 0;
	}
	node left() { return node(x - 1, y, s >> 1); }
	node right() { return node(x + 1, y, s >> 1); }
	node up() { return node(x, y - 1, s >> 1); }
	node down() { return node(x, y + 1, s >> 1); }
	void push() {
		sound[x][y] += s;
		visited[x][y] = 1;
	}
};

int main() {
	scanf("%d%d%d%d", &n, &m, &q, &p);
	
	vector<node> todfs;

	for (int i = 0; i < n; i++) {
		scanf("%s", in[i]);
		
		for (int j = 0; j < m; j++)
			if (in[i][j] != '.' && 	in[i][j] != '*') {
				todfs.push_back(node(i, j, q * (in[i][j] - 'A' + 1)));
			}
	}

	for (int x = 0; x < (int) todfs.size(); x++) {
		node n;
		n = todfs[x];

		init();
		queue<node> dfs;
		dfs.push(n);
		visited[n.x][n.y] = true;
		sound[n.x][n.y] += n.s;

		while (!dfs.empty()) {
			n = dfs.front(); dfs.pop();
			if (n.left().isin()) {
				n.left().push();
				dfs.push(n.left());
			}
			if (n.right().isin()) {
				n.right().push();
				dfs.push(n.right());
			}
			if (n.up().isin()) {
				n.up().push();
				dfs.push(n.up());
			}
			if (n.down().isin()) {
				n.down().push();
				dfs.push(n.down());
			}
		}
	}

	int count = 0;

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
		if (sound[i][j] > p) {
			count++;
		}

	printf("%d\n", count);
}