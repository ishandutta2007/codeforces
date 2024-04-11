#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct Merger {
	int operator() (int a, int b) { return std::min(a, b); }
};

template <class T, class Merger>
class SparseTable {
public:
	void init(std::vector<T> a) {
		int e = 0;
		int n = a.size();
		while((1 << e) / 2 < a.size()) {
			e++;
		}
		table.resize(e, std::vector<T>(n));
		get.assign(n + 1, -1);
		for(int i = 0; i < n; i++) {
			table[0][i] = a[i];
			get[i+1] = get[(i+1)/2] + 1;
		}
		for(int i = 0; i + 1 < e; i++) {
			for(int j = 0; j + (1 << i) < n; j++) {
				table[i+1][j] = merge(table[i][j], table[i][j + (1 << i)]);
			}
		}
	}
	
	T qry(int l, int r) {
		int e = get[r - l];
		return merge(table[e][l], table[e][r - (1 << e)]);
	}
private:
	std::vector<std::vector<T>> table;
	std::vector<int> get;
	Merger merge;
};


struct EulerTourTree {
	void read(int m) {
		std::cin >> n;
		edges.resize(n);
		h.resize(n);
		in.resize(n);
		out.resize(n);
		for(int i = 1; i < n; i++) {
			int p;
			std::cin >> p;
			edges[p-1].push_back(i);
		}
		special.push_back(0);
		while(m--) {
			int x;
			std::cin >> x;
			special.push_back(x-1);
		}
		// init
		h[0] = 0;
		dfs(0);
		table.init(seq);
		//for(auto x : seq) std::cout << x << ' '; std::cout << std::endl;
	}

	void dfs(int on) {
		//std::cout << "in " << on << '\n';
		in[on] = (int) seq.size();
		seq.push_back(h[on]);
		for(auto to : edges[on]) {
			h[to] = 1 + h[on];
			dfs(to);
			seq.push_back(h[on]);
		}
		seq.push_back(h[on]);
		out[on] = (int) seq.size();
		//std::cout << "out " << on << '\n';
	}

	int qry(int u, int v) {
		assert(u < v);
		u = special[u];
		v = special[v];
		//std::cout << "query between " << u << ", " << v << ' ';
		int ans = h[v];
		if(in[v] < in[u]) std::swap(u, v);
		//std::cout << "[" << in[u] << ", " << out[v] << "] ";
		return ans - table.qry(in[u], out[v]);
	}

	int n;
	int c = 0;
	std::vector<std::vector<int>> edges;
	std::vector<int> in, out, h;
	std::vector<int> seq;
	std::vector<int> special;
	SparseTable<int, Merger> table;
};

int dp[1010][1010];
EulerTourTree trees[2];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	int tot = 0;
	for(int i = 0; i < 2; i++) {
		trees[i].read(n);
		tot += trees[i].n - 1;
	}
	for(int i = 0; i < 1010; i++) {
		for(int j = 0; j < 1010; j++) {
			dp[i][j] = 0x3f3f3f3f;
		}
	}
	dp[0][0] = 0;
	for(int sum = 0; sum < n; sum++) {
		for(int i = 0; i <= sum; i++) {
			int j = sum;
			dp[sum+1][j] = std::min(dp[sum+1][j], dp[i][j] + trees[0].qry(i, sum+1));
			dp[j][sum+1] = std::min(dp[j][sum+1], dp[j][i] + trees[1].qry(i, sum+1));
			dp[i][sum+1] = std::min(dp[i][sum+1], dp[i][j] + trees[1].qry(sum, sum+1));
			dp[sum+1][i] = std::min(dp[sum+1][i], dp[j][i] + trees[0].qry(sum, sum+1));
		}
	}
	int ans = 0x3f3f3f3f;
	for(int i = 0; i <= n; i++) {
		ans = std::min(ans, std::min(dp[n][i], dp[i][n]));
	}
	std::cout << tot - ans << '\n';
}