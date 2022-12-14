#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

void up(){
	int number; std::cin>>number;
	if(number==1){
		std::cout<<"-1\n";
		return;
	}
	int mod7=5;
	std::cout<<'5';
	for(int _=0;_<number-1;++_) {
		auto const nextDigit=(mod7*10+3)%7==0 ? 9: 3;
		std::cout<<char('0'+nextDigit);
		mod7=(mod7*10+nextDigit)%7;
		assert(mod7!=0);
	}
	std::cout<<'\n';

}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTest; std::cin>>numTest;
	while(numTest--) up();
}