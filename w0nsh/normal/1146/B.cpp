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
	std::string str;
	std::cin >> str;
	int n = SZ(str);
	int cnt = 0;
	TRAV(i, str) if(i == 'a') cnt++;
	int bez = n - cnt;
	if(bez % 2 != 0){
		std::cout << ":(";
		return 0;
	}
	int lenfirst = cnt + bez/2;
	int pos = lenfirst;
	FOR(i, lenfirst){
		if(str[i] == 'a') continue;
		if(str[i] != str[pos++]){
			std::cout << ":(";
			return 0;
		}
	}
	FOR(i, lenfirst) std::cout << str[i];
	return 0;
}