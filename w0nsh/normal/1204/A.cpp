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
	std::string a;
	std::cin >> a;
	if(a == "0"){
		std::cout << 0 << "\n";
	}else{
		int len = SZ(a);
		bool all = true;
		REP(i, 1, SZ(a)) if(a[i] != '0') all = false;
		int pw = (len-1);
		int missed = pw/2+1;
		if(all && pw%2 == 0) missed--;
		std::cout << missed << "\n";
	}
	
	return 0;
}