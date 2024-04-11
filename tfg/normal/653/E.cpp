#include <iostream>
#include <set>
#include <queue>
#include <cstdio>

const int ms = 300300;

std::set<int> forb[ms];
int par[ms];
bool got[ms];

int main() {
	int n, m, k;
	std::cin >> n >> m >> k;
	std::set<int> verts;
	for(int i = 1; i < n; i++) {
		verts.insert(i);
	}
	for(int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		u--;v--;
		forb[u].insert(v);
		forb[v].insert(u);
	}
	if(n - 1 - (int)forb[0].size() < k) {
		std::cout << "impossible\n";
		return 0;
	}
	for(int i = 1; i < n; i++) {
		if(!verts.count(i)) continue;
		std::queue<int> q;
		q.push(i);
		while(!q.empty()) {
			int on = q.front();
			q.pop();
			par[on] = i;
			std::vector<int> hmm;
			for(auto to : verts) {
				if(!forb[on].count(to)) {
					hmm.push_back(to);
					q.push(to);
				}
			}
			for(auto v : hmm) {
				verts.erase(v);
			}
		}
	}
	bool valid = true;
	for(int i = 1; i < n; i++) {
		//std::cout << par[i] << (i + 1 == n ? '\n' : ' ');
		if(!forb[0].count(i)) {
			//std::cout << "from 0 to " << i << std::endl;
			got[par[i]] = true;
		}
	}
	for(int i = 1; i < n; i++) {
		k -= got[i] ? 1 : 0;
		if(par[i] == i) {
			//std::cout << "on " << i << " is " << got[i] << std::endl;
			valid = valid && got[i];
		}
	}
	std::cout << (k < 0 || !valid ? "impossible\n" : "possible\n");
}