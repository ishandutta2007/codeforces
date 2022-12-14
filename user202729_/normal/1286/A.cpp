// Easy-to-prove O(n^3) algorithm.
// There's also a hard-to-prove (and can be hard-to-implement) O(n) algorithm.
#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<vector>
#include<array>
#include<algorithm>
#include<cstring>
#include<climits>


int n;
int solve(auto a,auto more){
	int out=0;
	if(more[0]+more[1]==n){
		out=1;
	}else{
		for(int z=0;z<2;++z){
			int i=0;
			while(a[i]<0) ++i;
			while(i and more[a[i]]){
				a[i-1]=a[i];
				--more[a[i]];
				--i;
			}
			std::reverse(begin(a),end(a));
		}

		for(int z=0;z<2;++z){
			for(int i=1;i<n;++i) if(a[i-1]>=0 and a[i]<0 and more[a[i-1]]){
				--more[a[i-1]];
				a[i]=a[i-1];
			}
			std::reverse(begin(a),end(a));
		}

		for(auto& x:a)if(x<0){
			for(int z=0;;++z){
				if(more[z]){ x=z; --more[z]; break; }
			}
		}
		for(int i=1;i<a.size();++i)out+=a[i-1]!=a[i];
	}
	return out;
}

std::vector<int> a;
std::array< std::array< std::array< std::array< int, 2>, 101>, 101>, 101> dpmem;

int dp(int i,int more0,int more1,int nxt){
	if(i==0) return 0;
	auto& mem=dpmem[i][more0][more1][nxt];
	if(mem<0){
		mem=INT_MAX;
		if(a[i-1]<0){
			if(more0) mem=std::min(mem, dp(i-1,more0-1,more1,0)+(nxt!=0));
			if(more1) mem=std::min(mem, dp(i-1,more0,more1-1,1)+(nxt!=1));
		}else
			mem=dp(i-1,more0,more1, a[i-1])+(nxt!=a[i-1]);
	}
	return mem;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::cin>>n;
	a.resize(n);
	std::array<int,2> more{n/2,(n+1)/2};
	for(int& x:a){
		std::cin>>x;
		if(x==0) x=-1; else{
			x&=1;
			--more[x];
		}
	}

	std::memset(&dpmem, -1, sizeof dpmem);
	std::cout<<std::min(
			dp(n,more[0],more[1],true),
			dp(n,more[0],more[1],false)
			)<<'\n';
}