#include<iostream>
#include<vector>
#include<algorithm>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	std::vector<std::pair<int64_t,int>> d(n); // {mask, weight}
	for(auto& x:d)std::cin>>x.first;
	for(auto& x:d)std::cin>>x.second;
	std::sort(begin(d),end(d)); // by mask
	int64_t ans=0;
	for(int i=n;i--;){
		// mark second = 0  => don't choose
		auto const f=d[i].first;
		if((i!=0&&f==d[i-1].first)||std::any_of(begin(d)+i+1,end(d),[f](std::pair<int64_t,int> a){
					return a.second!=0&&
						(f&a.first)==f; // f is a subset of a.first
					})){
			ans+=d[i].second;
			continue;
		}
		d[i].second=0;
	}
	std::cout<<ans<<'\n';
}