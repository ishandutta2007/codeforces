#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : n)
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

int n, m;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int t;
	std::cin >> t;
	while(t--){
		std::cin >> n >> m;
		std::vector<PII> edges;
		FOR(i, m){
			int a, b;
			std::cin >> a >> b;
			a--;b--;
			edges.push_back(MP(a, b));
		}
		std::set<int> was;
		VI match;
		FOR(i, m){
			auto ed = edges[i];
			if(was.count(ed.X) == 0 && was.count(ed.Y) == 0){
				was.insert(ed.X);
				was.insert(ed.Y);
				match.push_back(i);
			}
		}
		if(SZ(match) >= n){
			std::cout << "Matching\n";
			FOR(i, n) std::cout << match[i]+1 << " ";
			std::cout << "\n";
		}else{
			std::cout << "IndSet\n";
			int done = n;
			int cur = 0;
			while(done > 0){
				if(was.count(cur) == 0){
					std::cout << cur+1 << " ";
					done--;
				}
				cur++;
			}
			std::cout << "\n";
		}
	}
	
	return 0;
}