#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int ntest;std::cin>>ntest;
	while(ntest--){
		int n,pos,nfix;std::cin>>n>>pos>>nfix;
		--pos;
		nfix=std::min(pos,nfix); // greater doesn't help
		std::vector<int> a(n);for(int& x:a)std::cin>>x;

		int out=-1;
		for(int i=0;i<=nfix;++i){
			int tmp=INT_MAX;
			for(int l=i;l<=i+pos-nfix;++l){
				tmp=std::min(tmp,std::max(a[l],a[l+n-pos-1]));
			}
			assert(tmp!=INT_MAX);
			out=std::max(out,tmp);
		}
		std::cout<<out<<'\n';
	}
}

// But Rust compiles faster... (I didn't try disabling bits/stdc++.h)