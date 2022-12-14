// time-limit: 1000
// problem-url: https://codeforces.com/contest/1616/problem/B
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
	int number; std::cin>>number;
	std::string s; std::cin>>s;
	if(s.size()>=2 and s[0]==s[1]){
		std::cout<<s[0]<<s[0]<<'\n';
	}else{
		// hopefully correct
		int i=1;
		while(i<(int)s.size() and s[i-1]>=s[i]) i++;
		for(int j=0; j<i; ++j)std::cout<<s[j];
		for(int j=i; j--;)std::cout<<s[j];
		std::cout<<'\n';
	}
}