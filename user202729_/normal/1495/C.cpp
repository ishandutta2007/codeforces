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
	int numRow, numCol; std::cin>>numRow>>numCol;
	std::vector<std::string> data(numRow);
	for(auto& it: data){
		it.reserve(numCol);
		std::cin>>it;
		assert((int)it.size()==numCol);
	}
	for(int row=numRow%3==0; row<numRow; row+=3){
		if(row>=3){
			if(numCol>=2 and (
						data[row-1][1]=='X' or data[row-2][1]=='X'
						)){
				data[row-1][1]=data[row-2][1]='X';
			}else{
				data[row-1][0]=data[row-2][0]='X';
			}
		}
		data[row].assign(numCol, 'X');
	}
	for(auto const& row: data) std::cout<<row<<'\n';
}