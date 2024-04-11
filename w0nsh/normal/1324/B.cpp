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
		VI A(n);
		FOR(i, n) std::cin >> A[i];
		std::map<int, VI> map;
		FOR(i, n){
			map[A[i]].push_back(i);
		}
		bool good = false;
		TRAV(pr, map){
			if(SZ(pr.Y) > 2) good = true;
			if(SZ(pr.Y) == 2 && pr.Y[0] +1 != pr.Y[1]) good = true;
		}
		std::cout << (good ? "YES\n" : "NO\n");
	}

	return 0;
}