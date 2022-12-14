#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<vector>
#include<algorithm>
#include<iostream>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n,h;std::cin>>n>>h;
	std::vector<int> a(n);
	for(auto& ai:a)std::cin>>ai;
	auto iter=begin(a);
	while(iter!=end(a)){
		auto it2=iter;
		while(it2!=begin(a) and it2[-1]>*it2){
			std::swap(*it2,it2[-1]);
			--it2;
		}

		assert(std::is_sorted(begin(a),iter+1));
		it2=iter;
		int minheight=0;
		for(;;){
			minheight+=*it2;
			if(it2-begin(a)>=2)
				it2-=2;
			else break;
		}
		if(minheight>h){
			break;
		}else
			++iter;
	}
	std::cout<<iter-begin(a)<<'\n';
}