#include <algorithm>
#include <vector>
#include <iostream>
#include <set>
#include <utility>

#define int long long

int n;
std::set<int> A;

void answer(){
	std::vector<int> best = {*(A.begin())};
	for(int i = 1; i < 1000000000000ll; i <<= 1){
		for(auto &a : A){
			std::vector<int> cand = {a};
			if(A.find(a-i) != A.end())
				cand.push_back(a-i);
			if(A.find(a+i) != A.end())
				cand.push_back(a+i);
			if(cand.size() > best.size()) best = cand;
			if(best.size() == 3) break;
		}
		if(best.size() == 3) break;
	}
	std::cout << best.size() << "\n";
	for(auto i : best) std::cout << i << " ";
	std::cout << "\n";
}

signed main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	for(int i = 0; i < n; ++i){
		int a;
		std::cin >> a;
		A.insert(a);
	}
	answer();
	return 0;
}