// time-limit: 1000
// problem-url: https://codeforces.com/contest/1610/problem/C


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
	std::vector<int> a(n), b(n);
	for(int i=0; i<n; ++i){
		std::cin>>a[i]>>b[i];
	}

	auto const check=[&](int value){
		if(value>n) return false;
		int pos=-1;
		for(int i=0; i<value; ++i){
			++pos;
			if(pos==n) return false;
			while(not(b[pos]>=i and a[pos]>=value-1-i)){
				++pos;
				if(pos==n) return false;
			}
		}
		return true;
	};

	int result=1;
	for(int step=1<<(31^__builtin_clz(n)); step; step>>=1) if(check(result+step)) result+=step;
	
	std::cout<<result<<'\n';
}