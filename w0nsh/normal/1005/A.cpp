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

int n;
std::vector<int> A;


void answer(){
	std::vector<int> stairs;
	int have = 0;
	for(int i = 0; i < n; ++i){
		if(A[i] == 1){
			if(have > 0) stairs.push_back(have);
			have = 1;
		}else have++;
	}
	if(have > 0) stairs.push_back(have);
	std::cout << stairs.size() << "\n";
	for(auto s : stairs) std::cout << s << " ";
}

void read(){
	std::cin >> n;
	for(int i = 0; i < n; ++i){
		int a;
		std::cin >> a;
		A.push_back(a);
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	read();
	answer();
	return 0;
}