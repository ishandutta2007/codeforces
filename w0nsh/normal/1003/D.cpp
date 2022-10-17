#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#include <list>
#include <stack>
#include <functional>
#include <utility>

#define int long long

int n, q;
std::vector<int> powers;
std::vector<int> coins;

void calc_powers(){
	int have = 1;
	for(int i = 0; i < 50; ++i){
		powers.push_back(have);
		have *= 2;
	}
}

void read(){
std::ios_base::sync_with_stdio(false);
	std::cin >> n >> q;
	coins.resize(40);
	for(int i = 0; i < n; ++i){
		int a;
		std::cin >> a;
		coins[std::distance(powers.begin(), std::lower_bound(powers.begin(), powers.end(), a))]++;
	}
}

void answer(){
	while(q--){
		int b;
		std::cin >> b;
		int spent = 0;
		for(int i = 38; i >= 0; --i){
			if(coins[i] == 0) continue;
			int hm = std::min(b / powers[i], coins[i]);
			spent += hm;
			b = b - (hm * powers[i]);
		}
		if(b > 0){
			std::cout << "-1" << "\n";
		}else{
			std::cout << spent << "\n";
		}
	}
}

signed main(){
	calc_powers();
	read();
	answer();
	return 0;
}