#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int INF = 1e9;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

struct Cell {
	int ori;
	int first;

	void read() {
		char c;
		std::cin >> c;
		ori = c - '0';
		first = INF;
	}

	int qry(long long t) {
		if(first >= INF) return ori;
		else if(t <= first) return ori;
		else return (int) ((t + first + ori) % 2);
	}
};

int n, m, q;
Cell mat[1000][1000];
int queue[1000000];

bool valid(int i, int j) { return 0 <= i && 0 <= j && i < n && j < m; }

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::cin >> n >> m >> q;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			mat[i][j].read();
		}
	}
	int size = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			for(int dir = 0; dir < 4; dir++) {
				int x = i + dx[dir];
				int y = j + dy[dir];
				if(valid(x, y) && mat[x][y].qry(0) == mat[i][j].qry(0)) {
					//std::cout << "pairing (" << x+1 << ", " << y+1 << ") to (" << i+1 << ", " << j+1 << ")\n";
					mat[i][j].first = 0;
					queue[size++] = i * m + j;
					break;
				}
			}
		}
	}
	for(int on = 0; on < size; on++) {
		int i = queue[on] / m;
		int j = queue[on] % m;
		int t = mat[i][j].first;
		//std::cout << mat[i][j].qry(t+1) << " shouldn't be " << mat[i][j].ori << ", (" << i+1 << ", " << j+1 << ") got time " << t << std::endl;
		for(int dir = 0; dir < 4; dir++) {
			int x = i + dx[dir];
			int y = j + dy[dir];
			if(valid(x, y) && mat[x][y].qry(t+1) == mat[i][j].qry(t+1) && t+1 < mat[x][y].first) {
				mat[x][y].first = t+1;
				queue[size++] = x * m + y;
			}
		}
	}
	while(q--) {
		int i, j;
		long long t;
		std::cin >> i >> j >> t;
		i--;j--;
		std::cout << mat[i][j].qry(t) << '\n';
	}
}