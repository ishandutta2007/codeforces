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
#include <iomanip>
#include <cstdlib>

int ans = 0;
std::vector<int> A;

void answer(){
	int rests[3];
	rests[1] = rests[2] = 0;
	for(auto i : A){
		if(i % 3 == 0){
			rests[1] = rests[2] = 0;
			ans++;
			continue;
		}
		if(rests[3-(i%3)] > 0 || rests[i%3] == 2){
			rests[1] = rests[2] = 0;
			ans++;
		}else rests[i%3]++;
	}
	std::cout << ans << "\n";
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::string temp;
	std::cin >> temp;
	for(auto c : temp){
		A.push_back(c - '0');
	}
	answer();
	return 0;
}