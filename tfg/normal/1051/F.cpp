#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 100100;

int parr[ms];
int getPar(int x) {
	if(parr[x] == x) {
		return x;
	} else {
		return parr[x] = getPar(parr[x]);
	}
}

bool makeUnion(int a, int b) {
	a = getPar(a);
	b = getPar(b);
	if(a == b) return false;
	parr[b] = a;
	return true;
}

std::vector<std::pair<int, int>> edges[ms];
int c = 0;
std::vector<long long> dists;
long long dist[ms];
int in[ms], out[ms];

void dfs(int on, int par = -1, long long curDist = 0) {
	//std::cout << "entering dfs(" << on << ", " << par << ", " << curDist << ")\n";
	dist[on] = curDist;
	in[on] = c;
	dists.push_back(curDist);
	c++;
	for(auto e : edges[on]) {
		if(e.first == par) continue;
		dfs(e.first, on, curDist + e.second);
		dists.push_back(curDist);
		c++;
	}
	out[on] = c;
	//std::cout << "exiting " << on << ", is (" << in[on] << ", " << out[on] << ")\n";
}

struct Merger {
	long long operator() (long long a, long long b) { return std::min(a, b); }
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

SparseTable<long long, Merger> table;

long long getDist(int u, int v) {
	if(in[u] > in[v]) {
		std::swap(u, v);
	}
	//std::cout << "for qry " << u << ", " << v << " querying on " << in[u] << ", " << in[v] + 1 << "\n";
	return dist[u] + dist[v] - 2 * table.qry(in[u], in[v] + 1);
}

int s = 0;
int uni[ms];
int rev[50];
long long mini[50][50];
long long hmm[50][2];

int getUni(int x) {
	if(uni[x] == -1) {
		rev[s] = x;
		uni[x] = s++;
	}
	return uni[x];
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	for(int i = 0; i < n; i++) {
		parr[i] = i;
		uni[i] = -1;
	}
	for(int i = 0; i < 50; i++) {
		for(int j = 0; j < 50; j++) {
			mini[i][j] = 1e16;
		}
	}
	while(m--) {
		int u, v, co;
		std::cin >> u >> v >> co;
		u--;v--;
		if(!makeUnion(u, v)) {
			mini[getUni(u)][getUni(v)] = std::min(mini[getUni(u)][getUni(v)], (long long) co);
			mini[getUni(v)][getUni(u)] = std::min(mini[getUni(v)][getUni(u)], (long long) co);
		} else {
			edges[u].emplace_back(v, co);
			edges[v].emplace_back(u, co);
		}
	}
	dfs(0);
	table.init(dists);
	for(int i = 0; i < s; i++) {
		for(int j = 0; j < s; j++) {
			mini[i][j] = std::min(mini[i][j], getDist(rev[i], rev[j]));
		}
	}
	for(int k = 0; k < s; k++) {
		for(int i = 0; i < s; i++) {
			for(int j = 0; j < s; j++) {
				mini[i][j] = std::min(mini[i][j], mini[i][k] + mini[k][j]);
			}
		}
	}
	/*for(int i = 0; i < s; i++) {
		std::cout << rev[i] << (i + 1 == s ? '\n' : ' ');
	}
	std::cout << "--------------------\n";
	for(int i = 0; i < s; i++) {
		for(int j = 0; j < s; j++) {
			std::cout << mini[i][j] << (j + 1 == s ? '\n' : ' ');
		}
	}*/
	std::cin >> m;
	while(m--) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		long long ans = getDist(u, v);
		for(int i = 0; i < s; i++) {
			hmm[i][0] = getDist(u, rev[i]);
			hmm[i][1] = getDist(v, rev[i]);
		}
		for(int i = 0; i < s; i++) {
			for(int j = 0; j < s; j++) {
				ans = std::min(ans, hmm[i][0] + mini[i][j] + hmm[j][1]);
			}
		}
		std::cout << ans << '\n';
	}
}