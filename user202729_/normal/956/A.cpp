#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numRow, numCol; std::cin>>numRow>>numCol;
	std::vector<std::string> table(numRow);
	for(auto & row: table) std::cin>>row;
	for(int r1=0;r1<numRow;++r1) 
	for(int r2=0;r2<numRow;++r2) 
	for(int c1=0;c1<numCol;++c1) 
	for(int c2=0;c2<numCol;++c2) 
		if(
				(table[r1][c1]=='#')+
				(table[r1][c2]=='#')+
				(table[r2][c1]=='#')+
				(table[r2][c2]=='#')
				==3){
			std::cout<<"No\n";
			return 0;
		}

	std::cout<<"Yes\n";
}