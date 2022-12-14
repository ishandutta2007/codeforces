#include<iostream>
#ifdef Sublime
#include<sstream>
std::stringstream I(R"(
3
1 2 4

4
6 9 15 30

3
1 1 1

2
100019 200038
)");
#else
auto&I=std::cin;
#endif
auto&O=std::cout;

#include<vector>
#include<algorithm>

int main(){
	int n;

	int constexpr MAX_A=15000000;
	std::vector<int> sieve(MAX_A+1);
	unsigned i;for(i=2;i*i<=MAX_A;++i){
		if(sieve[i]!=0)continue;
		sieve[i]=i;
		for(unsigned j=i*i;j<=MAX_A;j+=i)
			if(sieve[j]==0)
				sieve[j]=i;
	}
	for(;i<=MAX_A;++i)
		if(sieve[i]==0)
			sieve[i]=i;

	while(I>>n){
		std::vector<int> data(n);
		int gcd_all=0;
		for(int& x:data){
			I>>x;
			gcd_all=std::__gcd(x,gcd_all);
		}
		data.erase(std::remove(data.begin(),data.end(),gcd_all),data.end());
		if(data.empty()){
			O<<"-1\n";
			continue;
		}
		if(gcd_all!=1){
			for(int& x:data)
				x/=gcd_all;
		}

		std::vector<int> nNumDivisibleByPrime(MAX_A+1);
		for(int x:data){
			while(x!=1){
				int p;
				p=sieve[x];
				do{
					x/=p;
				}while(sieve[x]==p);
				++nNumDivisibleByPrime[p];
			}
		}
		O<<n-*std::max_element(nNumDivisibleByPrime.begin(),nNumDivisibleByPrime.end())<<'\n';
	}
}