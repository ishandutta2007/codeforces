#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::string string; std::cin>>string;
	char last='b'; int count=0, result=1;
	for(auto x: (string+string)){
		if(x!=last){
			++count;
		} else count=1;
		result=std::max(result, count);
		last=x;
	}
	std::cout<<std::min(result,(int)string.size())<<'\n';
}