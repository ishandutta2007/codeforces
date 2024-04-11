#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define MP std::make_pair
#define PR std::pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

constexpr int N = 1000005;
std::array<VI, N> set;
std::array<bool, N> comp;
 
int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	for(int i = 2; i < N; ++i) set[i].reserve(9);
	for(int i = 2; i < N; ++i){
		if(!comp[i]){
			for(int j = i; j < N; j += i){
				comp[j] = true;
				int heh = 0;
				int x = j;
				while(x%i == 0) x /= i, heh++;
				assert(heh > 0);
				if(heh & 1) set[j].push_back(i);
			}
		}
	}

	int t;
	std::cin >> t;
	while(t--){
		int n;
		std::cin >> n;
		std::map<VI, int> map;
		int mx = 0;
		int nd = 0;
		FOR(i, n){
			int a;
			std::cin >> a;
			map[set[a]]++;
			mx = std::max(mx, map[set[a]]);
		}
		int zer = map[set[1]];
		TRAV(pr, map){
			if(SZ(pr.X)){
				if(pr.Y % 2 == 0) zer += pr.Y;
				else nd = std::max(nd, pr.Y);
			}
		}
		nd = std::max(nd, zer);
		int q;
		std::cin >> q;
		while(q--){
			ll x;
			std::cin >> x;
			if(x == 0) std::cout << mx << "\n";
			else std::cout << nd << "\n";
		}
	}

	return 0;
}