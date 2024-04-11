#ifndef LOCAL
#define NDEBUG
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	if(n%4!=0){
		std::cout<<"! -1\n";
		return 0;
	}
	auto const val=[](int i){
		std::cout<<"? "<<++i<<std::endl;
		int ai;std::cin>>ai;
		return ai;
	};

	int l=0,r=n/2u;
	{
		int vall=val(l),valr=val(r);
		if(vall==valr){ std::cout<<"! 1\n"; return 0; }
		if(vall<valr) std::swap(l,r);
	}

	int const lastl=l+n/2u;
	for(int step=1<<20;step>>=1;)if(l+step<lastl){
		auto vall1=val(l+step),valr1=val(r+step);
		if(vall1>valr1){ l+=step; r+=step; }
		else if(vall1==valr1){ std::cout<<"! "<<l+step+1<<'\n'; return 0; }
	}

	assert(0);
}