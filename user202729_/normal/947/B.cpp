#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	std::vector<int> inisize(n); for(auto& x:inisize) std::cin>>x;
	std::vector<int> temp(n); for(auto& x:temp) std::cin>>x;

	std::multiset<int64_t> value;
	int64_t offset=0;

	for(int i=0;i<n;++i){
		value.insert(inisize[i]-offset);

		int64_t out=0;
		while(not value.empty()){
			auto v0=offset+*value.begin();
			assert(v0>=0);
			if(v0<=temp[i]){
				out+=v0;
				value.erase(value.begin());
			}else break;
		}

		out+=temp[i]*(int64_t)value.size();
		offset-=temp[i];

		std::cout<<out<<' ';
	}
	std::cout<<'\n';
}