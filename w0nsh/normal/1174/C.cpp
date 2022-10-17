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


int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	VI col(n+1, 0);
	int fre = 1;
	for(int i = 2; i <= n; ++i){
		if(col[i] == 0){
			for(int j = i; j <= n; j += i){
				col[j] = fre;
			}
			fre++;
		}
	}
	REP(i, 2, n+1) std::cout << col[i] << " ";
	return 0;
}