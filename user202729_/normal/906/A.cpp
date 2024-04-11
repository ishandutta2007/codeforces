#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::array<bool, 26> fail{};
	int number; std::cin>>number;
	std::string string;
	bool unique=false;
	int result=0;
	for(int index=0;index<number;++index){
		char type; std::cin>>type>>string;
		switch(type){
			case '.':
				for(auto ch: string) fail[ch-'a']=true;
				break;
			case '?':
				{
					auto const ch=string[0];
					if(index==number-1){
						assert(not fail[ch-'a']);
						for(auto & x: fail) x=true;
						fail[ch-'a']=false;
					}else{
						result+=unique;
						fail[ch-'a']=true;
					}
				}
				break;
			case '!':
				result+=unique;
				for(int ch=0;ch<26;++ch) if(not fail[ch] and string.find(ch+'a')==std::string::npos)
					fail[ch]=true;
				break;
			default:
				assert(false);
				__builtin_unreachable();
		}
		assert(std::accumulate(begin(fail),end(fail), 0)!=(int)fail.size());
		if(std::accumulate(begin(fail),end(fail), 0)==(int)fail.size()-1){
			unique=true;
		}
	}
	std::cout<<result<<'\n';
}