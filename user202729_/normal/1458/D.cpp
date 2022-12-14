// surprisingly simple to implement?
#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

void up();
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTest; std::cin>>numTest;
	while(numTest--) up();
}

void up(){
	std::string s; std::cin>>s;
	std::vector<int> count(s.size()*2);
	int degree=(int)s.size();
	for(auto& ch: s){
		ch-='0';
		if(ch){
			++count[degree];
			degree++;
		}else{
			--degree;
			++count[degree];
		}
	}

	degree=(int)s.size();
	for(int _=0; _<(int)s.size(); ++_){
		if(count[degree-1]>=2 or (count[degree-1]==1 and count[degree]==0)){
			std::cout<<'0';
			--degree;
			assert(count[degree]);
			--count[degree];
		}else{
			std::cout<<'1';
			assert(count[degree]);
			--count[degree];
			++degree;
		}
	}
	std::cout<<'\n';
}