#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<vector>
#include<algorithm>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;

	std::vector<int> f; // slope-changing points int the dp function sorted int increasing order
	int64_t min=0;

	for(int i=0;i<n;++i){
		int ai;std::cin>>ai;
		ai-=i; // strictly increasing -> not strictly increasing

		if(f.empty() or ai>=f.back()){
			f.push_back(ai);
			continue;
		}

		int x=f.back();
		min+=x-ai;

		int added[]={ai,ai};
		f.insert(std::lower_bound(begin(f),end(f),ai), std::begin(added),std::end(added));
		assert(std::is_sorted(begin(f),end(f)));
		f.pop_back();
	}
	std::cout<<min<<'\n';
}