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
	int n, k;
	std::cin >> n >> k;
	std::map<int, int> map;
	FOR(i, n){
		int a;
		std::cin >> a;
		map[a]++;
	}
	int left = (n+1)/2;
	int zad = 0;
	TRAV(pr, map){
		while(pr.Y >= 2 && left > 0){
			left--;
			zad += 2;
			pr.Y -= 2;
		}
	}
	TRAV(pr, map){
		if(pr.Y == 1 && left > 0){
			left--;
			zad += 1;
			pr.Y--;
		}
	}
	std::cout << zad;
	return 0;
}