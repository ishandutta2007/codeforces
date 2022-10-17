#include <bits/stdc++.h> 

#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define SZ(x) (int)(x).size()
typedef std::vector<int> VI;

int n, m, Y[105], X[105], ret[105][105];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m;
	FOR(i, n) std::cin >> X[i];
	FOR(i, m) std::cin >> Y[i];
	FOR(bit, 31){
		VI x, y;
		FOR(i, n) if(X[i] & (1<<bit)) x.push_back(i);
		FOR(i, m) if(Y[i] & (1<<bit)) y.push_back(i);
		if(std::abs(SZ(x) - SZ(y)) % 2 != 0) (std::cout << "NO\n"), (std::exit(0));
		while(SZ(x) * SZ(y) > 0){
			ret[x.back()][y.back()] = ret[x.back()][y.back()] | (1<<bit);
			x.pop_back();
			y.pop_back();
		}
		while(SZ(x)) ret[x.back()][0] = ret[x.back()][0] | (1<<bit), x.pop_back();
		while(SZ(y)) ret[0][y.back()] = ret[0][y.back()] | (1<<bit), y.pop_back();
	}
	std::cout << "YES\n";
	FOR(i, n){
		FOR(j, m) std::cout << ret[i][j] << " ";
		std::cout << "\n";
	}
	return 0;
}