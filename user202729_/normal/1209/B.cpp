#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	std::string state;
	state.reserve(number);
	std::cin>>state;
	for(auto &x: state) x-='0';
	assert((int)state.size()==number);

	std::vector<std::pair<int, int>> value(number);
	for(auto & [a, b]: value) std::cin>>a>>b;

	int result=0;
	for(int step=0;step<135;++step) {
		result=std::max(result, (int)std::count(begin(state),end(state), 1));
		for(int index=0;index<number;++index) {
			auto[a, b]=value[index];
			if(step>=b and (step-b)%a==0)
				state[index]^=1;
		}
	}

	std::cout<<result<<'\n';
}