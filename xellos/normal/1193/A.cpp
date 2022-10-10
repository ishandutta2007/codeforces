// Build DAG by adding single vertices.
// If we add vertex i, we can't add any vertex < i
// until there is an edge to it from vertex i or any later added vertex.
// States of DP: (added vertices, candidates for next added). O(4^N).
#include <bits/stdc++.h>
using namespace std;

struct state {
	int candidates;
	int cnt, sum;
	constexpr static int mod = 998244353;

	state() = default;
	state(int candidates_, int cnt_, long long sum_)
		: candidates(candidates_), cnt(cnt_), sum(sum_ % mod) {}

	inline state & operator+=(const state & S) {
		cnt += S.cnt;
		if(cnt >= mod) cnt -= mod;
		sum += S.sum;
		if(sum >= mod) sum -= mod;
		return *this;
	}

	bool operator<(const state & S) const {
		return candidates < S.candidates;
	}
};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N, M;
	cin >> N >> M;
	vector<int> E(N, 0), Ei(N, 0), E_all(N, 0);
	for(int i = 0; i < M; i++) {
		int u, v;
		/* rand */
		// static mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
		// u = rng()%N, v = rng()%N;
		// while(u == v || (E_all[u]>>v)&1)
		// 	u = rng()%N, v = rng()%N;
		/* rand */
		/* input */
		cin >> u >> v;
		u--, v--;
		/* input */
		E[u] |= 1<<v;
		Ei[v] |= 1<<u;
		E_all[u] |= 1<<v;
		E_all[v] |= 1<<u;
	}

	vector< vector<state> > dp(1<<N);
	// dp[0].push_back({(1<<N)-1, 1});
	dp[0].push_back({(1<<N)-1, 1, 0});
	for(int used = 0; used < (1<<N); used++) {
		sort(begin(dp[used]), end(dp[used]));
		int pos = 0;
		for(int i = 1; i < (int)dp[used].size(); i++) {
			if(dp[used][i].candidates == dp[used][pos].candidates) {
				dp[used][pos] += dp[used][i];
				continue;
			}
			pos++;
			dp[used][pos] = dp[used][i];
		}
		if(!dp[used].empty()) {
			dp[used].resize(pos+1);
		}
		for(state & st : dp[used]) {
			int suf = (1<<N)-1;
			for(int j = 0; j < N; j++) {
				suf ^= (1<<j);
				if(((st.candidates)>>j)&1) {
					int next_used = used | (1<<j);
					int next_candidates = (st.candidates & suf) | E_all[j];
					next_candidates ^= (next_candidates & next_used);
					long long num_reversed = __builtin_popcount(used & E[j]);
					dp[next_used].push_back({next_candidates, st.cnt, st.sum + st.cnt * num_reversed});
				}
			}
		}
	}

	int num_states = 0;
	for(int i = 0; i < (1<<N); i++) num_states += dp[i].size();
	cerr << num_states << "\n";

	long long ans_sum = 0, ans_cnt = 0;
	for(state & st : dp[(1<<N)-1]) {
		// ans_cnt += st.cnt;
		ans_sum += st.sum;
	}
	// ans_cnt %= state::mod;
	ans_sum %= state::mod;
	// ans_sum = ans_cnt * M % state::mod;
	// ans_sum = ans_sum * pow(2, state::mod-2, state::mod) % state::mod;
	// cout << ans_cnt << "\n";
	cout << ans_sum << "\n";
	return 0;
}