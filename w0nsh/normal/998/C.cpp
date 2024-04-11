#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <utility>

int rev, inv, n;
std::string str;
int zeros;

void answer(){
	if(zeros <= 1) std::cout << zeros*inv << "\n";
	else{
		if(inv < rev){
			std::cout << 1ll*zeros*inv << "\n";
		}else{
			std::cout << 1ll*(zeros-1)*rev + 1ll*inv << "\n";
		}
	}
}

void read(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> rev >> inv;
	std::cin >> str;
	zeros = 0;
	bool last_zero = false;
	for(int i = 0; i < n; ++i){
		if(str[i] == '0'){
			if(!last_zero) zeros++;
			last_zero = true;
		}else{
			last_zero = false;
		}
	}
}

int main(){
	read();
	answer();
	return 0;
}