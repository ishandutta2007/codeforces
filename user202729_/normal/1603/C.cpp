// time-limit: 4000
// problem-url: https://codeforces.com/contest/1603/problem/C



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
	int n; std::cin>>n;
	std::vector<int> a(n);
	for(auto& it: a) {
		std::cin>>it;
	}
	
	std::vector<int> k(n, 1), v(n);
	int64_t result {};
	int64_t cur {};
	int const MOD=998244353;
	for(int r=2; r<=n; ++r){
		v[r-1]=a[r-1];

		auto const ceildiv=[&](int a, int b){return (a+b-1)/b;};
		for(int i=r-2; i>=0; --i){
			cur-=int64_t(k[i]-1)*(i+1);
			k[i]=ceildiv(a[i], v[i+1]);
			cur+=int64_t(k[i]-1)*(i+1);
			if(v[i]==a[i]/k[i]) break;
			v[i]=a[i]/k[i];
		}

		result=(result+cur)%MOD;
	}
	std::cout<<result<<'\n';
	
}