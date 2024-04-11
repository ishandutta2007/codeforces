// Figured out the solution after about 10 hours of thinking (4 hours if excludes sleeping)
// I wonder if I can solve this if it appears int some 5 hours contest.
//#include"range/v3/all.hpp"

#ifndef LOCAL
#define NDEBUG
#endif
#include<numeric>
#include<cassert>
#include<iostream>
#include<vector>

std::vector<int> a;
int n;

void swapop(int x,int y){
	std::swap(a[x],a[y]);
	std::cout<<x+1<<' '<<y+1<<'\n';
}

void swap0(int x,int y,int z){
	// equivalent to swapop(x,y)
	//for(int t:ranges::views::ints(z,(int)a.size()))
	for(int t=z;t<(int)a.size();t++)
		swapop(x,t);
	swapop(x,y);
	for(unsigned t=a.size();t-->z;)
	//for(int t:ranges::views::ints(z,(int)a.size())|ranges::views::reverse)
		swapop(y,t);
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::cin>>n;
	if(n%4==2 or n%4==3){
		std::cout<<"NO\n";return 0;
	}

	std::cout<<"YES\n";
	//a=ranges::views::ints(0,n)|ranges::to<std::vector<int>>();
	a.resize(n);std::iota(begin(a),end(a),0);
	//for(int i:ranges::views::ints(0,n-1)
	//		|ranges::views::stride(4))
	for(int i=0;i<n-1;i+=4)
	{
		swap0(i,i+1,  i+4);
		swap0(i+2,i+3,i+4);
		for(auto [x,y]:{
				std::pair<int,int>{1,3},
				{0,2},{1,2},{0,3}})
			swapop(i+x,i+y);
		//assert(ranges::equal(a,ranges::views::ints(0,n)));
	}

	std::cout<<std::flush;
	//assert(ranges::equal(a,ranges::views::ints(0,n)));
	for(int i=0;i<n;++i) assert(a[i]==i);
}