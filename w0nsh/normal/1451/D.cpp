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

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--){
		ll d, k;
		std::cin >> d >> k;
		int ile = 0;
		while((ile*k)*(ile*k)*2 <= d*d){
			ile++;
		}
		ile--;
		if((ile*k)*(ile*k) + (ile*k+k)*(ile*k+k) > d*d){
			std::cout << "Utkarsh\n";
		}else{
			std::cout << "Ashish\n";
		}
	}

	return 0;
}