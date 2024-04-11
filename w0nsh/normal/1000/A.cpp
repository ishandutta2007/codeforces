#include <algorithm>
#include <set>
#include <vector>
#include <iostream>
#include <map>
#include <string>

int n;
std::map<std::string, int> A, B;

void answer(){
	int ret = 0;
	for(auto it = A.begin(); it != A.end(); ++it){
		std::string str = it->first;
		ret += std::max(0, A[str] - B[str]);
	}
	std::cout << ret << "\n";
}

void read(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	for(int i = 0; i < n; ++i){
		std::string str;
		std::cin >> str;
		A[str]++;
	}
	for(int i = 0; i < n; ++i){
		std::string str;
		std::cin >> str;
		B[str]++;
	}
}

int main(){
	read();
	answer();
	return 0;
}