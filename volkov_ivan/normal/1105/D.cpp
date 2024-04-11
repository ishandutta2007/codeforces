#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MAX_N = 1007;
char field[MAX_N][MAX_N];
int speed[10], ans[10];
int n, m;

bool ok(int x, int y) {
	return (x >= 1 && y >= 1 && x <= n && y <= m && field[x][y] == '.');
}

struct Node{
	int step, dist, player,  x, y;
	Node() {}
	Node(int step, int player, int dist, int x, int y) {
		this->step = step;
		this->player = player;
		this->dist = dist;
		this->x = x;
		this->y = y;
	}
};

bool operator < (const Node &a, const Node &b) {
	if (a.step != b.step) return (a.step < b.step);
	if (a.player != b.player) return (a.player < b.player);
	if (a.dist != b.dist) return (a.dist < b.dist);
	if (a.x != b.x) return (a.x < b.x);
	return (a.y < b.y);
}

int main() {
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	int p;
	cin >> n >> m >> p;
	for (int i = 1; i <= p; i++) cin >> speed[i];
	set <Node> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> field[i][j];
			if (field[i][j] != '.' && field[i][j] != '#') {
				q.insert(Node(0, field[i][j] - '0', 0, i, j));
			}
		}
	}
	while (!q.empty()) {
		Node t = *q.begin();
		q.erase(t);
		for (int c1 = -1; c1 <= 1; c1++) {
			for (int c2 = -1; c2 <= 1; c2++) {
				if (c1 == 0 && c2 == 0) continue;
				if (c1 != 0 && c2 != 0) continue;
				if (ok(t.x + c1, t.y + c2)) {
					if (speed[field[t.x][t.y] - '0'] == t.dist + 1) q.insert(Node(t.step + 1, t.player, 0, t.x + c1, t.y + c2));
					else q.insert(Node(t.step, t.player, t.dist + 1, t.x + c1, t.y + c2));
					field[t.x + c1][t.y + c2] = field[t.x][t.y];
				}
			}
		}
	}
	for (int i = 1; i <= p; i++) ans[i] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (field[i][j] != '.' && field[i][j] != '#') ans[field[i][j] - '0']++;
		}
	}
	for (int i = 1; i <= p; i++) cout << ans[i] << ' ';
	cout << endl;
	return 0;
}