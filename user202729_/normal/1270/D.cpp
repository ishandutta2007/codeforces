#ifndef LOCAL
#define NDEBUG
#endif
#include<iostream>
#include<algorithm>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);

	int n,k;
	std::cin>>n>>k;

	int max=-1,maxcnt=0;

	for(int i=1;i<=k+1;++i){
		std::cout<<'?';
		for(int j=1;j<=k+1;++j)if(j!=i)std::cout<<' '<<j;
		std::cout<<std::endl;

		int pos,val;std::cin>>pos>>val;
		if(val>max) {max=val;maxcnt=1;}
		else if(val==max) ++maxcnt;
	}
	std::cout<<"! "<<maxcnt<<'\n';
}