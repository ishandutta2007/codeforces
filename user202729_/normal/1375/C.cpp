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

void up(){
	int number; std::cin>>number;
	std::vector<int> value(number), minPrefix(number);
	for(int cur=INT_MAX, i=0; i<number; ++i){
		std::cin>>value[i];
	}
	std::cout<<(value[0]<value.back() ? "YES\n": "NO\n");
	
}