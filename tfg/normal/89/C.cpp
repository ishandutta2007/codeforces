#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

char mat[5050];
int dir[5050];
int step[5050];

struct DSU {
	int par[5050], mn[5050], mx[5050];
	int getPar(int x) { return x == par[x] ? x : par[x] = getPar(par[x]); }
	void makeUnion(int a, int b) {
		if(getPar(a) == getPar(b)) return;
		//std::cout << "uniting " << a << ", " << b << std::endl;
		a = getPar(a), b = getPar(b);
		if(a == b) return;
		mn[a] = std::min(mn[a], mn[b]);
		mx[a] = std::max(mx[a], mx[b]);
		par[b] = a;
	}
	int getMin(int x) { return mn[getPar(x)]; }
	int getMax(int x) { return mx[getPar(x)]; }

	void init(int n) {
		for(int i = 0; i < n; i++) {
			par[i] = mn[i] = mx[i] = i;
		}
	}
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	for(int i = 0; i < n * m; i++) {
		std::cin >> mat[i];
		if(mat[i] == 'U') { dir[i] = 0; }
		else if(mat[i] == 'R') { dir[i] = 1; }
		else if(mat[i] == 'D') { dir[i] = 2; }
		else if(mat[i] == 'L') { dir[i] = 3; }
		else { dir[i] = -1; }
	}
	DSU dsu[2];
	int ans[] = {-1, -1};
	for(int si = 0; si < n; si++) for(int sj = 0; sj < m; sj++) {
		if(dir[si * m + sj] == -1) continue;
		dsu[0].init(n * m);
		dsu[1].init(n * m);
		int gId = si * m + sj + 1;
		int curDir = 0;
		int i = si, j = sj;
		int curAns = 0;
		//std::cout << "starting at (" << si << ", " << sj << ")" << std::endl;
		while(1) {
			//std::cout << "(" << i << ", " << j << ")" << std::endl;
			int id = i * m + j;
			if(dir[id] != -1 && step[id] != gId) {
				step[id] = gId;
				curDir = dir[id];
				curAns++;
			} else { }
			int ni = i + dx[curDir], nj = j + dy[curDir];
			//std::cout << "next would be " << ni << ", " << nj << std::endl;
			if(0 <= ni && ni < n && 0 <= nj && nj < m) {
				//std::cout << "using dsu " << (curDir & 1) << '\n';
				dsu[curDir & 1].makeUnion(id, ni * m + nj);
				if(curDir == 0 || curDir == 3) {
					int nId = dsu[curDir & 1].getMin(id);
					i = nId / m, j = nId % m;
				} else {
					int nId = dsu[curDir & 1].getMax(id);
					i = nId / m, j = nId % m;
				}
				if(i * m + j == id) break;
			} else {
				break;
			}
		}
		//std::cout << "starting at (" << si << ", " << sj << ") got " << curAns << "\n";
		if(curAns > ans[0]) {
			ans[0] = curAns;
			ans[1] = 0;
		}
		if(curAns == ans[0]) {
			ans[1]++;
		}
	}
	std::cout << ans[0] << ' ' << ans[1] << '\n';
}