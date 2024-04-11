#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	if(number<3){ std::cout<<"-1\n"; return 0; }
	if(number==3){
		std::cout<<"1 5 3\n8 2 7\n4 6 9";
		return 0;
	}
	std::vector<std::vector<int>> result(number, std::vector<int>(number));
	int cur=number*number;
	int row=0, col=0;
	while(row<number-3){
		result[row][col]=cur--;
		++row;
	}
	result[number-1][1]=cur--;
	result[number-1][0]=cur--;
	result[number-2][1]=cur--;
	result[number-2][0]=cur--;
	result[number-3][0]=cur--;
	row=number-3; col=1;
	while(col<number){
		result[row][col]=cur--;
		if(col%2==1) {
			if(row==0) ++col;
			else --row;
		}else {
			if(row==number-1) ++col;
			else ++row;
		}
	}
	assert(cur==0);
	for(auto & it: result){
		for(auto it: it) std::cout<<it<<' ';
		std::cout<<'\n';
	}
}