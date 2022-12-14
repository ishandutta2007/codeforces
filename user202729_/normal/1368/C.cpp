#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	std::cout<<number*3+4<<'\n';
	for(int i=0; i<=number; ++i)
		std::cout
			<<i<<' '<<i<<'\n'
			<<i+1<<' '<<i<<'\n'
			<<i<<' '<<i+1<<'\n';
	std::cout<<number+1<<' '<<number+1<<'\n';
}