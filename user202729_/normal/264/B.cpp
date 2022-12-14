//http://codeforces.com/contest/264/problem/B
#include<iostream>
#include<vector>
#include<cassert>
#include<array>
#include<cmath>
#include<algorithm>
std::array<int,100001> sieve; // sieve[x] is a prime factor of x for x>1, x composite
std::array<int,100001> lastIndexWithXDivisibleBy;
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);

	// initialize sieve
	for(int i=2;i<std::sqrt(sieve.size()+.01);++i)
		if(sieve[i]==0){
			for(unsigned j=i*i;j<sieve.size();j+=i)
				sieve[j]=i;
		}

	int nNum;std::cin>>nNum;
	std::vector<int> maxGoodSequenceLenEndsAt(nNum+1);
	for(int index=1;index<=nNum;++index){
		int value;std::cin>>value;
		if(value==1)continue;
		int ans=0;
		for(;;){
			int prime=sieve[value];
			if(prime==0)prime=value; // sieve[value] == 0 for prime value

			ans=std::max(ans,maxGoodSequenceLenEndsAt[lastIndexWithXDivisibleBy[prime]]);

			lastIndexWithXDivisibleBy[prime]=index;
			if(prime==value)break;
			assert(value%prime==0);
			value/=prime;
		}
		maxGoodSequenceLenEndsAt[index]=ans+1;
	}
	std::cout<<std::max(1,
			*std::max_element(maxGoodSequenceLenEndsAt.begin(),maxGoodSequenceLenEndsAt.end()))
		<<'\n';
}