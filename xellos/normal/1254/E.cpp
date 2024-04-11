#include <iostream>
#include <vector>
using namespace std;

using cat = long long;

void DFS(int R, auto & G, auto & E, auto & par, auto & dep) {
	for(auto e : G[R]) if(par[E[e]] == -1) {
		int v = E[e];
		par[v] = e^1;
		dep[v] = dep[R]+1;
		DFS(v, G, E, par, dep);
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	vector<int> E(2*(N-1));
	vector< vector<int> > G(N);
	for(int i = 0; i < N-1; i++) {
		cin >> E[2*i] >> E[2*i+1];
		G[--E[2*i]].push_back(2*i+1);
		G[--E[2*i+1]].push_back(2*i);
	}
	vector<int> par(N, -1), dep(N, 0);
	par[0] = 0;
	DFS(0, G, E, par, dep);
	vector<int> E_sum(2*(N-1), 0), E_deg(2*(N-1), 0);
	vector<int> E_next(2*(N-1), -1), E_prev(2*(N-1), -1), E_in(N, -1), E_out(N, -1);
	for(int i = 0; i < N; i++) {
		int u = i, v;
		cin >> v;
		if(!(v--)) continue;
		if(u == v) {
			cout << "0\n";
			return 0;
		}
		vector<int> E_seq, E_seq_r;
		while(dep[u] > dep[v]) {
			E_seq.push_back(par[u]);
			u = E[par[u]];
		}
		while(dep[u] < dep[v]) {
			E_seq_r.push_back(par[v]^1);
			v = E[par[v]];
		}
		while(u != v) {
			E_seq.push_back(par[u]);
			E_seq_r.push_back(par[v]^1);
			u = E[par[u]];
			v = E[par[v]];
		}
		for(int j = (int)E_seq_r.size()-1; j >= 0; j--) E_seq.push_back(E_seq_r[j]);
		for(int j = 0; j < (int)E_seq.size(); j++) if(E_sum[E_seq[j]]++) {
			cout << "0\n";
			return 0;
		}
		for(int j = 1; j < (int)E_seq.size(); j++) {
			E_next[E_seq[j-1]] = E_seq[j], E_deg[E_seq[j-1]]++;
			E_prev[E_seq[j]] = E_seq[j-1], E_deg[E_seq[j]]++;
		}
		if(E_in[E[E_seq.back()]] != -1 || E_out[E[E_seq[0]^1]] != -1) {
			cout << "0\n";
			return 0;
		}
		E_in[E[E_seq.back()]] = E_seq.back();
		E_out[E[E_seq[0]^1]] = E_seq[0];
	}
	for(int i = 0; i < N; i++) if(E_in[i] != -1 && E_out[i] != -1) {
		if((E_in[i]^E_out[i]) == 1 && (int)G[i].size() > 1) {
			cout << "0\n";
			return 0;
		}
		E_next[E_in[i]] = E_out[i], E_deg[E_in[i]]++;
		E_prev[E_out[i]] = E_in[i], E_deg[E_out[i]]++;
	}
	for(int i = 0; i < 2*(N-1); i++) if(E_deg[i] > 2 || (E_deg[i] == 2 && (E_prev[i] == -1 || E_next[i] == -1))) {
		cout << "0\n";
		return 0;
	}
	vector<char> vis(2*(N-1), 0);
	for(int i = 0; i < 2*(N-1); i++) if(E_deg[i] == 1 && E_prev[i] == -1) {
		int cur = i;
		while(cur != -1) {
			vis[cur] = 1;
			cur = E_next[cur];
		}
	}
	for(int i = 0; i < 2*(N-1); i++) if(E_deg[i] == 2 && !vis[i]) {
		cout << "0\n";
		return 0;
	}
	cat ans = 1, mod = 1000000007;
	vector<cat> fac(N+1, 1);
	for(int i = 2; i <= N; i++) fac[i] = fac[i-1] * (i-1) % mod;
	for(int i = 0; i < N; i++) {
		int paths = 0;
		for(auto e : G[i]) paths += 1-E_sum[e];
		if(E_in[i] == -1) paths++;
		ans = ans * fac[paths] % mod;
	}
	cout << ans << "\n";
}