#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n; std::cin>>n;
	std::vector<int> a(n); for(auto& x: a) std::cin>>x;
	for(int bit=30; bit--;){
		if(std::count_if(begin(a),end(a),[&]( auto x){ return x>>bit &1; })==1){
			std::swap(a[0],*std::find_if(begin(a),end(a),[&]( auto x){ return x>>bit &1; }));
			break;
		}
	}
	for(auto x: a) std::cout<<x<<' ';
	std::cout<<'\n';
}