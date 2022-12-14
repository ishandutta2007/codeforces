#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	std::vector<int> minFactor(number+1),
		mob(number+1, 1); // Mobius function
	for(int prime=2; prime<(int)minFactor.size(); ++prime)
		if(minFactor[prime]==0){
			for(int multiple=prime; multiple<(int)minFactor.size(); multiple+=prime){
				mob[multiple]*=-1;

				if(minFactor[multiple]==0)
					minFactor[multiple]=prime;

				assert(mob[prime]==-1);
			}
			if((int64_t)prime*prime<(int)minFactor.size())
				for(int multiple=prime*prime; multiple<(int)minFactor.size(); multiple+=prime*prime)
					mob[multiple]=0;
		}

	/*
	int64_t result{};
	std::array<int, 4> value{};
	for(int x=2; x<=number; ++x)
		for(int y=2; y<x; ++y){
			int distance;
			if(std::gcd(x, y)!=1)
				distance=1;
			else if((int64_t)minFactor[x]*minFactor[y]<=number)
				distance=2;
			else if((x<=number/2 or x!=minFactor[x]) and (y<=number/2 or y!=minFactor[y]))
				distance=3;
			else continue;
			
			value[distance]++;
			result+=distance;
		}

	std::cout<<result<<'\n';
	return 0;
	// */

	std::vector<int> countMinFactor(number/2+1);
	int total{}; // number of nodes having any adjacent edge
	for(int x=2; x<=number; ++x)
		if(minFactor[x]<(int)countMinFactor.size()){
			total++;
			countMinFactor[minFactor[x]]++;
		}

	auto const c2=[&](int64_t it){return (it*(it-1))>>1;};

	int64_t numPair1{};
	for(int d=2; d<=number; ++d)
		numPair1-=mob[d]*c2(number/d);
	assert(numPair1>=0);

	int64_t numPair3{};
	std::vector<int> countMinFactorGE=countMinFactor;
	for(int index=(int)countMinFactorGE.size()-1; index--;)
		countMinFactorGE[index]+=countMinFactorGE[index+1];

	for(int a=3; a<(int)countMinFactor.size()-1; ++a){
		numPair3+=(int64_t)countMinFactor[a]*(
				countMinFactorGE[std::max(a+1, number/a+1)]
				);
	}

	int64_t numPair2=c2(total)-numPair1-numPair3;
	assert(numPair2>=0);
	std::cout<<
		1*numPair1+
		2*(c2(total)-numPair1-numPair3)+
		3*numPair3
		<<'\n';
}