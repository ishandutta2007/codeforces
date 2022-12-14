#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<vector>
#include<string>


int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n,m;std::cin>>n>>m;
	std::vector<std::string> s(n),t(m);
	for(auto& x:s)std::cin>>x;
	for(auto& x:t)std::cin>>x;

	int q;std::cin>>q;
	while(q--){
		int i;std::cin>>i;
		--i;
		std::cout<<s[i%n]<<t[i%m]<<'\n';
	}
}