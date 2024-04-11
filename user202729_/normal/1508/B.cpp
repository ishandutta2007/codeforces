
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
	int64_t k; std::cin>>k;
	--k;

	if(n<=62 and k>=((int64_t)1<<(n-1))){
		std::cout<<"-1\n";
		return;
	}

	std::vector<int> result(n);
	for(int i=0; i<n; ++i) result[i]=i+1;
	for(int i=0; i<n;){
		if(0<=n-i-2 and n-i-2<=62 and (k>>(n-i-2)&1)){
			int j=i;
			while(j<n and 0<=n-j-2 and (k>>(n-j-2)&1)) ++j;
			int delta=j-i+1; // >= 2
			std::reverse(result.begin()+i, result.begin()+i+delta);
			i+=delta;
		}else{
			++i;
		}
	}
	
	for(auto const& it: result){
		std::cout<<it<<' ';
	}
	std::cout<<'\n';
	
}