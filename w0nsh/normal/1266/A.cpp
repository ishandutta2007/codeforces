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
	FOR(i, n){
		std::string a;
		std::cin >> a;
		int sum  = 0;
		int par = -1;
		int zer = 0;
		TRAV(ch, a){
			if(ch == '0') zer++;
			if((ch-'0')%2 == 0) par++;
			sum += (ch-'0');
		}
		if(sum == 0) std::cout << "red\n";
		else if(sum%3 == 0 && par > 0 && zer > 0) std::cout << "red\n";
		else std::cout << "cyan\n";
	}
	return 0;
}