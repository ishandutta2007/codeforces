#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <queue>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 400400;

int c = 1;
int to[ms][26];
int fail[ms];

int addString(const std::string &str) {
	int on = 0;
	for(auto ch : str) {
		if(to[on][ch-'a'] == 0) {
			to[on][ch-'a'] = c++;
		}
		on = to[on][ch-'a'];
	}
	return on;
}

void buildAho() {
	std::queue<int> que;
	que.push(0);
	while(!que.empty()) {
		int on = que.front();
		que.pop();
		for(int i = 0; i < 26; i++) {
			if(to[on][i]) {
				fail[to[on][i]] = on == 0 ? 0 : to[fail[on]][i];
				que.push(to[on][i]);
			} else {
				to[on][i] = to[fail[on]][i];
			}
		}
	}
}

template <class T>
class FenwickTree {
public:
	void init(int mn) {
		this->n = mn;
		bit.assign(n + 1, 0);
	}

	T qry(int x) {
		x = std::min(x, n);
		T ans = 0;
		for(; x > 0; x -= x & -x) {
			ans += bit[x];
		}
		return ans;
	}

	void upd(int x, T v) {
		if(x <= 0) return;
		for(; x <= n; x += x & -x) {
			bit[x] += v;
		}
	}
private:
	int n;
	std::vector<T> bit;
};

std::vector<int> edges[ms];
int in[ms], out[ms], tt = 0;

void dfs(int on) {
	in[on] = tt++;
	for(auto too : edges[on]) {
		dfs(too);
	}
	out[on] = tt;
}

FenwickTree<int> tree;

int ans[ms];
std::vector<std::pair<int, int>> graph2[ms];
std::vector<std::pair<int, int>> qries[ms];

void solve(int on, int st) {
	tree.upd(in[st]+1, 1);
	for(auto e : graph2[on]) {
		solve(e.first, to[st][e.second]);
	}
	for(auto q : qries[on]) {
		ans[q.first] = tree.qry(out[q.second]) - tree.qry(in[q.second]);
	}
	tree.upd(in[st]+1, -1);
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	for(int i = 1; i <= n; i++) {
		int t;
		std::cin >> t;
		char ch;
		int ha;
		if(t == 1) {
			std::cin >> ch;
			ha = 0;
		} else {
			std::cin >> ha >> ch;
		}
		graph2[ha].emplace_back(i, ch-'a');
	}
	int m;
	std::cin >> m;
	for(int i = 0; i < m; i++) {
		int on;
		std::cin >> on;
		std::string str;
		std::cin >> str;
		//std::reverse(str.begin(), str.end());
		qries[on].emplace_back(i, addString(str));
	}
	buildAho();
	for(int i = 1; i < c; i++) {
		edges[fail[i]].push_back(i);
	}
	dfs(0);
	tree.init(c + 10);
	solve(0, 0);
	for(int i = 0; i < m; i++) {
		std::cout << ans[i] << '\n';
	}
}