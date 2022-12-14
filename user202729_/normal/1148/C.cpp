#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	std::vector<int> pos(number), value(number);
	for(int index=0;index<number;++index) {
		std::cin>>value[index];
		--value[index];
		pos[value[index]]=index;
	}

	std::vector<std::array<int, 2>> moves;
	moves.reserve(3*number);

	auto const swap=[&](int pos1, int pos2){
		if(pos1==pos2) return;
		assert(2*std::abs(pos1-pos2)>=number);
		moves.push_back({pos1+1, pos2+1});

		assert(pos[value[pos1]]==pos1);
		assert(pos[value[pos2]]==pos2);
		std::swap(value[pos1], value[pos2]);
		std::swap(pos[value[pos1]], pos[value[pos2]]);
	};

	auto const half=number>>1;
	assert((number&1)==0);

	auto const side=[&](int pos){
		return pos>=half;
	};

	auto const moveToCorner=[&](int pos){
		swap(pos, pos>=half ? 0: number-1);
	};

	auto const moveToCorrect=[&](int value){
		if(pos[value]==value) return;
		if(side(pos[value])!=side(value)) moveToCorner(pos[value]);
		moveToCorner(pos[value]);
		swap(pos[value], value);
	};

	for(int value=half; value--;){
		moveToCorrect(value);
		moveToCorrect(number-value-1);
	}

	for(int index=0;index<number;++index) assert(pos[index]==index);

	assert((int)moves.size()<=(3*number));
	std::cout<<moves.size()<<'\n';
	for(auto [x, y]: moves){
		std::cout<<x<<' '<<y<<'\n';
	}

}