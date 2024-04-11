#include<iostream>
#include<vector>
#include<array>
#include<algorithm>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	std::array<int,63> cnt{}; // cnt[i] = number of values with ctz == i
	std::vector<int64_t> bs(n);
	for(int64_t& b:bs){
		std::cin>>b;
		++cnt[__builtin_ctzll(b)];
	}

	int keepctz=std::max_element(begin(cnt),end(cnt))-begin(cnt);
	std::cout<<n-cnt[keepctz]<<'\n';
	for(int64_t& b:bs){
		if(keepctz!=__builtin_ctzll(b))
			std::cout<<b<<' ';
	}
	std::cout<<'\n';
}