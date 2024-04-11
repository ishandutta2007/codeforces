#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

void up();
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTest; std::cin>>numTest;
	while(numTest--) up();
}

auto const data=[]{
	std::array<int, 100> data;
	data.fill(INT_MIN);
	data[0]=0;
	for(int i=4; i<(int)data.size(); ++i)
		for(int j=2; j*j<=i; ++j) if(i%j==0){
			// i is composite
			for(int k=i; k<(int)data.size(); ++k)
				if(data[k-i]!=INT_MIN)
					data[k]=std::max(data[k], data[k-i]+1);

			break;
		}
	return data;
}();

void up(){
	int number; std::cin>>number;
	int result=number<(int)data.size() ? 0: ((number-(int)data.size())/4+1);
	number-=result*4; result=data[number]==INT_MIN ? -1: result+data[number];
	std::cout<<result<<'\n';
}