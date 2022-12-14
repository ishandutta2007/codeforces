#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n,x,y;std::cin>>n>>x>>y;
	std::string s;s.reserve(n);
	std::cin>>s;
	char last='1';
	int ndiff=0;
	for(char& c:s){ ndiff+=c!=last; last=c; }
	ndiff+='1'!=last;

	if(ndiff==0) std::cout<<"0\n";
	else std::cout<<(ndiff/2ULL-1)*std::min(x,y)+y<<'\n';
}