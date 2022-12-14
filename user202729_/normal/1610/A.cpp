// time-limit: 1000
// problem-url: https://codeforces.com/contest/1610/problem/A

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
	int n; std::cin>>n;
	int m; std::cin>>m;
	
	if(n==1 and m==1){
		std::cout<<"0\n";
	}else if(n==1 or m==1){
		std::cout<<"1\n";
	}else{
		std::cout<<"2\n";
	}
}