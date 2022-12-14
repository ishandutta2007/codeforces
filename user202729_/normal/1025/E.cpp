// unproven :(
// Not tested 
//
#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

using Board=std::vector<std::vector<char>>;

int side, numPieces;

using Move=std::array<char, 4>;

auto solve(Board& board){
	// move all pieces to row 0

	std::vector<Move> result;
	for(int _=0;_<side;++_)
	for(int row=1;row<side;++row) {
		for(int col=0;col<side;++col)
			if(auto& cur=board[row][col]; cur>=0 and board[row-1][col]<0){
				result.push_back({row, col, row-1, col});
				std::swap(cur, board[row-1][col]);
			}
	}

	for(int row=side;--row;){
		for(int col=0;col<side;++col) if(auto& cur=board[row][col]; cur>=0){
			auto const newCol=int(board[0].rend()-std::find(board[0].rend()-col, board[0].rend(), -1))-1;
			if(newCol<0) continue;

			assert(newCol<col);
			for(int col1=col; col1>newCol; --col1) 
				result.push_back({row, col1, row, col1-1});

			for(int row1=row; row1--;) result.push_back({row1+1, newCol, row1, newCol});

			std::swap(cur, board[0][newCol]);
			assert(cur<0);
		}
		for(int col=side; col--;) if(auto& cur=board[row][col]; cur>=0){
			auto const newCol=std::find(col+begin(board[0]),end(board[0]), -1)-begin(board[0]);
			if(newCol==side) continue;
			assert(newCol>col);
			for(int col1=col; col1<newCol; ++col1)
				result.push_back({row, col1, row, col1+1});

			for(int row1=row; row1--;) result.push_back({row1+1, newCol, row1, newCol});

			std::swap(cur, board[0][newCol]);
			assert(cur<0);
		}
	}

	return result;
}

std::pair<std::vector<char>, std::vector<Move>> readBoard(){
	Board board(side, std::vector<char>(side, -1));
	for(int index=0;index<numPieces;++index) {
		int x, y;
		std::cin>>x>>y;
		assert(board[x-1][y-1]==-1);
		board[x-1][y-1]=index;
	}
	auto moves=solve(board);
	return {std::move(board[0]), std::move(moves)};
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::cin>>side>>numPieces;
	auto [before, movesBefore]=readBoard();
	auto [after, movesAfter]=readBoard();
	std::vector<Move> movesShuffle;


	for(int col=0;col<side;++col) if(int index=before[col]; index>=0){
		for(int row=0;row<index;++row) 
			movesShuffle.push_back({row, col, row+1, col});
	}
	for(int col=0;col<side;++col) if(int index=before[col]; index>=0){
		auto const newCol=std::find(begin(after),end(after), index)-begin(after);
		if(newCol<col){
			for(int col1=col; col1>newCol; --col1) 
				movesShuffle.push_back({index, col1, index, col1-1});
		}else if(newCol>col){
			for(int col1=col; col1<newCol; ++col1)
				movesShuffle.push_back({index, col1, index, col1+1});
		}
	}
	for(int col=0;col<side;++col) if(int index=after[col]; index>=0){
		for(int row=index; row--;)
			movesShuffle.push_back({row+1, col, row, col});
	}

	std::cout<<movesBefore.size()+movesAfter.size()+movesShuffle.size()<<'\n';
	for(auto x: movesBefore){
		for(int it: x) std::cout<<it+1<<' ';
		std::cout<<'\n';
	}
	for(auto x: movesShuffle){
		for(int it: x) std::cout<<it+1<<' ';
		std::cout<<'\n';
	}
	std::for_each(movesAfter.rbegin(),movesAfter.rend(),[&](auto x){
		std::cout<<x[2]+1<<' '<<x[3]+1<<' ';
		std::cout<<x[0]+1<<' '<<x[1]+1<<'\n';
	});
}