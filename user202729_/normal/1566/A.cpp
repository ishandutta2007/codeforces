// time-limit: 1000
// problem-url: https://codeforces.com/contest/1566/problem/A

// not confident enough to participate in global round 18 :(

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
	int sum; std::cin>>sum;
	std::cout<<sum/(number/2+1)<<'\n';
}