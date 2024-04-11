#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define MP std::make_pair
#define PR std::pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

ll tab[26][26];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	
	FOR(i, n){
		FOR(j, n){
			int kt = i+j;
			if(kt == 0 || kt == 2*n-2 || (i+j)%2 == i%2) tab[i][j] = 0;
			else tab[i][j] = 1ll<<(kt-1);
			std::cout << tab[i][j] << " ";
		}
		std::cout << std::endl;
	}

	int q;
	std::cin >> q;
	while(q--){
		ll k;
		std::cin >> k;
		PII pos = MP(0, 0);
		std::vector<PII> ans;
		
		while(pos != MP(n-1, n-1)){
			ans.push_back(pos);
			if(pos.X + pos.Y == 2*n-3){
				pos = MP(n-1, n-1);
				continue;
			}

			if(pos.X == n-1){
				pos.Y++;
			}else if(k & (1ll<<(pos.X+pos.Y)) ){
				if((pos.X+pos.Y+1)%2 == (pos.X+1)%2) pos.Y++;
				else pos.X++;
			}else{
				if((pos.X+pos.Y+1)%2 == (pos.X+1)%2) pos.X++;
				else pos.Y++;
			}
		}

		ans.push_back(pos);

		TRAV(i, ans) std::cout << i.X+1 << " " << i.Y+1 << "\n";
		std::cout << std::endl;
	}

	return 0;
}