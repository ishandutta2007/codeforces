#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct q{ //kon slon ladya
	int x, y;
	int s;
	q() {}
	q(int x, int y, int s) {
		this->x = x;
		this->y = y;
		this->s = s;
	}
};

const int MAX_N = 11, INF = 1000;
int f[MAX_N][MAX_N];
pair <int, int> best[MAX_N][MAX_N][3];
bool visited[MAX_N][MAX_N][3];
pair <int, int> moves[MAX_N * MAX_N];
int n;

bool ok(int x, int y) {
	return (x >= 0 && y >= 0 && x < n && y < n);
}

bool cmp(pair <int, int> a, pair <int, int> b) {
	if (a.first == b.first) {
		return (a.second < b.second);
	}
	return (a.first < b.first);
}

pair <int, int> summ(pair <int, int> a, pair <int, int> b) {
	return {a.first + b.first, a.second + b.second};
}

vector <pair <int, int>> gen_kon(int x, int y) {
	vector <pair <int, int>> ans;
	for (int fi = -2; fi <= 2; fi++) {
		if (fi == 0) continue;
		if (abs(fi) == 2) {
			for (int se = -1; se <= 1; se += 2) {
				if (ok(x + fi, y + se)) ans.push_back({x + fi, y + se});
			}
		} else {
			for (int se = -2; se <= 2; se += 4) {
				if (ok(x + fi, y + se)) ans.push_back({x + fi, y + se});
			}
		}
	}
	return ans;
}

vector <pair <int, int>> gen_slon(int x, int y) {
	vector <pair <int, int>> ans;
	for (int i = -1; i <= 1; i += 2) {
		for (int j = -1; j <= 1; j += 2) {
			for (int c = 1; c <= 8; c++) {
				if (ok(x + i * c, y + j * c)) ans.push_back({x + i * c, y + j * c});
			}
		}
	}
	return ans;
}

vector <pair <int, int>> gen_ladya(int x, int y) {
	vector <pair <int, int>> ans;
	for (int i = 0; i < n; i++) {
		if (i != x) ans.push_back({i, y});
		if (i != y) ans.push_back({x, i});
	}
	return ans;
}

pair <int, int> find_best(int x1, int y1, int x2, int y2, int s, int f) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			best[i][j][0] = best[i][j][2] = best[i][j][1] = {INF, INF};
			visited[i][j][0] = visited[i][j][2] = visited[i][j][1] = 0;
		}
	}
	queue <q> qu;
	qu.push(q(x1, y1, s));
	best[x1][y1][s] = {0, 0};
	while (!qu.empty()) {
		q elem = qu.front();
		qu.pop();
		int d = best[elem.x][elem.y][elem.s].first, ch = best[elem.x][elem.y][elem.s].second;
		int x = elem.x, y = elem.y;	
		for (int i = 0; i < 3; i++) {
			if (elem.s != i && cmp({d + 1, ch + 1}, best[x][y][i])) {
				best[x][y][i] = {d + 1, ch + 1};
				if (!visited[x][y][i]) {
					qu.push(q(x, y, i));
					visited[x][y][i] = 1;
				}
			}
		}
		vector <pair <int, int>> now;
		if (elem.s == 0) now = gen_kon(x, y);
		if (elem.s == 1) now = gen_slon(x, y);
		if (elem.s == 2) now = gen_ladya(x, y);
		for (pair <int, int> nxt : now) {
			if (cmp({d + 1, ch}, best[nxt.first][nxt.second][elem.s])) {
				best[nxt.first][nxt.second][elem.s] = {d + 1, ch};
				if (!visited[nxt.first][nxt.second][elem.s]) {
					qu.push(q(nxt.first, nxt.second, elem.s));
					visited[nxt.first][nxt.second][elem.s] = 1;
				}
			}
		}
	}
	return best[x2][y2][f];
}

pair <int, int> solve() {
	pair <int, int> best_path[MAX_N * MAX_N][3][3], dp_best[MAX_N * MAX_N][3];
	for (int i = 2; i <= n * n; i++) {
		for (int fi = 0; fi < 3; fi++) {
			for (int se = 0; se < 3; se++) {
				best_path[i][fi][se] = find_best(moves[i - 1].first, moves[i - 1].second, moves[i].first, moves[i].second, fi, se);
			}
		}
	}
	for (int se = 0; se < 3; se++) {
		dp_best[2][se] = min(min(best_path[2][0][se], best_path[2][1][se], cmp), best_path[2][2][se], cmp);
	}
	for (int i = 3; i <= n * n; i++) {
		for (int se = 0; se < 3; se++) {
			dp_best[i][se] = min(min(summ(dp_best[i - 1][0], best_path[i][0][se]), summ(dp_best[i - 1][1], best_path[i][1][se]), cmp), summ(dp_best[i - 1][2], best_path[i][2][se]), cmp);
		}
	}
	return min(min(dp_best[n * n][0], dp_best[n * n][1], cmp), dp_best[n * n][2], cmp);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> f[i][j];
			moves[f[i][j]] = {i, j};
		}
	}
	pair <int, int> ans = solve();
	cout << ans.first << ' ' << ans.second << endl;
	return 0;
}