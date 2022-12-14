#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	int ax,ay;std::cin>>ax>>ay;
	int bx,by;std::cin>>bx>>by;
	int cx,cy;std::cin>>cx>>cy;
	std::cout<<(((bx<ax)==(cx<ax) and (by<ay)==(cy<ay)) ? "YES\n" : "NO\n");
}