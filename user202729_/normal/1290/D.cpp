// { ":(" }
// [I didn't read the editorial]
//
// {NOTE spoiler below}



















































// Idea (mostly failed):
// * for k=1: obviously just consider every pair, #op = n**2 * 0.5 < max n**2 * 1.5
// * for k=n: sweep once from left to right, #op = n < max = n * 1.5
// * for k=2: tried using the mod field (cyclic x => x*i % n for i=1..k)
//  => hard (not fixed order)
//  - all odd mod's ends with '00..01' (block len = ctz(k)) ==> n log n values.
//  - fully cyclic (so every odd value has a multiplicative inverse mod n): need n+2k ops per mod.
//  => fails when n+2k >= 3/2 * n?
// * consider the special case k = n/2 => alternate block order
// 
// UPD: Miscalculated the number of operations...
// Obviously. It cannot be that easy.
// However it's possible to apply the same optimization used int the special case n = 1.
//
// === Tested. Must be correct. ===
// UPD: The checker only checked that the query limit is not exceeded...
// Fixed.

#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	int n,k;std::cin>>n>>k;

	assert((n xor (n-1))>=n);
	assert((k xor (k-1))>=k);
	assert(k<=n);

	assert(3LL*n*n / (2*k) <= 15000);
	int nquery=0;

	std::vector<char> ok(n,true);

	int const block=k==1 ? 1 : k/2;
	assert(n==1 or n/block>=2);
	for(int d=1;d<n/block;++d){
		for(int mod=0;mod<d;++mod)
		if(mod+d<n/block){
			std::cout<<"R\n";
			for(int i=mod;i<n/block;i+=d)
				for(int x=i*block;x<i*block+block;++x){
					++nquery;
					std::cout<<"? "<<x+1<<'\n';
					char ch;std::cin>>ch;
					if(ch=='Y') ok[x]=false;
				}
		}
	}

	assert(nquery <= 3LL*n*n / (2*k));
	std::cout<<"! "<<std::accumulate(begin(ok),end(ok),0)<<'\n';
}