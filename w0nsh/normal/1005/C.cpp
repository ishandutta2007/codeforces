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

#define PR std::pair
#define X first
#define Y second

#define int long long

int n;
std::vector<int> A;
std::map<int, PR<int, bool> > map;

void answer(){
	for(auto v : A){
		if(map.find(v) != map.end() && map[v].Y == true){
			map[v].X++;
			continue;
		}
		bool good = false;
		for(long long i = 1; i < 10000000000ll; i<<=1){
			if(map.find(i-v) != map.end()){
				good = true;
				map[i-v].Y = true;
			}
		}
		if(!good){
			if(map.find(v) == map.end()) map[v] = {0, false};
			map[v].X++;
		}
		else{
			if(map.find(v) == map.end()) map[v] = {0, true};
			map[v].X++;
		}
	}
	int count = 0;
	for(auto kvp : map){
		if(!kvp.second.Y) count += kvp.second.X;
	}
	std::cout << count << "\n";
}

signed main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	A.resize(n);
	for(int i = 0; i < n; ++i) std::cin >> A[i];
	answer();
	return 0;
}