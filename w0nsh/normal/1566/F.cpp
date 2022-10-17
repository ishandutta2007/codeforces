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

constexpr ll INF = 1000000666ll * 1000000000ll;
constexpr int MAGIC = 1000000666;

void solve(){
	int n, m;
	std::cin >> n >> m;
	VI A(n);
	FOR(i, n) std::cin >> A[i];
	std::sort(A.begin(),A.end());

	std::vector<PII> B(m);
	FOR(i, m){
		std::cin >> B[i].X >> B[i].Y;
	}
	std::sort(B.begin(), B.end());

	std::set<PII> set;
	std::vector<PII> evs;
	FOR(i, m){
		evs.push_back(MP(B[i].X, -i-1));
		evs.push_back(MP(B[i].Y, i+1));
	}
	FOR(i, n) evs.push_back(MP(A[i], 0));
	std::sort(evs.begin(), evs.end());
	std::vector<bool> dead(m);

	TRAV(ev, evs){
		int x = ev.X;
		int y = ev.Y;
		if(y < 0){
			y *= -1;
			y--;

			set.insert(MP(x, y));
		}else if(y > 0){
			y--;

			auto it = set.lower_bound(MP(B[y].X+1, -1));
			if(it != set.begin()){
				--it;
				while(true){
					if(it == set.begin()){
						if(it->Y != y)
							dead[it->Y] = true;
						set.erase(it);
						break;
					}
					auto next = std::prev(it);
					if(it->Y != y)
						dead[it->Y] = true;
					set.erase(it);
					it = next;
				}
			}
		}else{

			TRAV(pr, set){
				dead[pr.Y] = true;
			}
			set.clear();

		}
	}

	std::vector<PII> C;
	FOR(i, m){
		if(!dead[i]) C.push_back(B[i]);
	}

	// TRAV(pr, C){
	// 	std::cout << pr.X << " " << pr.Y << std::endl;
	// }

	FOR(i, SZ(C)-1){
		assert(C[i].X < C[i+1].X);
		assert(C[i].Y <= C[i+1].Y);
	}
	if(SZ(C) == 0){
		std::cout << 0 << "\n";
		return;
	}

	std::map<int, ll> cost;
	TRAV(pr, C) cost[pr.X] = INF;
	cost[MAGIC] = 0;

	FOR(i, n){
		VI prev;
		auto pocz = (i == 0 ? C.begin() : std::lower_bound(C.begin(), C.end(), MP(A[i-1], -MAGIC)));
		auto kon = std::lower_bound(C.begin(), C.end(), MP(A[i], -MAGIC));
		while(pocz < kon){
			prev.push_back(std::abs(std::distance(pocz, C.begin())));
			pocz++;
		}

		VI next;
		pocz = std::lower_bound(C.begin(), C.end(), MP(A[i], -MAGIC));
		kon = (i == n-1 ? C.end() : std::lower_bound(C.begin(), C.end(), MP(A[i+1], -MAGIC)));
		while (pocz < kon){
			next.push_back(std::abs(std::distance(pocz, C.begin())));
			pocz++;
		}

		ll best1 = INF;
		ll best2 = INF;

		FOR(x, SZ(prev)){
			int musze;
			if(x == SZ(prev)-1){
				musze = 0;
			}else{
				musze = A[i] - C[prev[x+1]].Y;
			}

			best2 = std::min(best2, cost[C[prev[x]].X] + 2ll * musze);
			best1 = std::min(best1, cost[C[prev[x]].X] + musze);
		}

		if(SZ(prev)){
			int musze = A[i] - C[prev[0]].Y;
			best2 = std::min(best2, cost[MAGIC] + 2ll * musze);
			best1 = std::min(best1, cost[MAGIC] + musze);
		}else{
			best1 = cost[MAGIC];
			best2 = cost[MAGIC];
		}

		cost[MAGIC] = best1;
		FOR(x, SZ(next)){
			int musze = C[next[x]].X - A[i];

			cost[C[next[x]].X] = std::min(best2 + musze, best1 + 2ll * musze);
		}
	}

	if(C.back().X > A.back()) {
		std::cout << cost[C.back().X] << "\n";
	}else{
		std::cout << cost[MAGIC] << "\n";
	}
}


int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int t;
	std::cin >> t;
	while(t--){
		solve();
	}

	return 0;
}