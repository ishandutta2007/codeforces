// >.<
#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<string>
#include<vector>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::string s;std::cin>>s;
	char const VERT='0';
	char const HORZ='1';

	int row=1,col=1;
	for(char c:s){
		if(c==VERT){
			std::cout<<row <<" 4\n";
			row^=2;
		}else{
			std::cout<<"4 "<<col<<'\n';
			col^=2;
		}
	}
}