// {the success probability of a random permutation is low}
//
// :(

#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numRow, numCol; std::cin>>numRow>>numCol;
	if(2*((numRow-1)*numCol+numRow*(numCol-1))>(numRow*numCol)*int64_t(numRow*numCol-1)/2
			or (
				std::min(numRow, numCol)==2 and
				std::max(numRow, numCol)==3
			   )
			){
		std::cout<<"NO\n";
		return 0;
	}
	std::vector<int> result(numRow*numCol);
	std::iota(begin(result),end(result), 1);
	std::mt19937 engine(10000);
	bool first=true;
	do{
continue_outer:
		if(first and numCol>2){
			first=false;
			for(int row=0;row<numRow;row+=2) {
				auto iterator=begin(result)+row*numCol;
				std::rotate(iterator, iterator+2, iterator+numCol);
			}
			for(int col=0;col<numCol;col+=2) {
				auto temp=result[(numRow-1)*numCol+col];
				for(int row=0;row<numRow;++row) {
					std::swap(temp, result[row*numCol+col]);
				}
			}
		}else{
			std::shuffle(begin(result),end(result), engine);
		}


		auto const adjacent=[&](int first, int sec){
			if(std::abs(first-sec)==numCol or
				(std::abs(first-sec)==1 and std::min(first, sec)%numCol!=0)
			  )
				return true;
			return false;
		};
		for(int index=0;index<(int)result.size()-numCol;++index) 
			if(adjacent(result[index], result[index+numCol])){
				goto continue_outer;
			}
		for(int index=0;index<(int)result.size();++index) 
			if(index%numCol!=numCol-1 and adjacent(result[index], result[index+1])) {
				goto continue_outer;
			}
		break;
	}while(true);

	std::cout<<"YES\n";
	for(int index=0;index<(int)result.size();++index) 
		std::cout<<result[index]<<(index%numCol==numCol-1 ?'\n':' ');
}