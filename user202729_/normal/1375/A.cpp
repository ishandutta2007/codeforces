#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

void up();
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTest; std::cin>>numTest;
	while(numTest--) up();
}

void up(){
	int number; std::cin>>number;
	for(int i=0; i<number; ++i){
		int value; std::cin>>value;
		std::cout<<(i%2==0 ? -1: 1)*std::abs(value)<<' ';
	}
	std::cout<<'\n';
}