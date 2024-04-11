#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int64_t number; std::cin>>number;
	int small=1, smallCount=10;
	int64_t result=1;
	while(result<number){
		if(smallCount==0){small+=1; smallCount=10;}
		smallCount--;
		result=result/small*(small+1);
	}

	for(int i=0; i<10; ++i)
		std::cout<<std::string(i<smallCount ? small: small+1, "codeforces"[i]);
	std::cout<<'\n';
}