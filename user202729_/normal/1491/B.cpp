// again? Did I not do any cf contest for that long?
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
	int numRow, verticalCost, horizontalCost;
	std::cin>>numRow>>verticalCost>>horizontalCost;
	int last; std::cin>>last;
	bool anyDiagonal=false, anySeparate=false;
	for(int i=1; i<numRow; ++i){
		int cur; std::cin>>cur;
		anyDiagonal=anyDiagonal or std::abs(last-cur)==1;
		anySeparate=anySeparate or std::abs(last-cur)>=2;
		last=cur;
	}
	if(anySeparate){ std::cout<<"0\n"; return; }
	if(anyDiagonal){ std::cout<<std::min(verticalCost, horizontalCost)<<'\n'; return; }
	std::cout<<horizontalCost+std::min(verticalCost, horizontalCost)<<'\n'; return;
}