// time-limit: 1000
// problem-url: https://codeforces.com/contest/1580/problem/A


// way too slow to figure out solution (it's just straightforward O(n) ...)
// also constant factors a little large
//
// is there a better solution?

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
	std::vector<std::string> data(numRow); for(auto& row: data){
		std::cin>>row;
		assert((int)row.size()==numCol);
		for(auto& ch: row) ch-='0';
	}

	std::vector sum(numRow+1, std::vector<int>(numCol+1)); // 2D suffix inclusive
	for(int row=numRow; row--;) for(int col=numCol; col--;)
		sum[row][col]=data[row][col]+sum[row+1][col]+sum[row][col+1]-sum[row+1][col+1];

	std::vector sumRight(numRow, std::vector<int>(numCol+1)); // sum suffix inclusive over row
	for(int row=numRow; row--;) for(int col=numCol; col--;)
		sumRight[row][col]=data[row][col]+sumRight[row][col+1];

	std::vector<std::vector<int>> f(numCol+1);

	int row=-1;
	// f[right][left]=minimum numChanges of rows <=row such that cols from left... right
	// forms a portal-upper
	for(int right=4; right<=numCol; ++right) f[right].resize(right-3, INT_MAX/2); // simplify implementation but slightly slower...

	int result=INT_MAX;
	while(true){
		row++;
		if(row+4==numRow) break;
		for(int right=4; right<=numCol; ++right)
			for(int left=0; right-left>=4; ++left){
				auto const numOneInnerSegment=sumRight[row][left+1]-sumRight[row][right-1];

				f[right][left]=std::min(
						// case 1: top row is not row
						f[right][left]+
						(data[row][left]!=1)+
						(data[row][right-1]!=1)+
						numOneInnerSegment
						,
						// case 2: top row is this row
						right-left-2-numOneInnerSegment
						);

				auto const curResult=
					f[right][left]

					+
					sum[row+1][left+1]
					-sum[row+1][right-1]
					-sum[row+4][left+1]
					+sum[row+4][right-1] // inner

					+(data[row+1][left]==0)
					+(data[row+2][left]==0)
					+(data[row+3][left]==0) // left vertical border

					+(data[row+1][right-1]==0)
					+(data[row+2][right-1]==0)
					+(data[row+3][right-1]==0) // right vertical border

					+(right-left-2-(sumRight[row+4][left+1]-sumRight[row+4][right-1])) // down segment (number of zeroes in inner segment)
					;
					
				result=std::min(result, curResult);
			}
	}
		
		std::cout<<result<<'\n';
	
}