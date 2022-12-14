// ...
#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int t; std::cin>>t; while(t--){
		int a, b, c, d; std::cin>>a>>b>>c>>d;
		// refer to the problem description for the meaning of the variable names...
		if(a-c*(int64_t)b>0){
			std::cout<<"-1\n";
		}else{
			int64_t maxI=a/((int64_t)d*b);
			//for(int i=0; i<=maxI; ++i) result+=a-i*d*b;
			//sorry, this is not clang
			std::cout<<
				a*int64_t(maxI+1)
				-d*(int64_t)b*maxI*(maxI+1)/2<<'\n';
		}
	}
}