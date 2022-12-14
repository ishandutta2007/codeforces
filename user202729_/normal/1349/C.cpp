#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numRow, numCol, numQuery; std::cin>>numRow>>numCol>>numQuery;
	std::vector<std::string> data(numRow);
	for(auto & row: data){row.reserve(numCol); std::cin>>row;
		assert((int)row.size()==numCol);
		for(auto & ch: row) ch=char(ch-'0');
	}

	std::vector<std::vector<int>> distance(numRow, std::vector<int>(numCol, INT_MAX));
	std::queue<std::pair<int, int>> pos;

	auto const setFixed=[&](int row, int col){
		if(distance[row][col]!=0){
			distance[row][col]=0;
			pos.push({row, col});
		}
	};
	for(int row=0;row<numRow;++row) 
		for(int col=1;col<numCol;++col) 
			if(data[row][col-1]==data[row][col]){
				setFixed(row, col-1);
				setFixed(row, col);
			}

	for(int row=1;row<numRow;++row) 
		for(int col=0;col<numCol;++col) 
			if(data[row-1][col]==data[row][col]){
				setFixed(row-1, col);
				setFixed(row, col);
			}

	while(not pos.empty()){
		auto [row, col]=pos.front(); pos.pop();
		auto const nextDistance=distance[row][col]+1;
		for(int _=0, dr=1, dc=0; _<4; ++_, std::swap(dr, dc), dr=-dr)
			if(unsigned(row+dr)<(unsigned) numRow and unsigned(col+dc)<(unsigned) numCol){
				if(distance[row+dr][col+dc]==INT_MAX){
					distance[row+dr][col+dc]=nextDistance;
					pos.push({row+dr, col+dc});
				}
			}
	}

	while(numQuery--){
		int row, col; int64_t numStep; std::cin>>row>>col>>numStep;
		--row;--col;
		if(distance[row][col]==INT_MAX){
			std::cout<<char('0'+data[row][col])<<'\n';
			continue;
		}
		std::cout<<char('0'+(
					data[row][col] xor
					(std::min(numStep, (int64_t)distance[row][col])&1) xor
					(numStep&1)
					))<<'\n';
	}
}