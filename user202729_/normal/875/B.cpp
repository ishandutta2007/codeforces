#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	std::vector<char> add(number);
	std::cout<<'1';
	for(int i=0; i<number; ++i){
		int value; std::cin>>value;--value;
		add[value]=true;
		while(not add.empty() and add.back()) add.pop_back();
		std::cout<<' '<<2+i-(number-(int)add.size());
	}
	std::cout<<'\n';
}