#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

using P=std::vector<short>;

bool check(P const& it){
	return std::all_of(begin(it),end(it), [&](auto it){ return -1<=it and it<=1; });
}

size_t numStep;

void solve(P const& small, P const& large){
	// -> solve(large, small+large*something)
	if(small.size()==numStep) {
		std::cout<<large.size()-1<<'\n';
		for(auto it: large) std::cout<<(large.back()<0 ? -it : it)<<' ';
		std::cout<<'\n'<<small.size()-1<<'\n';
		for(auto it: small) std::cout<<(small.back()<0 ? -it : it)<<' ';
		std::cout<<'\n';
		std::exit(0);
	}
	assert(large.size()==small.size()+1);

	P larger=small;
	larger.push_back(0); larger.push_back(0);

	auto const plus_twice=[&](auto first, auto sec){ return first+sec*2; };


	std::transform(larger.begin()+1, larger.end(), begin(large), larger.begin()+1, std::minus<>());
	if(check(larger)) solve(large, larger);
	std::transform(larger.begin()+1, larger.end(), begin(large), larger.begin()+1, plus_twice);
	if(check(larger)) solve(large, larger);
	//std::transform(larger.begin()+1, larger.end(), begin(large), larger.begin()+1, std::minus<>());

}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::cin>>numStep;
	solve({1}, {0, 1});
}