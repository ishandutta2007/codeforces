#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define ff first
#define ss second
using namespace std;

using cat = long long;

cat pw(cat a, cat e, cat mod) {
	if(e <= 0) return 1;
	cat x = pw(a, e/2, mod);
	x = x * x % mod;
	if(e&1) x = x * a % mod;
	return x;
}

void DFS(int R, int par, auto & G, auto & I) {
	I[R].ss = I[R].ff+1;
	for(auto s : G[R]) if(par != s) {
		I[s].ff = I[R].ss;
		DFS(s, R, G, I);
		I[R].ss = I[s].ss;
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N, Q;
	cin >> N >> Q;
	cat mod = 998244353;
	cat inv = pw(N, mod-2, mod);
	vector< vector<int> > G(N);
	for(int i = 0; i < N-1; i++) {
		int u, v;
		cin >> u >> v;
		G[--u].push_back(--v);
		G[v].push_back(u);
	}
	vector< pair<int, int> > I(N, {0, 0});
	DFS(0, 0, G, I);
	constexpr int K = 500;
	vector<int> sz(N), par(N, 0);
	for(int i = 0; i < N; i++) sz[I[i].ff] = I[i].ss-I[i].ff;
	for(int i = 0; i < N; i++)
		for(auto s : G[i]) if(sz[I[s].ff] > sz[I[i].ff]) par[I[i].ff] = I[s].ff;
	vector< vector<int> > subtree(N);
	for(int i = 0; i < N; i++) {
		int v = I[i].ff;
		if((int)G[i].size() - (i > 0) >= K) {
			subtree[v].resize(N);
			for(auto s : G[i]) if(sz[I[s].ff] < sz[v])
				for(int j = I[s].ff; j < I[s].ss; j++) subtree[v][j] = I[s].ss-I[s].ff;
		}
		else {
			for(auto s : G[i]) if(sz[I[s].ff] < sz[v])
				subtree[v].push_back(I[s].ff);
			sort(begin(subtree[v]), end(subtree[v]));
		}
	}
	for(int q = 0; q < Q; q++) {
		static vector<int> upd;
		static vector<cat> val(N, 0), add(N, 0);
		int tp, v;
		cin >> tp >> v;
		v = I[v-1].ff;
		if(tp == 2) {
			cat ans = val[v], ans_inv = 0;
			for(int u : upd) {
				if(v < u || v >= u+sz[u]) ans_inv += add[u] * sz[u];
				else if(v == u) ans += add[u];
				else {
					ans += add[u];
					if((int)subtree[u].size() == N) ans_inv -= add[u] * subtree[u][v];
					else {
						auto it = upper_bound(begin(subtree[u]), end(subtree[u]), v);
						ans_inv -= add[u] * sz[*(--it)];
					}
				}
			}
			ans = (ans + ans_inv % mod * inv) % mod;
			if(ans < 0) ans += mod;
			cout << ans << "\n";
			continue;
		}
		cat d;
		cin >> d;
		if(!add[v] && d) upd.push_back(v);
		add[v] += d;
		if(add[v] > mod) add[v] -= mod;
		if((int)upd.size() >= K) {
			upd.clear();
			static vector<cat> add_subtree(N, 0);
			memset(&(add_subtree[0]), 0, sizeof(cat)*N);
			cat add_tot = 0;
			for(int i = 0; i < N; i++) {
				if(add[i]) {
					d = add[i] * inv % mod;
					add_tot += d * sz[i];
					add_subtree[i] += add[i] - d * sz[i];
				}
				if(i && add[par[i]])
					add_subtree[i] -= add[par[i]] * inv % mod * sz[i];
			}
			memset(&(add[0]), 0, sizeof(cat)*N);
			for(int i = 0; i < N; i++) {
				if(i) add_subtree[i] += add_subtree[par[i]];
				val[i] = (val[i] + add_tot + add_subtree[i]) % mod;
			}
		}
	}
}