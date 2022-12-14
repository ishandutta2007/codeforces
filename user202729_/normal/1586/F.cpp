// time-limit: 3000
// problem-url: https://codeforces.com/contest/1586/problem/F

// not proven

#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n; std::cin>>n;
	int k; std::cin>>k;
	int c=1, pow_k_c=k; while(pow_k_c<n){ pow_k_c*=k; c++;}
	std::cout<<c<<'\n';
	auto const baseK_cDigit=[&](int x){
		// 2^10=1024, safe
		assert(c<=10);
		std::array<int, 10> result; // result[0]: most significant digit, until result[c-1]: least significant, result[c]: undefined
		for(int i=0; i<c; ++i){
			result[c-i-1]=x%k;
			x/=k;
		}
		return result;
	};
	for(int i=0; i<n; ++i){
		auto const ik=baseK_cDigit(i);
		for(int j=i+1; j<n; ++j){
			auto const jk=baseK_cDigit(j);
			std::cout<<
				std::mismatch(begin(ik), begin(ik)+c, begin(jk)).first-begin(ik) // what a rarely used function.
				+1<<' ';
		}
	}
	std::cout<<'\n';
}