#include<iostream>
#include<algorithm>
#include<vector>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;

	std::vector<int64_t> funvalues;
	auto process=[&](int factor){
		// 1 + (1+factor) + (1+2*factor) + ... (n/factor terms)
		funvalues.push_back(n/factor*(n+2ULL-factor)/2);
	};

	for(int f=1;f*f<=n;++f){
		if(n%f==0){
			process(f);
			if(f*f<n)
				process(n/f);
		}
	}

	std::sort(funvalues.begin(),funvalues.end());
	funvalues.erase(std::unique(funvalues.begin(),funvalues.end()),funvalues.end());

	for(int64_t x:funvalues)std::cout<<x<<' ';
	std::cout<<'\n';
}