#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<vector>
#include<iostream>
#include<algorithm>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::vector<std::vector<int>> branch; // [0]: node index, >0: connected nodes
	int n;std::cin>>n;
	branch.reserve(2*n);branch.resize(n,{-1});

	std::vector<std::pair<int,int>> d(n);
	for(int i=0;i<n;++i){
		std::cin>>d[i].first;
		d[i].second =i;
	}
	std::sort(begin(d),end(d),[](auto m,auto n){return m.first>n.first;});

	for(int i=0;i<n;++i){
		auto [di,ind]=d[i];
		assert(branch[i][0]<0);
		branch[i][0]=ind*2+1;
		int j=i+di-1;
		if(j==(int)branch.size()-1)
			branch.emplace_back(1,ind*2+2);
		else
			branch[j].push_back(ind*2+2);
	}

	for(unsigned i=1;i<branch.size();++i)
		std::cout<<branch[i-1][0]<<' '<<branch[i][0]<<'\n';
	for(auto& b:branch)
		for(unsigned i=1;i<b.size();++i)
			std::cout<<b[0]<<' '<<b[i]<<'\n';
}