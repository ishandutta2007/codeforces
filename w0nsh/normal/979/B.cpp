#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <map>

int n;
std::string w[3];
std::vector<std::pair<int, int> > ans;

void answer(){
	ans.resize(3);
	for(int i = 0; i < 3; ++i){
		std::map<char, int> map;
		for(auto &ch : w[i]){
			map[ch]++;
		}
		int max = 0;
		for(auto &pr : map){
			max = std::max(max, pr.second);
		}
		int need = w[i].size() - max;
		if(n == 1 && max == (int)w[i].size()) ans[i] = std::make_pair(w[i].size()-1, i);
		else ans[i] = std::make_pair(std::min(w[i].size(), w[i].size()-need+n), i);
	}
	std::sort(ans.begin(), ans.end());
	std::reverse(ans.begin(), ans.end());
	if(ans[0].first == ans[1].first) std::cout << "Draw\n";
	else if(ans[0].second == 0) std::cout << "Kuro\n";
	else if(ans[0].second == 1) std::cout << "Shiro\n";
	else std::cout << "Katie\n";
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	for(int i = 0; i < 3; ++i) std::cin >> w[i];
	answer();
	return 0;
}