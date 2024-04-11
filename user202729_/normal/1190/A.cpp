#include<iostream>
#include<vector>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int64_t n,pagesize;
	int nspecial;
	std::cin>>n>>nspecial>>pagesize;

	int64_t base=0;
	int ans=0;
	int64_t lastpage_end=-1;

	for(int _=nspecial;_--;){
		int64_t x;std::cin>>x;
		if(lastpage_end<x){
			++ans;
			lastpage_end=base+(x-base+pagesize-1)/pagesize*pagesize;
		}
		++base;
	}

	std::cout<<ans<<'\n';
}