// time-limit: 1000
// problem-url: https://codeforces.com/contest/1523/problem/A

// ... combined div 1+2 again.
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
	int m; std::cin>>m;
	std::string a; std::cin>>a;

	assert((int)a.size()==n);

	if(std::any_of(begin(a), end(a), [&](auto const& it){
		return it=='1';
	})){
		int i=0;
		while(a[i]=='0') i++;
		for(int _=0; _<m; ++_){
			if(i-1<0) break;
			i--;
			a[i]='1';
		}

		int j=n-1;
		while(a[j]=='0') j--;
		for(int _=0; _<m; ++_){
			if(j+1>=n) break;
			j++;
			a[j]='1';
		}

		for(int k=i, firstZeroBlock=-1; k<=j; ++k){
			if(a[k]=='0'){
				if(firstZeroBlock<0)
					firstZeroBlock=k;
			}else{
				if(firstZeroBlock>=0){
					assert(firstZeroBlock<=k-1);
					assert(a[k-1]=='0');

					auto const blockLen=k-firstZeroBlock;
					assert(blockLen>0);

					for(int l=std::min(m, blockLen>>1); l--;)
						a[firstZeroBlock+l]=a[k-1-l]='1';
						
					firstZeroBlock=-1;
				}
			}
		}
	}
		
	std::cout<<a<<'\n';
		

}