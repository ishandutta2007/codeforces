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
		std::set<int> mods;
		FOR(i, n){
			int a;
			std::cin >> a;
			a = (i+a)%n;
			if(a < 0) a += n;
			mods.insert(a);
		}
		if(SZ(mods) == n) std::cout << "YES\n";
		else std::cout << "NO\n";
	}
	return 0;
}