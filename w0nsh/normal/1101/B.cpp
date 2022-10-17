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
int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> str;
	int n = SZ(str);
	VI now;
	now.push_back(58);
	now.push_back(91);
	int left = -1;
	int rem = 0;
	FOR(i, n){
		if((int)str[i] == now.back()) now.pop_back();
		else rem++;
		if(now.empty()){
			left = i;
			break;
		}
	}
	if(left == -1){
		std::cout << -1;
		return 0;
	}
	now.push_back(58);
	now.push_back(93);
	int right = -1;
	for(int i = n-1; i >= 0; --i){
		if((int)str[i] == now.back()) now.pop_back();
		else rem++;
		if(now.empty()){
			right = i;
			break;
		}
	}
	if(right == -1 || left >= right){
		std::cout << -1;
		return 0;
	}
	REP(i, left+1, right){
		if((int)str[i]  != 124) rem++;
	}
	std::cout << n - rem;
	return 0;
}