#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<vector>
#include<array>
#include<iostream>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n,nquery;std::cin>>n>>nquery;

	std::vector<int> a(n);
	std::vector<std::array<int,19>> d(2*n);
	for(int i=n;i<2*n;++i){ // n * 19
		int& ai=a[i-n];std::cin>>ai;
		for(int bit=0;bit<19;++bit){
			if(ai>>bit&1)
				d[i][bit]=ai;
			else
				d[i][bit]=1<<bit;
		}
	}
	for(int i=n;--i;){ // n * 19 * 19
		for(int bit=0;bit<19;++bit)
			for(int x=d[i*2][bit];x;x^=x&-x)
				d[i][bit]|=d[i*2+1][__builtin_ctz(x)];
	}

	while(nquery--){
		int l,r;std::cin>>l>>r;
		--l;

		int cur=a[l];
		auto const proc=[&](std::array<int,19> const& a){ // 19
			int newcur=0;
			for(int x=cur;x;x^=x&-x)
				newcur|=a[__builtin_ctz(x)];
			cur=newcur;
		};

		int r0=r;
		l+=n;r+=n; // NOTE error prone
		std::vector<std::array<int,19>*> pendr;

		while(l<r){ // log n * 19
			if(l&1)proc(d[l++]);
			if(r&1)pendr.push_back(&d[--r]);
			l>>=1;r>>=1;
		}
		while(not pendr.empty()){ // log n * 19
			proc(*pendr.back());pendr.pop_back();
		}

		std::cout<<((cur&a[r0-1])?"Shi\n":"Fou\n");
	}
}