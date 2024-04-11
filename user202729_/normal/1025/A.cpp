#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	std::array<int, 26> count{};
	for(int _=0;_<number;++_) {
		char ch; std::cin>>ch;
		++count[ch-'a'];
	}
	std::cout<<(
			(*std::max_element(begin(count),end(count))<2 and number>1)
			? "No\n":"Yes\n");
}