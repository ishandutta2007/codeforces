#include<iostream>
#include<algorithm>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int y,b,r;std::cin>>y>>b>>r;
	std::cout<<3*std::min({y,b-1,r-2})+3<<'\n';
}