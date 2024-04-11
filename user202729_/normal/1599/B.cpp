// time-limit: 1000
// problem-url: https://codeforces.com/contest/1599/problem/B

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

int64_t solveSlow(int64_t n, int64_t a, int64_t b, bool aRight, bool bRight){
	if(n==1) return 0;
	if(a==0) {aRight=true;} if(a==n-1) aRight=false;
	if(b==0) {bRight=true;} if(b==n-1) bRight=false;

	if(a==b){
		auto const old=a;
		a+=(aRight ? 1: -1);
		b+=(bRight ? 1: -1);
		assert(a!=old); assert(b!=old);
		auto const result=solveSlow(n-1, a-(a>=old), b-(b>=old), aRight, bRight);
		return result+(result>=old);
	}else{
		a+=(aRight ? 1: -1);
		return solveSlow(n, b, a, bRight, aRight);
	}
}

int64_t solveFast(int64_t n, int64_t a, int64_t b, bool aRight, bool bRight){
	if(not aRight){
		if(not bRight){
			return (
					b==n-1 and a==n-1 ? 0:
					b>=a ? ((b-a)%2==0 ? n-1: 0) :
					((b-a)%2!=0 ? n-1: 0)
				   );
		}else{
			return (
					a==0 and b==0 ? n-1:
					b<=a ? ((b-a)%2==0 ? 0: n-1):
					((b-a)%2!=0 ? 0: n-1)
				   );
		}
	}
	return n-1-solveFast(n, n-1-a, n-1-b, not aRight, not bRight);
}

void up(){
	if(0){
		for(int n=2; n<=20; ++n){
			for(int aRight=0; aRight<2; ++aRight)
				for(int bRight=0; bRight<2; ++bRight){
					for(int a=0; a<n; ++a){
						for(int b=0; b<n; ++b){
							auto const result=solveSlow(n, a, b, aRight, bRight);
							//std::cout<<result<<' ';
							

							assert(result==solveFast(n, a, b, aRight, bRight));


							assert(result==0 or result==n-1);
							std::cout<<(result==0 ? ".": "#");
						}
						std::cout<<'\n';
					}
					std::cout<<'\n';
				}
			std::cout<<"========\n";
		}
		return;
	}

	int64_t n; std::cin>>n;
	int64_t a; std::cin>>a;
	int64_t b; std::cin>>b;
	char aDir; std::cin>>aDir; std::cin.ignore(4);
	char bDir; std::cin>>bDir; std::cin.ignore(4);
	bool aRight=aDir=='r';
	bool bRight=bDir=='r';

	std::cout<<
		solveFast(n, a, b, aRight, bRight)
		<<'\n';

	
}