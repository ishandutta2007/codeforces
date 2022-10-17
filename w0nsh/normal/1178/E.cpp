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
	std::string ans = "";
	if(SZ(str) % 2 == 1) str.pop_back();
	int n = SZ(str);
	for(int i = 0; i < n/2-1; i += 2){
		if(str[i] == str[n-1-i] || str[i] == str[n-1-i-1]) ans.push_back(str[i]);
		else if(str[i+1] == str[n-1-i] || str[i+1] == str[n-1-i-1]) ans.push_back(str[i+1]);
	}
	std::cout << ans;
	if(SZ(str) % 4 != 0) std::cout << str[n/2];
	std::reverse(ans.begin(), ans.end());
	std::cout << ans;
	return 0;
}