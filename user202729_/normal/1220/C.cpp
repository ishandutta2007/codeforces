#include<iostream>
#include<string>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::string s;std::cin>>s;
	char minc='z'+1;
	for(char c:s){
		if(c<=minc){
			minc=c;
			std::cout<<"Mike\n";
		}else{
			std::cout<<"Ann\n";
		}
	}
}