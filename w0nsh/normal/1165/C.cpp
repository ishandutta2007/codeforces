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
	std::string str;
	std::cin >> str;
	std::string ans = "";
	int del = 0;
	std::reverse(str.begin(), str.end());
	int ps = 0;
	while(SZ(str)){
		if(ps%2 == 1){
			if(str.back() == ans.back()) del++;
			else{
				ans.push_back(str.back());
				ps = (ps+1)%2;
			}
		}else{
			ans.push_back(str.back());
			ps = (ps+1)%2;
		}
		str.pop_back();
	}
	if(SZ(ans) % 2 == 1) ans.pop_back(), del++;
	std::cout << del << "\n";
	std::cout << ans;
	return 0;
}