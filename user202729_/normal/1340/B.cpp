#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

std::array<int, 10> digits={{
0b1110111,
0b0010010,
0b1011101,
0b1011011,
0b0111010,
0b1101011,
0b1101111,
0b1010010,
0b1111111,
0b1111011
}};

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numDigit, numBroken; std::cin>>numDigit>>numBroken;
	std::vector<int> values(numDigit);
	for(auto & it: values){
		for(int _=0;_<7;++_) {
			char ch; std::cin>>ch;
			assert(ch=='0' or ch=='1');
			it=it*2+(ch-'0');
		}
	}

	std::vector<std::vector<char>> possible(numDigit+1, std::vector<char>(numBroken+1));
	// possible[index][numBroken] = problem with [index...] and numBroken
	possible.back()[0]=true;

	for(auto index=numDigit; index--;){
		for(int numBrokenNext=0;numBrokenNext<=numBroken;++numBrokenNext) if(possible[index+1][numBrokenNext]){
			for(int curDigit: digits) if((values[index]&curDigit)==values[index]){
				int const numBrokenHere=__builtin_popcount(curDigit^values[index]);
				assert((int)possible[index].size()==numBroken+1);
				if(numBrokenNext+numBrokenHere<=numBroken)
					possible[index][numBrokenNext+numBrokenHere]=true;
			}
		}
	}

	if(not possible[0][numBroken]){
		std::cout<<"-1\n"; return 0;
	}
	
	int index=0;
	while(index<numDigit){
		for(int curDigitValue=9; ; --curDigitValue){
			int const curDigit=digits[curDigitValue];
			if((values[index]&curDigit)==values[index]){
				int const numBrokenHere=__builtin_popcount(curDigit^values[index]);
				if(numBroken-numBrokenHere>=0 and possible[index+1][numBroken-numBrokenHere]){
					numBroken-=numBrokenHere;
					std::cout<<char('0'+curDigitValue);
					break;
				}
			}
		}
		++index;
	}
	std::cout<<'\n';
}