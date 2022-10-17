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

const int MAX = 2000000;

int tab[600][600];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	VI primes;
	std::vector<bool> prime(MAX);
	for(int i = 2; i < MAX; ++i){
		if(!prime[i]){
			primes.push_back(i);
			for(int j = std::min(1ll*i*i, 1ll*MAX); j < MAX; j += i){
				prime[j] = true;
			}
		}
	}
	int r, c;
	std::cin >> r >> c;
	if(r == 1 && c == 1){
		std::cout << 0 << "\n";
		return 0;
	}
	bool swap = false;
	if(r > c){
		std::swap(r, c);
		swap = true;
	}
	if(r == 1){
		FOR(i, c) tab[0][i] = i+2;
	}else{
		FOR(i, r){
			FOR(j, c){
				tab[i][j] = i+1;
			}
		}
		FOR(j, c){
			FOR(i, r){
				tab[i][j] *= r+j+1;
			}
		}
	}
	if(swap){
		FOR(i, c){
			FOR(j, r){
				std::cout << tab[j][i] << " ";
			}
			std::cout << "\n";
		}
	}
	else{
		FOR(i, r){
			FOR(j, c){
				std::cout << tab[i][j] << " ";
			}
			std::cout << "\n";
		}
	}
	return 0;
}