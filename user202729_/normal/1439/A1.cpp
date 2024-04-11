//...
#if not LOCAL
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
	int numRow; std::cin>>numRow;
	int numCol; std::cin>>numCol;
	std::vector data(numRow, std::vector<char>(numCol));
	for(auto& row: data){
		for(auto& cell: row){
			std::cin>>cell;
			cell-='0';
		}
	}

	std::vector<std::array<int, 6>> result;
	auto const operate=[&](std::array<int, 6> operation){
		result.push_back(operation);
		for(int i=0; i<6; i+=2){
			data[operation[i]][operation[i+1]]^=1;
		}
	};

	for(int row=0; row<numRow-2; ++row){
		for(int col=0; col<numCol; ++col){
			if(data[row][col]){
				operate({{row, col, row+1, col, row+1, col+(col==0 ? 1: -1)}});
			}
		}
	}
	for(int col=0; col<numCol-2; ++col){
		for(int row=numRow-2; row<numRow; ++row){
			if(data[row][col])
				operate({{row, col, row, col+1, row==numRow-1 ? numRow-2: numRow-1, col+1}});
		}
	}

	std::array<int, 8> cells{{
		numRow-2, numCol-2,
		numRow-2, numCol-1,
		numRow-1, numCol-2,
		numRow-1, numCol-1,
	}};
	std::array<int, 6> operation;
	for(int i=0; i<8; i+=2){
		for(int j=0; j<6; ++j) operation[j]=cells[j>=i ? j+2: j];
		int value{};
		for(int j=0; j<6; j+=2) value^=data[operation[j]][operation[j+1]];
		if(value) operate(operation);
	}
	
	for(int j=0; j<8; j+=2) assert(data[cells[j]][cells[j+1]]==0);
	std::cout<<result.size()<<'\n';
	for(auto const& row: result){
		for(auto const& cell: row){
			std::cout<<cell+1<<' ';
		}
		std::cout<<'\n';
	}
	
}