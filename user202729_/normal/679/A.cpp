#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<vector>

bool ask(int x){
	std::cout<<x<<std::endl;
	char c;std::cin>>c;
	std::cin.ignore(5,'\n');
	return c=='y';
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::vector<int> primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89};
	int i=0;
	while(primes[i]<=10){
		if(ask(primes[i])){
			int j=i;
			while(primes[i]*primes[j]<=100){
				if(ask(primes[i]*primes[j])){
					std::cout<<"composite\n";
					return 0;
				}
				++j;
			}
			std::cout<<"prime\n";
			return 0;
		}
		++i;
	}
	std::cout<<"prime\n";
}