#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

std::vector<std::string> black;

int numRow, numCol;
bool valid(unsigned row, unsigned col){ return row<(unsigned) numRow and col<(unsigned) numCol; }

void flood(int row, int col){
	assert(black[row][col]);
	black[row][col]=false;
	for(int _=0, dx=1, dy=0;_<4;++_, std::swap(dx, dy), dx=-dx) 
		if(valid(row+dx, col+dy) and black[row+dx][col+dy])
			flood(row+dx, col+dy);
}


int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::cin>>numRow>>numCol;
	black.resize(numRow);

	auto const check=[&](auto get, int len)->std::array<bool, 2>{
		// {set of true (black) is continuous or empty, is empty}

		bool opened=false, closed=false;
		for(int index=0;index<len;++index) {
			if(get(index)){
				if(closed) return {false, false};
				opened=true;
			}else{
				if(opened) closed=true;
			}
		}
		return {true, not opened};
	};

	bool hasEmptyRow{}, hasEmptyCol{};
	for(auto & it: black){
		it.reserve(numCol);
		std::cin>>it;
		assert((int)it.size()==numCol);
		for(auto & ch: it) ch=(ch=='#');
		auto const [okay, empty]=check([&](int index){ return it[index]; }, numCol);
		if(not okay){
			std::cout<<"-1\n"; return 0;
		}
		if(empty) hasEmptyRow=true;
	}
	for(int col=0;col<numCol;++col) {
		auto const [okay, empty]=check([&](int index){ return black[index][col]; }, numRow);
		if(not okay){
			std::cout<<"-1\n"; return 0;
		}
		if(empty) hasEmptyCol=true;
	}
	if(hasEmptyRow!=hasEmptyCol){
		std::cout<<"-1\n"; return 0;
	}

	int numComponent{};
	for(int row=0;row<numRow;++row) 
		for(int col=0;col<numCol;++col) 
			if(black[row][col]){
				flood(row, col);
				++numComponent;
			}

	std::cout<<numComponent<<'\n';
}