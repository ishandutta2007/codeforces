// Took about 5 minutes to solve. Implementation time should be negligible.
#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<climits>
#include<iostream>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	int min=INT_MAX,mincnt=0;
	for(int i=0;i<n;++i){
		int ai;std::cin>>ai;
		if(ai==min) ++mincnt;
		else if(ai<min) { min=ai; mincnt=1; }
	}
	std::cout<<(mincnt>n/2 ? "Bob\n" : "Alice\n");
}