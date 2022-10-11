#include <iostream>
#include <bitset>
#include <algorithm>
#include <vector>
#include <queue>

typedef long long ll;

const int ms = 150;

struct Flight {
	int from, to, need;

	void read() {
		std::cin >> from >> to >> need;
		from--;
		to--;
	}
};

bool operator < (Flight a, Flight b) {
	return a.need < b.need;
}

struct Matrix {
	std::bitset<ms> col[ms], row[ms];

	Matrix(bool pos = false) {
		for(int i = 0; i < ms; i++) {
			col[i].reset();
			row[i].reset();
		}
		if(pos) {
			for(int i = 0; i < ms; i++) {
				col[i][i] = row[i][i] = true;
			}
		}
	}

	Matrix operator * (Matrix &a) {
		Matrix ans;
		for(int i = 0; i < ms; i++) {
			for(int j = 0; j < ms; j++) {
				ans.row[i][j] = ans.col[j][i] = (row[i] & a.col[j]).count() > 0;
			}
		}
		return ans;
	}
};

int n, m;
std::bitset<ms> pos;
std::vector<int> edges[ms];

void skip(Matrix base, ll e) {
	Matrix ans(true);
	for(; e > 0; e /= 2) {
		if(e & 1) {
			ans = ans * base;
		}
		base = base * base;
	}
	/*for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			std::cout << ans.row[i][j] << ' ';
		}
		std::cout << '\n';
	}*/
	std::bitset<ms> nxt;
	for(int i = 0; i < ms; i++) {
		nxt[i] = (ans.col[i] & pos).count() > 0;
	}
	pos = nxt;
}

Flight f[ms];

int step[ms];
int cur_step = 0;
int dist[ms];

ll bfs(int s) {
	if(pos[s]) {
		return 0;
	}
	std::queue<int> q;
	q.push(s);
	cur_step++;
	dist[s] = 0;
	step[s] = cur_step;
	while(!q.empty()) {
		int on = q.front();
		q.pop();
		for(auto e : edges[on]) {
			if(step[e] != cur_step) {
				step[e] = cur_step;
				q.push(e);
				dist[e] = dist[on] + 1;
				if(pos[e]) {
					return dist[e];
				}
			}
		}
	}
	return 2e18;
}

int main() {
	std::cin >> n;
	std::cin >> m;
	pos[0] = true;
	for(int i = 0; i < m; i++) {
		f[i].read();
	}
	std::sort(f, f + m);
	if(f[0].need > 0) {
		std::cout << "Impossible\n";
		return 0;
	}
	ll cur_ans = 0;
	ll cur_t = 0;
	Matrix base;
	for(int i = 0; i < m;) {
		int j = i;
		//std::cout << "stretching from i == " << i << "\n";

		//for(int i = 0; i < n; i++) {
		//	if(pos[i]) std::cout << "is currently on pos " << i << "\n";
		//}
		while(j < m && f[i].need == f[j].need) {
			//std::cout << "got to j == " << j + 1 << "\n";
			edges[f[j].to].push_back(f[j].from);
			//std::cout << "included edge " << f[j].from << ", " << f[j].to << ", needing " << f[j].need << "\n";
			base.row[f[j].from][f[j].to] = base.col[f[j].to][f[j].from] = true;
			j++;
		}
		//std::cout << "got window [" << i << ", " << j << "[\n";
		ll nxt_t = j == m ? ll(1e18) : f[j].need;
		ll time_skip = nxt_t - cur_t;
		ll shortest = bfs(n - 1);
		if(shortest <= time_skip) {
			std::cout << cur_ans + shortest << '\n';
			return 0;
		}
		skip(base, time_skip);
		//for(int i = 0; i < n; i++) {
		//	if(pos[i]) std::cout << "is currently on pos " << i << "\n";
		//}
		i = j;
		cur_t = nxt_t;
		cur_ans += time_skip;
	}
	std::cout << "Impossible\n";
}