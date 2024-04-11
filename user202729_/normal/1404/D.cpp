// not easier than C.
#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	if(number%2==0){
		std::cout<<"First\n";
		for(int j=0; j<2; ++j)
			for(int i=0; i<number; ++i)
				std::cout<<i+1<<' ';
		std::cout<<'\n';
	}else{
		std::cout<<"Second\n"<<std::flush;
		std::vector<int> other(number*2+1); // number -> other in the other (*) 1-indexing 
		{ // read other
			std::vector<int> pairIndexToFirst(number); // other index-1 -> pairIndexToFirst number
			for(int i=1; i<=number*2; ++i){
				int pairIndex; std::cin>>pairIndex;--pairIndex;
				if(auto const j=pairIndexToFirst[pairIndex]){
					assert(other[i]==0); assert(other[j]==0);
					other[i]=j; other[j]=i;
				}else{
					pairIndexToFirst[pairIndex]=i;
				}
			}
		}

		for(int i=1; i<=number*2; ++i) assert(other[i]>=0);
		assert(other[0]==0); // this one is unused

		auto const myOther=[&](int value){ return value<=number ? value+number: value-number; };
		std::vector<int> set1; set1.reserve(number);
		for(int i=1; i<=number*2; ++i) if(other[i]>=0){ // visited -> other=0
			int value=i;
			do{
				assert(value>=0);
				auto const tmp=other[value]; other[value]=-1;
				value=tmp;
				assert(value>=0);
				other[value]=-1;
				value=myOther(value);

				set1.push_back(value);
			}while(value!=i);
		}

		assert((int)set1.size()==number);
		if(std::accumulate(begin(set1), end(set1), (int64_t)0)%(number*2)!=0)
			for(auto const it: set1) std::cout<<myOther(it)<<' ';
		else
			for(auto const it: set1) std::cout<<it<<' ';
		std::cout<<'\n';
	}
}