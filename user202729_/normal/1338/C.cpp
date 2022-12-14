#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

void up(){
	int64_t index; std::cin>>index;
	--index;
	int numDigit=1;  // base 4
	int64_t countCur=3;
	while(index>=countCur){
		++numDigit;
		index-=countCur;
		countCur*=4;
	}
	auto const subindex=index%3; index/=3;
	assert(index<countCur/3);
	auto result=countCur/3+index;
	if(subindex!=0){
		int64_t newResult=0;
		for(int pos=0; (result>>pos)!=0; pos+=2){
			auto const digit=(result>>pos)&3;
			if(digit!=0) {
				newResult|=((digit+subindex-1)%3+1)<<pos;
			}
		}
		result=newResult;
	}
	std::cout<<result<<'\n';
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTest; std::cin>>numTest;
	while(numTest--) up();
}