#ifndef LOCAL
#define NDEBUG
#endif
#include<numeric>
#include<cassert>
#include<tuple>
#include<vector>
#include<algorithm>
#include<iostream>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;

	if((n&1)!=0){
		std::cout<<"NO\n";
	}else{
		std::cout<<"YES\n";
		std::vector<int> a(n);

		int k=1,i=n;
		while(k-n<=0)k=k*2+1;

		while(i>0){
			int j=i;
			while(k-j<=i and j>0){
				a[j-1]=k-j;
				--j;
			}

			i=j;
			k>>=1;
		}

		for(int i=0;i<n;++i)assert((a[i]&(i+1))==0);
		for(int x:a)std::cout<<x<<' ';
		std::cout<<'\n';
	}

	if((n&(n-1))==0 // power of 2
			or n<6){
		std::cout<<"NO\n";
	}else{
		std::cout<<"YES\n";
		std::vector<int> a(n);

		if(n==6){ a={3,6,2,5,1,4}; }
		else{
			std::iota(begin(a),end(a),1);
			for(int i=7;i<n;){
				int j=i+1;
				while(j<n and (a[i]&a[j]))
					++j;
				std::rotate(begin(a)+i,begin(a)+i+1,begin(a)+j);
				i=j;
			}
			std::swap(a[2-1],a[3-1]);
			std::swap(a[4-1],a[6-1]);
			std::tie(a[1-1],a[5-1],a[7-1])=std::make_tuple(a[5-1],a[7-1],a[1-1]);
		}

		for(int i=0;i<n;++i)assert((a[i]&(i+1))!=0);
		for(int x:a)std::cout<<x<<' ';
		std::cout<<'\n';
	}
}