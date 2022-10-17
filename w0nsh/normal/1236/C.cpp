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

int tab[305][305];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	FOR(i, n){
		if(i%2 == 0){
			FOR(j, n) tab[j][i] = i*n+j;
		}else{
			FOR(j, n) tab[j][i] = i*n+(n-1-j);
		}
	}
	FOR(i, n){
		FOR(j, n){
			std::cout << tab[i][j]+1 << " ";
		}
		std::cout << "\n";
	}
	return 0;
}