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

int a, b, f, k;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> a >> b >> f >> k;
	int cnt = 0;
	int x[2];
	x[0] = f;
	x[1] = a-f;
	int fuel = b-x[0];
	if(fuel < 0){
		std::cout << -1 << "\n";
		return 0;
	}
	REP(i, 1, k){
		if(fuel < 0){
			std::cout << -1 << "\n";
			return 0;
		}
		if(fuel >= x[i%2]*2) fuel -= x[i%2]*2;
		else{
			cnt++;
			fuel = b;
			if(fuel < x[i%2]*2){
				std::cout << -1 << "\n";
				return 0;
			}
			fuel -= x[i%2]*2;
		}
	}
	if(fuel < x[k%2]){
		cnt++;
		fuel = b;
		if(fuel < x[k%2]){
			std::cout << -1 << "\n";
			return 0;
		}
	}
	std::cout << cnt << "\n";
	return 0;
}