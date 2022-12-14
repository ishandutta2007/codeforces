// ... right.
#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int left; std::cin>>left;
	int right; std::cin>>right;
	int n=2, maximum=1;
	while(maximum<right-left+1){
		++n;
		maximum<<=1;
	}
	std::vector<std::array<int, 3>> edges;
	for(int index=1; index<n; ++index){
		for(int other=index+1; other<n; ++other){
			edges.push_back({index, other,
				index==1 ? 1: (1<<(index-2))
			});
		}
	}

	int lastAdd=left-1;
	left-=lastAdd; right-=lastAdd; assert(left==1);

	for(int index=n-1; index>=1; index--){
		int left1=0, right1=0;
		if(index>1){ left1=1; right1=1<<(index-2); }

		// region spanned by node index (inclusive)
		if(right>right1){
			edges.push_back({index, n, right-right1+lastAdd});
			right-=right1-left1+1;
		}
	}
	assert(right==0);

	//if(lastAdd){
	//	++n;
	//	edges.push_back({n-1, n, lastAdd});
	//}

	std::cout<<"YES\n"<<n<<' '<<edges.size()<<'\n';
	for(auto const& row: edges){
		for(auto const& cell: row){
			std::cout<<cell<<' ';
		}
		std::cout<<'\n';
	}
	
}