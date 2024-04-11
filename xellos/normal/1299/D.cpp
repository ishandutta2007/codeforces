#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <unordered_map>
using namespace std;

using cat = long long;
cat mod = 1000000007;

void DFS(int R, auto & G, auto & par, auto & top, auto & X, auto & V) {
	if(top[R] != R) for(auto [s,w] : G[R]) if(s != par[R] && par[s] >= 0) {
		if(V[X[R]^X[s]^w]) V[0] = 1;
		V[X[R]^X[s]^w] = 1;
	}
	for(auto [s,w] : G[R]) if(par[s] == -1) {
		top[s] = top[R];
		X[s] = X[R]^w;
		par[s] = R;
		DFS(s, G, par, top, X, V);
	}
}

unordered_map<uint32_t, int> st_m;
vector<uint32_t> st_v;
int st_n = 0;

void generate_states(int pos = 1, uint32_t cur = 1) {
	if(pos == 32) {
		st_v.push_back(cur^1);
		st_m[cur^1] = st_n++;
		return;
	}
	generate_states(pos+1, cur);
	if((cur>>pos)&1) return;
	uint32_t nxt = cur | (1U<<pos);
	bool skip = false;
	for(int i = 0; i < 32; i++) if((cur>>i)&1) {
		int x = i^pos;
		if(x < pos) skip = true;
		nxt |= 1U<<x;
	}
	if(!skip) generate_states(pos+1, nxt);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	generate_states();
	int N, M;
	cin >> N >> M;
	vector< vector< pair<int, int> > > G(N);
	for(int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		G[--u].push_back({--v, w});
		G[v].push_back({u, w});
	}
	vector<int> par(N, -1), top(N, 0), X(N, 0);
	par[0] = 0;
	for(auto e : G[0]) top[e.first] = e.first, par[e.first] = 0, X[e.first] = e.second;
	vector<uint32_t> mask(N);
	for(auto e : G[0]) {
		vector<int> V(32, 0);
		DFS(e.first, G, par, top, X, V);
		uint32_t m = 0;
		for(int i = 0; i < 32; i++) if(V[i]) {
			uint32_t m_nw = m | (1U<<i);
			for(int j = 0; j < 32; j++) if((m>>j)&1) m_nw |= 1U<<(j^i);
			m = m_nw;
		}
		mask[e.first] = m;
	}
	vector< pair<int, int> > P;
	vector<int> W;
	for(auto [a, b] : G[0]) {
		bool has_pair = false;
		for(auto [s, w] : G[a]) if(s != 0) {
			if(par[s] == 0 && s < a) P.push_back({s, a}), W.push_back(w);
			if(par[s] == 0) has_pair = true;
		}
		if(!has_pair) P.push_back({a, -1}), W.push_back(-1);
	}
	vector<cat> dp(st_n, 0), dp_upd(st_n, 0);
	dp[st_m[0]] = 1;
	for(int i = 0; i < (int)P.size(); i++) {
		uint32_t m2;
		int K = 1 + (P[i].second != -1), x = 0;
		if(K == 1) m2 = mask[P[i].first];
		else {
			uint32_t ml = mask[P[i].first], mr = mask[P[i].second];
			m2 = ml | mr;
			uint32_t a = ml;
			for(int j = 0; a; j++, a >>= 1) if(a&1) {
				uint32_t b = mr;
				for(int k = 0; b; k++, b >>= 1) m2 |= (b&1U)<<(j^k);
			}
			x = X[P[i].first]^X[P[i].second]^W[i];
		}
		if(m2&1) continue;
		for(int j = 0; j < st_n; j++) if(!(m2&st_v[j]) && dp[j]) {
			uint32_t m_nw = st_v[j] | m2;
			uint32_t a = st_v[j];
			if(m2) for(int k = 0; a; k++, a >>= 1) if(a&1) {
				uint32_t b = m2;
				for(int l = 0; b; l++, b >>= 1) m_nw |= (b&1U)<<(k^l);
			}
			dp_upd[st_m[m_nw]] += K * dp[j];
			if(x && !((m_nw>>x)&1)) {
				a = m_nw;
				for(int k = 0; a; k++, a >>= 1) m_nw |= (a&1U)<<(k^x);
				m_nw |= (1U<<x);
				if(!(m_nw&1)) dp_upd[st_m[m_nw]] += dp[j];
			}
		}
		for(int j = 0; j < st_n; j++) {
			dp[j] += dp_upd[j] % mod;
			if(dp[j] >= mod) dp[j] -= mod;
			dp_upd[j] = 0;
		}
	}
	cat ans = 0;
	for(int i = 0; i < st_n; i++) ans = (ans + dp[i]) % mod;
	cout << ans << "\n";
}