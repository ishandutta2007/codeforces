#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	std::array<std::array<int, 2>, 2> pos{{
		{0, 0},
		{0, 1}
	}};

	auto const colorDifferent=[&](int a, int b){
		int i=0;
		while(i==a or i==b) i++;
		assert(a<3); assert(b<3);
		assert(a>=0); assert(b>=0);
		return i;
	};

	auto const full=[&](int parity){
		return pos[parity][0]>=number;
	};

	for(int _=0; _<number*number; ++_){
		int color; std::cin>>color;
		--color;

		// color: 0~ 2
		// parity: 0~ 1
		int chosenColor, chosenParity;
		if(full(0)){ // by construction (*), filled with color 0
			chosenColor=colorDifferent(color, 0);
			chosenParity=1;
		}else if(full(1)){ // by construction (*), filled with color 1
			chosenColor=colorDifferent(color, 1);
			chosenParity=0;
		}else{
			chosenColor=colorDifferent(color, 2);
			chosenParity=chosenColor; // (*)
		}

		assert(not full(chosenParity));
		assert(chosenColor!=color);

		std::cout<<chosenColor+1<<' '
			<<pos[chosenParity][0]+1<<' '
			<<pos[chosenParity][1]+1<<std::endl;

		pos[chosenParity][1]+=2;
		if(pos[chosenParity][1]>=number){
			pos[chosenParity][0]++;
			pos[chosenParity][1]=(pos[chosenParity][0]^chosenParity)&1;
		}
	}
	assert(full(0)); assert(full(1));
}