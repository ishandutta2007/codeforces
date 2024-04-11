#include <iostream>
#include <vector>
#include <algorithm>

const int ms = 1001000;

int par[ms];
int size[ms];

int getPar(int x) {
	if(par[x] == x) {
		return x;
	} else {
		return par[x] = getPar(par[x]);
	}
}

void makeUnion(int a, int b) {
	a = getPar(a);
	b = getPar(b);
	if(a == b) {
		return;
	}
	size[a] += size[b];
	par[b] = a;
}

struct Entry {
	int x, y, val;
};

long long need;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
bool visit[1001][1001];

int n, m;
void dfs(int x, int y) {
	if(x < 0 || y < 0 || x >= n || y >= m || visit[x][y] || need == 0 || size[getPar(x * m + y)] == 0) return;
	visit[x][y] = true;
	need--;
	for(int i = 0; i < 4; i++) {
		dfs(x + dx[i], y + dy[i]);
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	long long k;
	std::cin >> n >> m >> k;
	std::vector<Entry> points(n * m);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			Entry cur;
			cur.x = i;
			cur.y = j;
			std::cin >> cur.val;
			points[i * m + j] = cur;
			par[i * m + j] = i * m + j;
		}
	}
	std::sort(points.begin(), points.end(), [](Entry a, Entry b) -> bool { return a.val > b.val; });
	for(auto e : points) {
		int x = e.x, y = e.y;
		//std::cout << e.val << ": on pos (" << x << ", " << y << ") got size " << size[getPar(x * m + y)] << "\n";
		size[x * m + y] = 1;
		for(int i = 0; i < 4; i++) {
			int tox = x + dx[i], toy = y + dy[i];
			if(tox >= 0 && toy >= 0 && tox < n && toy < m && size[getPar(tox * m + toy)] > 0) {
				//std::cout << "going to (" << tox << ", " << toy << ")\n";
				makeUnion(x * m + y, tox * m + toy);
			}
		}
		need = k / e.val;
		//std::cout << e.val << ": on pos (" << x << ", " << y << ") got size " << size[getPar(x * m + y)] << "\n";
		if(k % e.val == 0 && need <= size[getPar(x * m + y)]) {
			dfs(x, y);
			std::cout << "YES\n";
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < m; j++) {
					std::cout << (visit[i][j] ? e.val : 0) << (j + 1 == m ? '\n' : ' ');
				}
			}
			return 0;
		}
	}
	std::cout << "NO\n";
}