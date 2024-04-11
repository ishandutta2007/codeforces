// {missed the a[i]<a[i+1] restriction while reading the statement. Makes the problem slightly harder.}
// [I've seen the standing table]
#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

void up(){
	int d, mod; std::cin>>d>>mod;
	++d;
	int result=1;
	int left=1;
	while(left<d){
		auto const right=std::min(left*2, d);
		assert(right>left);
		result=int(result*(int64_t)(right-left+1)%mod);
		left=right;
	}
	result=(result+mod-1)%mod; // empty sequence
	std::cout<<result<<'\n';
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTest; std::cin>>numTest;
	while(numTest--) up();
}