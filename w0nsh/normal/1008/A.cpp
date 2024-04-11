#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
int main(){
std::ios_base::sync_with_stdio(false);
	std::string str;
	std::cin >> str;
	std::set<char> vow = {'a', 'o', 'u', 'i', 'e'};
	bool must = false;
	bool wrong = false;
	if(str.back() != 'n' && vow.find(str.back()) == vow.end()){
		std::cout << "NO\n";
		return 0;
	}
	for(int i = 0; i < str.size(); ++i){
		if(vow.find(str[i]) != vow.end()) must = false;
		else if(must){
			wrong = true;
			break;
		}else{
			must = true;
			if(str[i] == 'n') must = false;
		}
	}
	if(wrong) std::cout << "NO\n";
	else std::cout << "YES\n";
	return 0;
}