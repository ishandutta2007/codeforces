// TODO solve C?
#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int q; std::cin>>q; while(q--){
		int u, v; std::cin>>u>>v;
		std::cout<<([&]{
			if(u>v) return false;
			if(u==v) return true;
			int const firstDiff=31^__builtin_clz(u^v);
			assert(not(u>>firstDiff&1));
			assert(v>>firstDiff&1);
			int degree=0;
			for(int i=0; i<=firstDiff; ++i){
				degree+=u>>i&1;
				degree-=v>>i&1;
				if(degree<0) return false;
			}
			return true;
		}() ?  "YES\n" : "NO\n");
	}
}