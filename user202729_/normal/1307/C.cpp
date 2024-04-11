// :(
#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::string string; std::cin>>string;
	std::array<int, 26> countBefore{};
	std::array<std::array<int64_t, 26>, 26> count{};
	for(auto ch: string){
		ch-='a';
		for(int other=0;other<26;++other) 
			count[other][ch]+=countBefore[other];
		++countBefore[ch];
	}

	int64_t out=*std::max_element(begin(countBefore),end(countBefore));
	for(auto const& item: count)
		out=std::max(out,*std::max_element(begin(item),end(item)));
	 std::cout<<out<<'\n';
}