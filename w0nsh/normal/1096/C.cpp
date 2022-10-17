#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : n)
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long double ld;
#define PLD std::pair<ld, ld>
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;
#define PI 3.14159265359;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int t;
	std::cin >> t;
	while(t--){
		int ang;
		std::cin >> ang;
		int n = 3;
		int good = -1;
		while(good == -1 && n < 400){
			// if(std::abs(360.0*(n-2)/n - ang) < 0.00001){
			// 	std::cout << n << "\n";
			// 	good = 1;
			// 	break;
			// }
			std::vector<long double> angles;
			REP(i, 1, n/2){
				angles.push_back(360.0*((long double)i)/n/2.0);
				if(std::abs(360.0*((long double)i)/n/2.0 - ang) < 0.00001){
					std::cout << n << "\n";
					good = 1;
					break;
				}

			}
			if(good == -1){
				angles.push_back(360.0*((long double)((n-1)/2))/n/2.0);
				FOR(i, SZ(angles)){
					REP(j, i, SZ(angles)){
						if(std::abs(180.0-angles[i]-angles[j]-ang) < 0.00001){
							std::cout << n << "\n";
							good = 1;
							break;
						}
					}
					if(good == 1) break;
				}
				
			}
			n++;
		}
		if(good == -1) std::cout << -1 << "\n";
	}
	return 0;
}