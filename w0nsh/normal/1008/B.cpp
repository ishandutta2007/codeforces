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
std::vector<std::pair<int, int> > vec;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	for(int i =0 ; i < n; ++i){
		int a, b;
		std::cin >> a >> b;
		vec.push_back({a, b});
	}
	int cur = 2000000000;
	bool wrong = false;
	for(int i = 0; i < n; ++i){
		if(std::max(vec[i].first, vec[i].second) <= cur) cur = std::max(vec[i].first, vec[i].second);
		else if(std::min(vec[i].first, vec[i].second) <= cur) cur = std::min(vec[i].first, vec[i].second);
		else{
			wrong = true;
			break;
		}
	}
	if(wrong) std::cout << "NO\n";
	else std::cout << "YES\n";
	return 0;
}