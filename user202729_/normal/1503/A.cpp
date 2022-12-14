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
	std::string s; s.reserve(n); std::cin>>s;
	if(s[0]=='0' or s.back()=='0' or std::count(begin(s), end(s),'0')%2!=0){
		std::cout<<"NO\n";
	}else{
		std::cout<<"YES\n";
		int x=0;
		for(auto& a: s) if(a=='1') {
			a=x<<1|x;
			x=not x;
		}
		assert(s[0]==(0<<1|0));
		s[0]=(1<<1|1);
		assert(s.back()==(1<<1|1));
		s.back()=(0<<0|0);

		x=0;
		for(auto& a: s){
			if(a=='0') {
				a=x<<1|(not x);
				x=not x;
			}
		}

		for(auto a: s) std::cout<<(a>>1 ? '(': ')');
		std::cout<<'\n';
		for(auto a: s) std::cout<<(a&1 ? '(': ')');
		std::cout<<'\n';
	}
}