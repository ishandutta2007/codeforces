#include <iostream>
#include <string>
#include <algorithm>

int n;
std::string str;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> str;
	for(int i = 2; i <= n; ++i){
		if(n%i == 0){
			std::reverse(str.begin(), str.begin()+i);
		}
	}
	std::cout << str << "\n";
	return 0;
}