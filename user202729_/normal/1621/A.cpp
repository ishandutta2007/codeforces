// time-limit: 1000
// problem-url: https://codeforces.com/contest/1621/problem/A
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
	int k; std::cin>>k;
	if(k>(n+1)/2){
		std::cout<<"-1\n"; return;
	}
	for(int row=0; row<n; ++row){
		for(int col=0; col<n; ++col)
			std::cout<<((row%2==0 and row==col and row<k*2) ? 'R':'.');
		std::cout<<'\n';
	}

}