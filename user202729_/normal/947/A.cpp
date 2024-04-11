#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int x2;std::cin>>x2;
	std::vector<char> composite(std::max(10,x2+1));
	for(int i=2;i*i<(int)composite.size();++i)if(not composite[i])
		for(int j=i*i;j<(int)composite.size();j+=i)
			composite[j]=true;

	auto const max_proper_non_composite_divisor=[&composite](int x){
		auto const x_old=x;
		assert(x>=1);
		if(x==1) assert(not composite[x]);
		if(not composite[x]) return 1;

		int a=2;
		while(composite[x]){
			while(x%a!=0) ++a;
			x/=a;
		}
		return x;
	};

	int min_x0=x2;
	for(int x1=x2-max_proper_non_composite_divisor(x2)+1;x1<=x2;++x1)
		min_x0=std::min(min_x0,x1-max_proper_non_composite_divisor(x1)+1);
	std::cout<<min_x0<<'\n';
}