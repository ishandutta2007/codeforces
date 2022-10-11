#include <iostream>
#include <cstring>
#include <string>
#include <utility>
#include <queue>
#include <set>

typedef std::pair<int, int> ii;

const int ms = 1010;
std::string board[ms];
int left[ms][ms];
int up[ms][ms];
int right[ms][ms];
int down[ms][ms];
int dist[ms][ms];
std::set<int> rows[ms], cols[ms];

int main() {
	int n, m, k;
	std::cin >> n >> m >> k;
	for(int i = 0; i < n; i++) {
		std::cin >> board[i];
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(i) {
				up[i][j] = up[i - 1][j];
			}
			
			if(j) {
				left[i][j] = left[i][j - 1];
			}
			if(board[i][j] == '.') {
				up[i][j]++;
				left[i][j]++;
				rows[i].insert(j);
				cols[j].insert(i);
			} else {
				up[i][j] = down[i][j] = left[i][j] = right[i][j] = 0;
			}
		}
	}
	for(int i = n - 1; i >= 0; i--) {
		for(int j = m - 1; j >= 0; j--) {
			if(i + 1 != n) {
				down[i][j] = down[i + 1][j];
			}
			if(j + 1 != m) {
				right[i][j] = right[i][j + 1];
			}
			if(board[i][j] == '.') {
				down[i][j]++;
				right[i][j]++;
			} else {
				up[i][j] = down[i][j] = left[i][j] = right[i][j] = 0;
			}
		}
	}
	int x1, y1, x2, y2;
	std::cin >> x1 >> y1 >> x2 >> y2;
	x1--;y1--;x2--;y2--;
	std::queue<ii> q;
	q.push(ii(x1, y1));
	memset(dist, 0x3f, sizeof dist);
	dist[x1][y1] = 0;
	while(!q.empty()) {
		ii cur = q.front();
		q.pop();
		//std::cout << "on (" << cur.first << ", " << cur.second << ") got " << dist[cur.first][cur.second] << "\n";
		auto st = rows[cur.first].lower_bound(cur.second - std::min(k, left[cur.first][cur.second] - 1));
		auto en = rows[cur.first].upper_bound(cur.second + std::min(k, right[cur.first][cur.second] - 1));
		int cur_dist = dist[cur.first][cur.second];
		for(auto it = st; it != en; it++) {
			//std::cout << "1: trying to (" << cur.first << ", " << *it << ")\n";
			if(dist[cur.first][*it] > 1 + cur_dist) {
				dist[cur.first][*it] = 1 + cur_dist;
				q.push(ii(cur.first, *it));
			}
		}
		rows[cur.first].erase(st, en);
		st = cols[cur.second].lower_bound(cur.first - std::min(k, up[cur.first][cur.second] - 1));
		en = cols[cur.second].upper_bound(cur.first + std::min(k, down[cur.first][cur.second] - 1));
		for(auto it = st; it != en; it++) {
			//std::cout << "2: trying to (" << *it << ", " << cur.second << ")\n";
			if(dist[*it][cur.second] > 1 + cur_dist) {
				dist[*it][cur.second] = 1 + cur_dist;
				q.push(ii(*it, cur.second));
			}
		}
		cols[cur.second].erase(st, en);
	}
	if(dist[x2][y2] >= 1e9) {
		std::cout << "-1\n";
	} else {
		std::cout << dist[x2][y2] << '\n';
	}
}