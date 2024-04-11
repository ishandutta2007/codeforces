#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

const int ms = 100100;

int n, m;

std::vector<int> edges[ms];
bool visit[ms];
std::vector<int> cur;

void dfs(int on) {
	//std::cout << "visiting " << on << std::endl;
	visit[on] = true;
	cur.push_back(on);
	for(auto to : edges[on]) {
		if(!visit[to]) {
			dfs(to);
		}
	}
}

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

void reposition(std::vector<int> &a) {
	//std::cout << "repositioning size " << a.size() << std::endl;
	if(a.size() == 4) {
		std::swap(a[1], a[2]);
	} else if(a.size() > 4) {
		int v = 2;
		while(gcd(a.size(), v) != 1) {
			v++;
		}
		//std::cout << "v is " << v << std::endl;
		std::vector<int> p(a.size());
		for(int i = 0; i < a.size(); i++) {
			p[i] = a[(long long) i * v % a.size()];
		}
		p.swap(a);
	}
}

int mat[50][50];
std::vector<std::pair<int, int>> bf_edge, ans;
int deg[50];

bool bf(int on = 0) {
	if(m == ans.size()) {
		return true;
	}
	if(on == bf_edge.size()) {
		return false;
	}
	int u = bf_edge[on].first, v = bf_edge[on].second;
	if(deg[u] < 2 && deg[v] < 2) {
		deg[u]++, deg[v]++;
		ans.emplace_back(u, v);
		if(bf(on + 1)) return true;
		ans.pop_back();
		deg[u]--, deg[v]--;
	}
	return bf(on + 1);
}


int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::cin >> n >> m;
	if(n <= 8) {
		for(int i = 0; i < m; i++) {
			int u, v;
			std::cin >> u >> v;
			mat[u][v] = mat[v][u] = 1;
		}
		for(int u = 1; u <= n; u++) {
			for(int v = u + 1; v <= n; v++) {
				if(!mat[u][v]) {
					bf_edge.emplace_back(u, v);
				}
			}
		}
		srand(time(NULL));
		std::random_shuffle(bf_edge.begin(), bf_edge.end());
		if(bf(0)) {
			for(auto e : ans) {
				std::cout << e.first << ' ' << e.second << std::endl;
			}
		} else {
			std::cout << "-1\n";
		}
	} else {
		for(int i = 0; i < m; i++) {
			int u, v;
			std::cin >> u >> v;
			u--;v--;
			edges[u].push_back(v);
			edges[v].push_back(u);
		}
		int cmp = 0;
		std::vector<std::vector<int>> v;
		for(int i = 0; i < n; i++) {
			if(!visit[i] && edges[i].size() == 1) {
				dfs(i);
				v.push_back(cur);
				cur.clear();
				cmp++;
			}
		}
		for(int i = 0; i < n; i++) {
			if(!visit[i]) {
				dfs(i);
				v.push_back(cur);
				cur.clear();
				cmp++;
			}
		}
		std::sort(v.begin(), v.end(), [](const std::vector<int> &a, const std::vector<int> &b) { return a.size() > b.size();});
		reposition(v[0]);
		std::vector<std::vector<int>> lst(v[0].size() + 1);
		int on = v[0].size() == 4 ? 2 : 1;
		for(int i = 1; i < v.size(); i++) {
			for(auto e : v[i]) {
				lst[on].push_back(e);
				on = (on + 1) % lst.size();
			}
		}
		std::vector<int> p;
		cmp = 0;
		for(auto hmm1 : lst) {
			for(auto hmm2 : hmm1) {
				p.push_back(hmm2);
			}
			if(cmp < v[0].size()) {
				p.push_back(v[0][cmp++]);
			}
		}
		std::vector<std::pair<int, int>> pos;
		for(int i = 0; i < p.size(); i++) {
			//std::cout << p[i] + 1 << (i + 1 == p.size() ? '\n' : ' ');
			int u = p[i], v = p[(i+1) % p.size()];
			if(u == v) continue;
			//std::cout << "testing (" << u + 1 << ", " << v + 1 << ")\n";
			if(std::find(edges[u].begin(), edges[u].end(), v) == edges[u].end()) {
				pos.emplace_back(u, v);
				//std::cout << "got\n";
			}
		}
		while(pos.size() > m) {
			pos.pop_back();
		}
		if(pos.size() == m) {
			for(auto e : pos) {
				std::cout << e.first + 1 << ' ' << e.second + 1 << '\n';
			}
		} else {
			std::cout << "-1\n";
		}
	}
}