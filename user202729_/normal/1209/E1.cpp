#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

void up(){
	int numRow, numCol; std::cin>>numRow>>numCol;
	std::vector<std::vector<int>> cols(numCol, std::vector<int>(numRow));
	for(int row=0;row<numRow;++row) 
		for(int col=0;col<numCol;++col) 
			std::cin>>cols[col][row];

	std::vector<int> result(1<<numRow);
	std::vector<int> next, tmp; 
	for(auto col: cols){
		next=result;
		for(int _=0;_<numRow;++_, std::rotate(begin(col), begin(col)+1, end(col)) ) {
			tmp=result;

			for(int index=0;index<numRow;++index) 
				for(int mask=0;mask<(int)tmp.size();++mask) {
					auto const cur=tmp[mask];
					if(not(mask>>index&1)){
						auto & it=tmp[mask|1<<index];
						it=std::max(it, cur+col[index]);
					}
				}

			std::transform(begin(tmp),end(tmp), begin(next), begin(next),[&](int first, int sec){
				return std::max(first, sec);
			});
		}
		std::swap(result, next);
	}

	std::cout<<result.back()<<'\n';
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTest; std::cin>>numTest;
	while(numTest--) up();
}