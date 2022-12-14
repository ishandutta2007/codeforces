#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	std::vector<int> b(number);for(auto & it: b) std::cin>>it;
	std::vector<int> x(number), a(number);
	for(int index=0;index<number;++index) {
		a[index]=b[index]+x[index];
		if(index+1!=number)
			x[index+1]=std::max(x[index], a[index]);
		std::cout<<a[index]<<' ';
	}
}