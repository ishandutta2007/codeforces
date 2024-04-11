// time-limit: 1000
// problem-url: https://codeforces.com/contest/1603/problem/B
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
	int x; std::cin>>x;
	int y; std::cin>>y;
	
	int n;
	if(y<x) n=x+y;
	else n=y-(y%x)/2;
	assert(n%x==y%n);
	std::cout<<n<<'\n';
}