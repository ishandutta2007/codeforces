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

int tab[3][100005];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n, q;
	std::cin >> n >> q;
	ll pairs = 0;
	FOR(i, q){
		int a, b;
		std::cin >> a >> b;
		a--;
		int som = tab[1-a][b-1]+tab[1-a][b]+tab[1-a][b+1];
		if(tab[a][b]) pairs -= som;
		else pairs += som;
		tab[a][b] = 1-tab[a][b];
		assert(pairs >= 0);
		if(pairs == 0) std::cout << "Yes\n";
		else std::cout << "No\n";
	}
	return 0;
}