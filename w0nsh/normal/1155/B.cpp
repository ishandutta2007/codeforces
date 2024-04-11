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
	std::string str;
	std::cin >> n >> str;
	int moves = (n-11)/2;
	int pos = 0;
	int eights = 0;
	while(eights < moves && pos < n){
		if(str[pos] == '8') eights++;
		pos++;
	}
	while(pos < n && str[pos] != '8') pos++;
	if(pos == n){
		std::cout << "NO\n";
		return 0;
	}
	int cnt = 0;
	FOR(i, pos) if(str[i] != '8') cnt++;
	if(cnt > moves) std::cout << "NO\n";
	else std::cout << "YES\n";
	return 0;
}