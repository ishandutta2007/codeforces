// time-limit: 1000
// problem-url: https://codeforces.com/contest/1566/problem/B

// as expected of a Div. 1+2 round initial problems are easy

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
	if(std::all_of(begin(s), end(s), [&](auto const& it){
		return it=='1';
	})){
		std::cout<<"0\n";
	}else if(std::find(
				std::find(
				std::find(begin(s), end(s), '0'),
				s.end(), '1'),
				s.end(), '0')==s.end()){
		std::cout<<"1\n";
	}else{
		std::cout<<"2\n";
	}
}