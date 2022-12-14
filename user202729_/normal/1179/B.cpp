#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n,m;std::cin>>n>>m;
	for(int r=1,r1;
			r<=(r1=n+1-r);
			++r){
		for(int c=1,c1;
				(c1=m+1-c), (c<=m and std::make_pair(r,c)<=std::make_pair(r1,c1));
				++c){
			std::cout<<r<<' '<<c<<'\n';
			if(std::make_pair(r,c)<std::make_pair(r1,c1))
				std::cout<<r1<<' '<<c1<<'\n';
		}
	}
}