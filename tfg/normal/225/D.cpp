#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <map>
#include <queue>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int n, m;
int ch;
int xx, yy;
struct Board {
	char mat[15][15];
	int x, y;
	void read() {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				std::cin >> mat[i][j];
				if(mat[i][j] == '1') {
					x = i, y = j;
				}
				if('1' <= mat[i][j] && mat[i][j] <= '9') {
					ch = std::max(ch, mat[i][j] - '0');
				}
				if(mat[i][j] == '@') {
					xx = i, yy = j;
				}
			}
		}
	}

	bool operator < (const Board &o) const {
		if(x != o.x) return x < o.x;
		else if(y != o.y) return y < o.y;
		else {
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < m; j++) {
					if(mat[i][j] != o.mat[i][j]) {
						return mat[i][j] < o.mat[i][j];
					}
				}
			}
			return false;
		}
	}

	int heuristic() {
		return abs(x-xx) + abs(y-yy);
	}

	bool canEnd() {
		for(int i = 0; i < 4; i++) {
			int tox = x + dx[i], toy = y + dy[i];
			if(tox < 0 || tox >= n || toy < 0 || toy >= m) {
				continue;
			}
			if(mat[tox][toy] == '@') {
				return true;
			}
		}
		return false;
	}

	std::vector<Board> nxt() {
		std::vector<Board> ans;
		for(int k = 0; k < 4; k++) {
			int tox = x + dx[k], toy = y + dy[k];
			if(tox < 0 || tox >= n || toy < 0 || toy >= m) {
				continue;
			}
			if(mat[tox][toy] == '.' || mat[tox][toy] == '0' + ch) {
				//std::cout << tox << ' ' << toy << '\n';
				Board ha = *this;
				for(int i = 0; i < n; i++) {
					for(int j = 0; j < m; j++) {
						if('1' <= ha.mat[i][j] && ha.mat[i][j] <= '9') {
							if(ha.mat[i][j] == '0' + ch) {
								ha.mat[i][j] = '.';
							} else {
								ha.mat[i][j]++;
							}
						}
					}
				}
				ha.x = tox, ha.y = toy;
				ha.mat[tox][toy] = '1';
				ans.push_back(ha);
			}
		}
		return ans;
	}

	void print() {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				std::cout << mat[i][j];
			}
			std::cout << '\n';
		}
	}
};

struct Node {
	Board state;
	int dist, heuristic;
	Node(Board b, int lul) {
		dist = lul;
		state = b;
		heuristic = dist + b.heuristic();
	}
	bool operator < (const Node &o) const { return heuristic != o.heuristic ? heuristic > o.heuristic : dist < o.dist; }
};

bool visit[15][15];
bool dfs(int x, int y, const Board &ha) {
	visit[x][y] = true;
	if(ha.mat[x][y] == '@') return true;
	for(int i = 0; i < 4; i++) {
		int tox = x + dx[i], toy = y + dy[i];
		if(tox < 0 || tox >= n || toy < 0 || toy >= m) {
			continue;
		}
		if(ha.mat[tox][toy] == '#') {
			continue;
		}
		if(!visit[tox][toy] && dfs(tox, toy, ha)) return true;
	}
	return false;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::cin >> n >> m;
	Board init;
	init.read();
	if(!dfs(init.x, init.y, init)) {
		std::cout << "-1\n";
		return 0;
	}
	std::map<Board, int> dist;
	dist[init] = 0;
	std::priority_queue<Node> q;
	q.push(Node(init, 0));
	while(!q.empty()) {
		auto cur = q.top();
		q.pop();
		//cur.state.print();
		if(cur.state.canEnd()) {
			std::cout << cur.dist + 1 << '\n';
			return 0;
		}
		auto nxt = cur.state.nxt();
		for(auto ha : nxt) {
			if(!dist.count(ha)) {
				//std::cout << "adding!\n";
				//ha.print();
				dist[ha] = cur.dist + 1;
				q.push(Node(ha, cur.dist + 1));
			} else {
				//std::cout << "not adding!\n";
				//ha.print();
			}
		}
	}
	std::cout << "-1\n";
}