#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

int n;
std::vector<std::string> query(int l,int r){
	assert(0<=l and l<r and r<=n);
	std::cout<<"? "<<l+1<<' '<<r<<std::endl;
	std::vector<std::string> a((r-l)*(r-l+1)/2);
	for(auto& row:a){
		std::cin>>row;
		std::sort(begin(row),end(row));
	}
	return a;
}

int main(){
	std::cin>>n;
	auto a=query(0,n);

	if(n==1){
		std::cout<<"! "<<a[0]<<'\n';
		return 0;
	}

	auto b=query(1,n);
	// a - b = prefixes

	assert(a.size()-b.size()==n);

	std::sort(begin(a),end(a));
	std::sort(begin(b),end(b));

	std::vector<std::string> prefixes(n);
	auto iter=std::set_difference(begin(a),end(a),begin(b),end(b),begin(prefixes));
	assert(end(prefixes)==iter);
	std::sort(begin(prefixes),end(prefixes),[](auto const& a,auto const& b){
			return a.size()<b.size();
			});

	for(unsigned i=0;i<prefixes.size();++i)
		assert((int)prefixes[i].size()==i+1);

	std::string out(n,' ');
	out[0]=prefixes[0][0];
	for(unsigned i=1;i<prefixes.size();++i){
		auto iter=std::set_difference(
				begin(prefixes[i]),end(prefixes[i]),begin(prefixes[i-1]),end(prefixes[i-1]),
				begin(out)+i);
		assert(iter==begin(out)+i+1);
	}

	std::cout<<"! "<<out<<'\n';
}