#ifndef LOCAL
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
	int a, b, n; std::cin>>a>>b>>n;
	int result=0;
	while(std::max(a, b)<=n){
		++result;
		if(a<b) std::swap(a, b);
		b+=a;
	}
	std::cout<<result<<'\n';
}