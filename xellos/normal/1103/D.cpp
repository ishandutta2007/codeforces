#include <bits/stdc++.h>
// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#include <time.h>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) (((x) < 0)?-(x):(x))
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

using cat = long long;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

struct exp_trie {
	// trie over sequences of exponents

	vector<cat> primes;

	struct node {
		cat val;
		short last_p, last_e;
		int par;
		short dep;
	};
	vector<node> V;
	vector<int> sons, backlinks, backlinks_start;
	vector< vector<int> > sons_start;
	vector< vector< pair<int, int> > > min_costs;

	exp_trie(vector<cat> primes_, cat MX) : primes(primes_) {
		int P = primes.size();
		V.push_back({1, -1, 0, 0, 0});
		sons_start.push_back({});
		V.dibs(2500000);
		sons.dibs(2500000);
		sons_start.dibs(2500000);
		for(int i = 0; i < (int)V.size(); i++) {
			if(P > 0 && primes[0] > MX / V[i].val) continue; // leaf
			sons_start[i].resize(P, 0);
			for(int j = V[i].last_p+1; j < P; j++) {
				sons_start[i][j] = sons.size();
				if(primes[j] > MX / V[i].val) continue;
				cat x = primes[j] * V[i].val;
				int e = 1;
				while(x <= MX) {
					sons.push_back(V.size());
					V.push_back({x, j, e, i, V[i].dep+1});
					sons_start.push_back({});
					e++;
					x *= primes[j];
				}
			}
		}
		min_costs.resize(V.size());
	}

	void put_cost(vector<int> pw_seq, int cost, int id) {
		int akt = 0;
		for(int i = 0; i < (int)pw_seq.size(); i++) if(pw_seq[i] > 0)
			akt = sons[sons_start[akt][i]+pw_seq[i]-1];
		min_costs[akt].push_back({cost, id});
	}

	void create_backlinks() {
		backlinks_start.resize(V.size(), 0);
		backlinks.dibs(15000000);
		for(int i = 1; i < (int)V.size(); i++) {
			node & n = V[i];
			backlinks_start[i] = backlinks.size();
			backlinks.push_back(n.par);
			for(int j = 0; j < n.dep-1; j++) {
				int v = backlinks[backlinks_start[n.par]+j];
				backlinks.push_back(sons[sons_start[v][n.last_p]+n.last_e-1]);
			}
		}
	}

	void propagate_subset_min(cat K) {
		for(int i = 0; i < (int)V.size(); i++) {
			sort(begin(min_costs[i]), end(min_costs[i]));
			min_costs[i].resize(min((int)min_costs[i].size(), (int)primes.size()));
		}
		for(int i = (int)V.size()-1; i >= 0; i--) for(int j = 0; j < V[i].dep; j++) {
			int v = backlinks[backlinks_start[i]+j];
			vector< pair<int, int> > min_cost(min_costs[v].size()+min_costs[i].size());
			merge(begin(min_costs[v]), end(min_costs[v]), begin(min_costs[i]), end(min_costs[i]), begin(min_cost));
			int sz = unique(begin(min_cost), end(min_cost)) - begin(min_cost);
			min_cost.resize(min(sz, (int)primes.size()));
			min_costs[v] = min_cost;
		}
	}

	vector< vector< pair<int, int> > > get_subset_min(cat K) {
		int P = primes.size();
		vector< vector< pair<int, int> > > ret(1<<P);
		for(int i = 0; i < (int)V.size(); i++) if(V[i].val <= K) {
			int b = 0, akt = i;
			while(akt > 0) {
				b |= 1<<(V[akt].last_p);
				akt = V[akt].par;
			}
			vector< pair<int, int> > min_cost(ret[b].size()+min_costs[i].size());
			merge(begin(ret[b]), end(ret[b]), begin(min_costs[i]), end(min_costs[i]), begin(min_cost));
			int sz = unique(begin(min_cost), end(min_cost)) - begin(min_cost);
			min_cost.resize(min(sz, (int)primes.size()));
			ret[b] = min_cost;
		}
		return ret;
	}
};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cat K;
	cin >> N >> K;
	vector<cat> A(N);
	for(int i = 0; i < N; i++) cin >> A[i];
	vector<int> E(N);
	for(int i = 0; i < N; i++) cin >> E[i];
	vector<cat> primes;
	cat X = A[0];
	for(cat i = 2; i*i <= X; i++) if(X%i == 0) {
		primes.push_back(i);
		while(X%i == 0) X /= i;
	}
	if(X > 1) primes.push_back(X);
	for(int i = 0; i < (int)primes.size(); i++) {
		bool pw0 = false;
		for(int j = 0; j < N; j++) if(A[j]%primes[i] != 0) pw0 = true;
		if(pw0) {
			for(int j = i+1; j < (int)primes.size(); j++) primes[j-1] = primes[j];
			primes.pop_back();
			i--;
			continue;
		}
	}
	sort(begin(primes), end(primes));
	int P = primes.size();
	vector< vector<int> > pw(N, vector<int>(P, 0));
	cat MX = 1;
	for(int i = 0; i < N; i++) {
		cat a = 1;
		for(int j = 0; j < P; j++) {
			int e = 0;
			while(A[i]%primes[j] == 0) e++, A[i] /= primes[j], a *= primes[j];
			pw[i][j] = e;
		}
		MX = max(MX, a);
	}
	exp_trie T(primes, MX);
	for(int i = 0; i < N; i++) T.put_cost(pw[i], E[i], i);
	T.create_backlinks();
	T.propagate_subset_min(K);
	vector< vector< pair<int, int> > > cost = T.get_subset_min(K);
	vector< vector<int> > subsets(N);
	for(int i = 0; i < (1<<P); i++) ALL_THE(cost[i], it) subsets[it->ss].push_back(i);
	vector< vector<int> > disj(1<<P);
	disj[(1<<P)-1].push_back(0);
	for(int i = (1<<P)-2; i >= 0; i--) for(int j = 0; j < P; j++) if(((i>>j)&1) == 0) {
		disj[i] = disj[i|(1<<j)];
		ALL_THE(disj[i|(1<<j)], it) disj[i].push_back(*it | (1<<j));
		break;
	}
	vector< vector<cat> > dp(1<<P, vector<cat>(1+P, -1));
	dp[0][0] = 0;
	for(int i = 0; i < N; i++) if(!subsets[i].empty()) {
		vector< vector<cat> > dp_nw = dp;
		ALL_THE(subsets[i], it) ALL_THE(disj[*it], jt) for(int j = 0; j < P; j++) if(dp[*jt][j] != -1) {
			if(dp_nw[*jt|*it][j+1] == -1) dp_nw[*jt|*it][j+1] = dp[*jt][j] + E[i];
			else dp_nw[*jt|*it][j+1] = min(dp_nw[*jt|*it][j+1], dp[*jt][j] + E[i]);
		}
		dp = dp_nw;
	}
	cat ans = -1;
	for(int i = 0; i <= P; i++) if(dp[(1<<P)-1][i] != -1) {
		if(ans == -1) ans = i * dp[(1<<P)-1][i];
		else ans = min(ans, i * dp[(1<<P)-1][i]);
	}
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing