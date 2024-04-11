#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class DFS {
	int N_, R_;
	vector< vector<int> > G_;
	vector<int> par_, dep_, dep_sub_;

	void DFS_internal(int v) {
		dep_sub_[v] = 0;
		for(auto u : G_[v]) if(par_[u] == -1) {
			par_[u] = v;
			dep_[u] = dep_[v] + 1;
			DFS_internal(u);
			dep_sub_[v] = max(dep_sub_[v], dep_sub_[u] + 1);
		}
	}

public:
	DFS(vector< vector<int> > & G, int R) : N_(G.size()), R_(R), G_(G) {
		par_.resize(N_, -1);
		dep_.resize(N_);
		dep_sub_.resize(N_);
		par_[R_] = R_;
		dep_[R_] = 0;
		DFS_internal(R_);
	}

	int max_dep_id() {
		int ret = -1, max_dep = -1;
		for(int i = 0; i < N_; i++) if(max_dep < dep_[i]) {
			max_dep = dep_[i];
			ret = i;
		}
		return ret;
	}

	int dep(int v) {
		return dep_[v];
	}

	int par(int v) {
		return par_[v];
	}

	int dep_subtree(int v) {
		return dep_sub_[v];
	}
};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N, K;
	cin >> N >> K;
	vector< vector<int> > G(N);
	for(int i = 0; i < N-1; i++) {
		int u, v;
		cin >> u >> v;
		G[--u].push_back(--v);
		G[v].push_back(u);
	}

	DFS DFS0(G, 0);
	int R1 = DFS0.max_dep_id();
	DFS DFS1(G, R1);
	int R2 = DFS1.max_dep_id(); // R2--R3: diameter
	DFS DFS2(G, R2);
	int D = DFS1.dep(R2);

	if(K == 2) {
		cout << "Yes\n";
		for(int i = 0; i < N; i++)
			cout << DFS1.dep(i) % 2 + 1 << ((i == N-1) ? "\n" : " ");
		return 0;
	}

	vector<int> ans(N);
	for(int i = 0; i < N; i++) {
		if(DFS1.dep(i)+DFS2.dep(i)-D == 0) {
			ans[i] = DFS1.dep(i) % K + 1;
			continue;
		}
		int d1 = DFS1.dep_subtree(i) + DFS1.dep(i);
		int d2 = DFS1.dep_subtree(i) + DFS2.dep(i);
		if(min(d1, d2) >= K-1) {
			cout << "No\n";
			return 0;
		}
		if(max(d1, d2) < K-1) { // no path with K vertices
			ans[i] = 1;
			continue;
		}
		if(d1 > d2) ans[i] = DFS1.dep(i) % K + 1;
		else ans[i] = (D + K - DFS2.dep(i)%K) % K + 1;
	}

	cout << "Yes\n";
	for(int i = 0; i < N; i++)
		cout << ans[i] << ((i == N-1) ? "\n" : " ");
}