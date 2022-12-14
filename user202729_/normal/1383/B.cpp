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
	std::array<std::array<int, 2>, 30> count{};
	for(int _=0; _<number; ++_){
		int value; std::cin>>value;
		for(int bit=0; bit<(int)count.size(); ++bit)
			count[bit][value>>bit&1]++;
	}

	for(auto bit=30; bit--;){
		if(count[bit][1]%2==0)
			continue;
		if(count[bit][1]%4==1||count[bit][0]%2==1)
			std::cout<<"WIN\n";
		else std::cout<<"LOSE\n";
		return;
	}
	std::cout<<"DRAW\n";
}