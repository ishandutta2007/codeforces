#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	std::vector<int64_t> c(n);
	{
		int64_t t;
		std::cin>>t;
		for(auto& x:c){ std::cin>>x; x+=t; }
	}
	std::vector<int> x(n);for(auto& y:x){ std::cin>>y;--y; }

	if(not std::is_sorted(begin(x),end(x))){
		std::cout<<"No\n"; return 0;
	}

	std::vector<int> tt(n);
	std::vector<char> force_not_tt(n);
	for(int i=0;i<n;++i){
		if(x[i]<i){
			std::cout<<"No\n"; return 0;
		}
		if(i<x[i]){
			++tt[i+1];
			if(x[i]+1<n){
				--tt[x[i]+1];
				force_not_tt[x[i]+1]=true;
			}
		}
	}
	std::partial_sum(begin(tt),end(tt),begin(tt));
	// now tt[i] = (c[i] <= b[i-1])

	for(int i=1;i<n;++i){
		if((tt[i] and force_not_tt[i]) or (tt[i-1] and not tt[i] and c[i]-c[i-1]==1)){
			std::cout<<"No\n"; return 0;
		}
	}

	int64_t last=0;
	std::cout<<"Yes\n";
	for(int i=0;i<n;++i){
		++last;
		last=std::max(last,c[i]);
		if(i+1<n and tt[i+1]) last=std::max(last,c[i+1]);
		std::cout<<last<<' ';
	}
	std::cout<<'\n';
}