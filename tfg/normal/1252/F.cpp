#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cstring>
#include <algorithm>
#include <cassert>
#include <functional>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 505;

struct Range {
	int l, r;
	long long c;
	Range() {}
	Range(int a, int b, long long cc) : l(a), r(b), c(cc) {}
};

std::vector<Range> cols[ms], rows[ms];
long long dp[ms][ms], pos[ms][ms];

template<class T = int>
struct Bit2D {
public:
	void init(std::vector<std::pair<T, T>> pts) {
		for(auto &a : pts) {
			a.first = -a.first;
		}
		std::sort(pts.begin(), pts.end());
		for(auto &a : pts) {
			if(ord.empty() || a.first != ord.back()) {
				ord.push_back(a.first);
			}
		}
		fw.resize(ord.size() + 1);
		coord.resize(fw.size());
		for(auto &a : pts) {
			std::swap(a.first, a.second);
		}
		std::sort(pts.begin(), pts.end());
		for(auto &a : pts) {
			std::swap(a.first, a.second);
			for(int on = std::upper_bound(ord.begin(), ord.end(), a.first) - ord.begin(); on < fw.size(); on += on & -on) {
				if(coord[on].empty() || coord[on].back() != a.second) {
					coord[on].push_back(a.second);
				}
			}
		}
		for(int i = 0; i < fw.size(); i++) {
			fw[i].assign(coord[i].size() + 1, 0);
		}
	}

	void upd(T x, T y, T v) {
		//std::cout << "updating " << x << ", " << y << std::endl;
		//y = -y;
		x = -x;
		for(int xx = std::upper_bound(ord.begin(), ord.end(), x) - ord.begin(); xx < fw.size(); xx += xx & -xx) {
			for(int yy = std::upper_bound(coord[xx].begin(), coord[xx].end(), y) - coord[xx].begin(); yy < fw[xx].size(); yy += yy & -yy) {
				fw[xx][yy] += v;
				break;
			}
		}
	}

	void init2() {
		for(int i = 1; i < fw.size(); i++) {
			for(int j = 1; j < (int) fw[i].size(); j++) {
				fw[i][j] += fw[i][j-1];
			}
		}
	}

	T qry(T x, T y) {
		//std::cout << "querying " << x << ", " << y << std::endl;
		//y = -y;
		x = -x;
		T ans = 0;
		for(int xx = std::upper_bound(ord.begin(), ord.end(), x) - ord.begin(); xx > 0; xx -= xx & -xx) {
			for(int yy = std::upper_bound(coord[xx].begin(), coord[xx].end(), y) - coord[xx].begin(); yy > 0; yy -= yy & -yy) {
				ans += fw[xx][yy];
				break;
			}
		}
		return ans;
	}
private:
	std::vector<int> ord;
	std::vector<std::vector<T>> fw;
	std::vector<std::vector<int>> coord;
};

Bit2D<long long> row[ms], col[ms];

struct Node {
	std::function<long long(int)> line;
	Node *left, *right;
};

long long INF(int x) { return 1e18; }

Node buffer[4*ms*ms];
int bpt = 0;

Node* chtRow[ms];
Node* chtCol[ms];

Node* createLCT(int l, int r) {
	Node* ans = &buffer[bpt++];
	ans->line = INF;
	if(l + 1 != r) {
		int mid = (l + r) / 2;
		ans->left = createLCT(l, mid);
		ans->right = createLCT(mid, r);
	} else {
		ans->left = ans->right = NULL;
	}
	return ans;
}

void updLine(Node* node, int l, int r, int x, std::function<long long(int)> f) {
	int mid = (l + r) / 2;
	bool lef = f(l) < node->line(l);
	bool md = f(mid) < node->line(mid);
	if(md) {
		std::swap(f, node->line);
	}
	if(r - l == 1) {
		return;
	} else if(lef != md) {
		updLine(node->left, l, mid, x, f);
	} else {
		updLine(node->right, mid, r, x, f);
	}
}

long long qry(Node* node, int l, int r, int x) {
	if(r - l == 1) {
		return node->line(x);
	} else {
		int mid = (l + r) / 2;
		if(x >= mid) {
			return std::min(node->line(x), qry(node->right, mid, r, x));
		} else {
			return std::min(node->line(x), qry(node->left, l, mid, x));
		}
	}
}

int32_t main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	int q;
	std::cin >> q;
	memset(dp, 0x3f, sizeof dp);
	dp[0][0] = 0;
	while(q--) {
		int x, y, d, t, e;
		std::cin >> x >> y >> d >> t >> e;
		bool can[4];
		can[0] = (x + y) % 4 == t % 4 && (x+y) >= t;
		can[1] = (x + d + y - d) % 4 == (t + 1) % 4 && (x+d+y-d) >= t+1;
		can[2] = (x + d + y) % 4 == (t + 2) % 4 && (x+d+y) >= t+2;
		can[3] = (x + y + d) % 4 == (t + 3) % 4 && (x+y+d) >= t+3;
		if(can[0]) {
			pos[x][y] += e;
		}
		if(can[1]) {
			pos[x+d][y-d] += e;
		}
		if(can[2]) {
			pos[x+d][y] += e;
		}
		if(can[3]) {
			pos[x][y+d] += e;
		}
		if(can[0] && can[3]) {
			rows[x].emplace_back(y, y + d, -e);
			//row[x][y][y+d] -= e;
		}
		//std::cout << "got (" << can[0] << ", " << can[1] << ", " << can[2] << ", " << can[3] << ")\n";
		if(can[0] && can[2]) {
			//col[y][x][x+d] -= e;
			cols[y].emplace_back(x, x + d, -e);
		}
		if(can[1] && can[2]) {
			//row[x+d][y-d][y] -= e;
			rows[x+d].emplace_back(y-d, y, -e);
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(pos[i][j]) {
				//std::cout << "at pos " << i << ", " << j << " has " << pos[i][j] << '\n';
				rows[i].emplace_back(j-1, j, pos[i][j]);
				cols[j].emplace_back(i-1, i, pos[i][j]);
			}
		}
	}
	for(int i = 0; i < n; i++) {
		chtRow[i] = createLCT(0, m);
		std::vector<std::pair<long long, long long>> ranges;
		for(auto r : rows[i]) {
			ranges.emplace_back(r.l, r.r);
		}
		row[i].init(ranges);
		for(auto r : rows[i]) {
			row[i].upd(r.l, r.r, r.c);
			//std::cout << "at row " << i << " got (" << r.l << ", " << r.r << ", " << r.c << ") got " << row[i].qry(r.l, r.r) << '\n';
		}
		rows[i].clear();
		row[i].init2();
	}
	for(int i = 0; i < m; i++) {
		chtCol[i] = createLCT(0, n);
		std::vector<std::pair<long long, long long>> ranges;
		for(auto r : cols[i]) {
			ranges.emplace_back(r.l, r.r);
		}
		col[i].init(ranges);
		for(auto r : cols[i]) {
			col[i].upd(r.l, r.r, r.c);
			//std::cout << "at col " << i << " got (" << r.l << ", " << r.r << ", " << r.c << ") got " << col[i].qry(r.l, r.r) << '\n';
		}
		cols[i].clear();
		col[i].init2();
	}
	auto getEvalRow = [&](int i, int j1, int j2) {
		//std::cout << "eval for row " << i << ", " << j1 << " to " << j2 << " is (" << dp[i][j1] << " + " << col[i].qry(j1, j2) << ")\n";
		return dp[i][j1] + row[i].qry(j1, j2);
	};
	auto getEvalCol = [&](int i, int j1, int j2) {
		//std::cout << "eval for row " << i << ", " << j1 << " to " << j2 << " is (" << dp[i][j1] << " + " << col[i].qry(j1, j2) << ")\n";
		return dp[j1][i] + col[i].qry(j1, j2);
	};
	dp[0][0] = pos[0][0];
	auto workRow = [&](int i, int j) {
		std::function<long long(int)> f = [&, ii=i, jj=j](int x) {
			if(x < jj) {
				return -1LL-jj;
			}
			return (dp[ii][jj] + row[ii].qry(jj, x)) * ms + (ms-1 - jj);
		};
		updLine(chtRow[i], 0, m, -1, f);
	};
	auto workCol = [&](int i, int j) {
		std::function<long long(int)> f = [&, ii=i, jj=j](int x) {
			if(x < ii) {
				return -1LL-ii;
			}
			return (dp[ii][jj] + col[jj].qry(ii, x)) * ms + (ms-1 - ii);
		};
		updLine(chtCol[j], 0, n, -1, f);
	};
	auto work = [&](int i, int j) {
		//std::cout << "working for " << i << ", " << j << "\n";
		workRow(i, j);
		workCol(i, j);
	};
	work(0, 0);
	for(int d = 1; d <= n + m; d++) {
		//break;
		for(int i = 0; i < n; i++) {
			int j = d - i;
			if(j < 0 || j >= m) {
				continue;
			}
			//std::cout << "got (" << qry(chtRow[i], 0, m, j) / ms << ", " << qry(chtCol[j], 0, n, i) / ms << ")\n";
			dp[i][j] = std::min(qry(chtRow[i], 0, m, j), qry(chtCol[j], 0, n, i)) / ms;
			work(i, j);
		}
	}
	std::cout << dp[n-1][m-1] << '\n';
}