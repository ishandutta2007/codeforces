#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
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
		std::string A, B;
		std::cin >> A >> B;

		std::set<PII> set;
		bool good = true;
		FOR(i, n){
			if(A[i] > B[i]){
				good = false;
				break;
			}else if(A[i] < B[i]){
				set.insert(MP(A[i]-'a', B[i]-'a'));
			}
		}
		if(!good){
			std::cout << -1 << "\n";
			continue;
		}
		int ans = 0;
		while(SZ(set)){
			int guy = set.begin()->X;
			VI all;
			while(SZ(set) && set.begin()->X == guy){
				all.push_back(set.begin()->Y);
				set.erase(set.begin());
			}
			ans++;
			TRAV(i, all){
				if(i != all[0]) set.insert(MP(all[0], i));
			}
		}
		std::cout << ans << "\n";
	}

	return 0;
}