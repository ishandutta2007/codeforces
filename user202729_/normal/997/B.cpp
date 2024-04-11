#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<bitset>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	std::bitset<10000> a{};
	a[0]=1;
	if(n*49LL<a.size()){
		for(int z=n;z--;) a|=a<<4|a<<9|a<<49;
		std::cout<<a.count()<<'\n';
	}else{
		auto const spread=[&](unsigned step){
			for(unsigned i=0;i+step<a.size();++i)
				a[i+step]=a[i+step] or a[i];
		};
		spread(4);
		spread(9);
		spread(49);
		auto out=(n*49LL+1)-((~a)<<(a.size()/2)).count();

		a={}; a[0]=1;
		spread(40);
		spread(45);
		spread(49);
		out-=((~a)<<(a.size()/2)).count();

		std::cout<<out<<'\n';
	}
}