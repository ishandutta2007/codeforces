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


std::string str;
int k, n, lets, que, star;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> str >> k;
	n = SZ(str);
	FOR(i, n){
		if(str[i] == '?') que++;
		else if(str[i] == '*') star++;
		else lets++;
	}
	if(lets == k){
		FOR(i, n) if(str[i] != '?' && str[i] != '*') std::cout << str[i];
	}else if(lets < k){
		if(star == 0) std::cout << "Impossible";
		else{
			FOR(i, n){
				if(str[i] == '?') continue;
				if(str[i] == '*'){
					if(star == 0) continue;
					star = 0;
					FOR(j, k-lets) std::cout << str[i-1];
				}else std::cout << str[i];
			}
		}
	}else{
		if(star + que < lets-k) std::cout << "Impossible";
		else{
			std::string ret;
			int left = lets-k;
			FOR(i, n){
				if(str[i] == '?' || str[i] == '*'){
					if(left > 0){
						left--;
						ret.pop_back();
					}
				}else ret.push_back(str[i]);
			}
			std::cout << ret;
		}
	}
	return 0;
}