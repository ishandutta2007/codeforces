#include <iostream>
#include <vector>
#include <unordered_set>
#define ff first
#define ss second
using namespace std;

using cat = long long;

class Solver {
	struct state {
		int e_top, e_bot, e_mid;
	};

	void precompute(int e, auto & next) {
		if(sz[e] != -1) return;
		sz[e] = 1;
		int v = E[e].ss;
		for(auto p : G[v]) if(p != (e^1)) {
			precompute(p, next);
			sz[e] += sz[p];
		}
		if((int)G[v].size() == 2) {
			next[e] = G[v][0]+G[v][1]-(e^1);
			is_path[e] = is_path[next[e]];
		}
		if((int)G[v].size() == 1) {
			next[e] = E.size();
			is_path[e] = 1;
		}
	}

	inline int get_next_edge(state & st) {
		if(st.e_top == st.e_bot) // == E.size()
			return E.size();
		if(st.e_top == (int)E.size()) return (sz[st.e_bot]%2 ? -1 : st.e_bot);
		if(st.e_bot == (int)E.size()) return (sz[st.e_top]%2 ? -1 : st.e_top);
		if(sz[st.e_top]%2 != sz[st.e_bot]%2) return -1;
		if(!is_path[st.e_top] && !is_path[st.e_bot]) return -1;
		int min_dep, cur;
		if(is_path[st.e_top] && is_path[st.e_bot]) {
			if(sz[st.e_top] == sz[st.e_bot]) return E.size();
			min_dep = min(sz[st.e_top], sz[st.e_bot]);
			cur = (sz[st.e_top] > sz[st.e_bot]) ? st.e_top : st.e_bot;
		}
		else if(is_path[st.e_top]) min_dep = sz[st.e_top], cur = st.e_bot;
		else /*if(is_path[st.e_bot])*/ min_dep = sz[st.e_bot], cur = st.e_top;
		for(int k = 0; min_dep; k++, min_dep >>= 1) if(min_dep&1) {
			cur = next_down[k][cur];
			if(cur == -1) return -1;
		}
		return cur;
	}

	void find_paired_states(int e, auto & P) {
		auto [u, v] = E[e];
		for(int i = 0; i <= (int)G[u].size(); i++) for(int j = 0; j <= (int)G[v].size(); j++) {
			if(i == 3 || j == 3) continue;
			if(i != (int)G[u].size() && G[u][i] == e) continue;
			if(j != (int)G[v].size() && G[v][j] == (e^1)) continue;
			int e_top_next = (i == (int)G[u].size()) ? E.size() : G[u][i];
			int e_bot_next = (j == (int)G[v].size()) ? E.size() : G[v][j];
			state st = {e_top_next, e_bot_next, e};
			int e_next = get_next_edge(st);
			if(e_next != -1) P[e_next].push_back(st);
		}
	}

	inline state get_inv_state(state & st) {
		state ret = {E.size(), E.size(), st.e_mid};
		auto [u, v] = E[st.e_mid];
		for(auto p : G[u]) if(p != st.e_mid && p != st.e_top) ret.e_top = p;
		for(auto p : G[v]) if(p != (st.e_mid^1) && p != st.e_bot) ret.e_bot = p;
		return ret;
	}

	vector< pair<int, int> > E;
	vector< vector<int> > G;
	vector<int> sz, is_path;
	vector<int> next_down[20];

public:
	Solver(int N) : E(2*(2*N-1)), G(2*N), sz(2*(2*N-1), -1), is_path(2*(2*N-1), 0) {
		for(int i = 0; i < 2*N-1; i++) {
			int u, v;
			cin >> u >> v;
			G[--u].push_back(2*i);
			G[--v].push_back(2*i+1);
			E[2*i] = {u, v};
			E[2*i+1] = {v, u};
		}
		for(int i = 0; i < 20; i++) next_down[i] = vector<int>(2*(2*N-1), -1);
	}

	cat solve() {
		int N = G.size()/2;
		for(int i = 0; i < 2*N; i++) if((int)G[i].size() > 3) return 0;

		for(int i = 0; i < 2*(2*N-1); i++) precompute(i, next_down[0]);
		for(int k = 1; k < 18; k++) for(int i = 0; i < 2*(2*N-1); i++) {
			if(next_down[k-1][i] == -1) continue;
			if(next_down[k-1][i] == E.size()) next_down[k][i] = E.size();
			else next_down[k][i] = next_down[k-1][next_down[k-1][i]];
		}

		vector< vector<state> > prev_states(2*(2*N-1)+1); // only 'out' states
		for(int i = 0; i < 2*(2*N-1); i++) find_paired_states(i, prev_states);

		vector< vector< pair<int, state> > > state_sz(2*N+1);
		for(int i = 0; i <= 2*(2*N-1); i++) for(int j = 0; j < (int)prev_states[i].size(); j++) {
			int cur_sz = 2;
			state st = prev_states[i][j];
			if(st.e_top != (int)E.size()) cur_sz += sz[st.e_top];
			if(st.e_bot != (int)E.size()) cur_sz += sz[st.e_bot];
			state_sz[cur_sz].push_back({i, st});
		}

		vector<cat> dp(2*(2*N-1)+1, 0);
		dp[2*(2*N-1)] = 1;
		cat ans = 0, mod = 1000000007;
		for(int i = 0; i <= 2*N; i++) for(auto p : state_sz[i]) {
			cat val = dp[p.ff];
			if(val == 0) continue;
			state st = p.ss;
			state inv = get_inv_state(st);
			int e = get_next_edge(inv);
			if(e == -1) continue;
			if(e == (int)E.size()) ans += val;
			else if(inv.e_top < inv.e_bot) {
				e ^= 1;
				dp[e] += val;
				if(dp[e] >= mod) dp[e] -= mod;
			}
		}
		ans %= mod;
		return ans;
	}
};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	if(N == 1) {
		cout << "2\n";
		return 0;
	}
	Solver solver(N);
	cout << solver.solve() << "\n";
}