#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define PR std::pair
#define MP std::make_pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;


int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--){

		int n;
		std::cin >> n;
		VI next(n);
		FOR(i, n) std::cin >> next[i], next[i]--;
		VI ans = next;

		VI dead(n);
		VI indeg(n);
		VI unsat;
		FOR(i, n) indeg[next[i]]++;
		FOR(i, n) if(indeg[i] == 0 && !dead[i]){
			int v = i;
			int done = 0;
			dead[v] = 1;
			while(!dead[next[v]]){
				done++;
				v = next[v];
				dead[v] = 1;
			}

			if(done == 0){
				unsat.push_back(i);
			}else{
				ans[v] = i;
			}
		}

		if(SZ(unsat) == 1){
			int guy = next[unsat[0]];
			FOR(i, n) if(i != unsat[0] && ans[i] == guy){
				ans[i] = unsat[0];
				break;
			}
		}else{
			FOR(i, SZ(unsat)){
				ans[unsat[i]] = unsat[(i+1)%SZ(unsat)];
			}
		}


		indeg = VI(n);
		FOR(i, n){
			assert(ans[i] != i);
			indeg[ans[i]]++;
			assert(indeg[ans[i]] == 1);
		}


		int hehe = 0;
		FOR(i, n) if(ans[i] == next[i]) hehe++;
		std::cout << hehe << "\n";
		TRAV(i, ans) std::cout << i+1 << " ";
		std::cout << "\n";


	// 	std::cin >> n;
	// 	next.resize(n);
	// 	g = std::vector<VI>(n);
	// 	FOR(i, n){
	// 		std::cin >> next[i], next[i]--;
	// 		g[next[i]].push_back(i);
	// 	}
	// 	ans = next;
	// 	vis = cyc = dead = VI(n);

	// 	tick = 0;
	// 	FOR(i, n) if(!vis[i]){
	// 		tick++;

	// 		VI stack;
	// 		int v = i;
	// 		while(!vis[v]){
	// 			vis[v] = tick;
	// 			stack.push_back(v);
	// 			v = next[v];
	// 		}

	// 		if(vis[v] < tick) continue;
	// 		dead[v] = 1;
	// 		while(stack.back() != v){
	// 			dead[stack.back()] = 1;
	// 			stack.pop_back();
	// 		}
	// 	}

	// 	unsat = VI();
	// 	VI indeg(n);
	// 	FOR(i, n){
	// 		if(dead[i]) continue;
	// 		indeg[next[i]]++;
	// 	}

	// 	FOR(i, n) if(!dead[i] && indeg[i] == 0){
	// 		int v = i;
	// 		dead[v] = 1;
	// 		while(!dead[next[v]]){
	// 			dead[next[v]] = 1;
	// 			v = next[v];
	// 		}

	// 		if(v == i) unsat.push_back(i);
	// 		else ans[v] = i;
	// 	}

	// 	if(SZ(unsat) == 1){
	// 		int guy = next[unsat[0]];
	// 		unsat.push_back(guy);
	// 		unsat.push_back(ans[guy]);
	// 	}

	// 	FOR(i, SZ(unsat)){
	// 		ans[unsat[i]] = unsat[(i+1)%SZ(unsat)];
	// 	}

	// 	indeg = VI(n);
	// 	FOR(i, n){
	// 		assert(ans[i] != i);
	// 		indeg[ans[i]]++;
	// 		assert(indeg[ans[i]] == 1);
	// 	}

	// 	int hehe = 0;
	// 	FOR(i, n) if(ans[i] == next[i]) hehe++;
	// 	std::cout << hehe << "\n";
	// 	TRAV(i, ans) std::cout << i+1 << " ";
	// 	std::cout << "\n";
	}

	return 0;
}