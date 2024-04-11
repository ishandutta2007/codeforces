#include <bits/stdc++.h>

using namespace std;

const int N = 107;

int n, k;
bool used[N];
int lvl[N], p[N];
vector <int> G[N];

int get_end() {
	int best = 1;
	for(int i = 2; i <= n; ++i)
		if(lvl[i] < k and lvl[i] > lvl[best])
			best = i;
	return best;
}

void solve() {
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; ++i)
		G[i].clear(), used[i] = false;
	
	lvl[1] = 0;
	for(int i = 2; i <= n; ++i) {
		scanf("%d", &p[i]);
		lvl[i] = lvl[p[i]] + 1;
		G[p[i]].push_back(i);
	}
	
	int end_vertex = get_end();
	used[end_vertex] = true;

	queue <int> Q;
	Q.push(end_vertex);
	vector <int> path = { end_vertex };
	
	while(end_vertex != 1) {
		end_vertex = p[end_vertex];
		path.push_back(end_vertex);
		
		used[end_vertex] = true;
		Q.push(end_vertex);
	}
	
	reverse(path.begin(), path.end());
	k -= path.size();
	
	while(!Q.empty()) {
		int u = Q.front();
		Q.pop();

		int occ = -1;
		for(int i = 0; i < (int)path.size(); ++i)
			if(path[i] == u) {
				occ = i;
				break;
			}
		
		assert(occ != -1);
		auto occ_it = path.begin() + occ + 1;
		for(auto v: G[u]) {
			if(used[v])
				continue;
			
			if(k == 0)
				break;
			
			path.insert(occ_it, u);
			occ_it = path.begin() + occ + 1;

			path.insert(occ_it, v);
			occ_it = path.begin() + occ + 1;
			
			Q.push(v);
			k--;
		}
		
		if(k == 0)
			break;
	}
	
	printf("%ld\n", path.size() - 1);
	for(auto v: path)
		printf("%d ", v);
	puts("");
}

int main() {
	int cases;
	scanf("%d", &cases);
	
	while(cases--)
		solve();
	return 0;
}