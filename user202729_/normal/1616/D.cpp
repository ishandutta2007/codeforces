// time-limit: 1500
// problem-url: https://codeforces.com/contest/1616/problem/D
#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

// too slow

void up();
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTest; std::cin>>numTest;
	while(numTest--) up();
}

void up(){
	int number; std::cin>>number;
	std::vector<int> a(number);
	for(auto& it: a) {
		std::cin>>it;
	}
	int minAverage; std::cin>>minAverage;
	
	std::vector<std::array<int, 2>> f(number+1);
	// f[prefix length][selected status of last element]=maximum number of elements selected in prefix
	// f[0].fill(0);

	int last {};
	int maxf1prev=0, maxf0range_index_=0;
	for(int index=1; index<=number; ++index){
		// segment last... index-1 can be all-selected
		// segment last... index might not be
		if(
				(index-last>=2 and a[index-1]+a[index-2]<minAverage*2)
				or
				(index-last>=3 and a[index-1]+a[index-2]+a[index-3]<minAverage*3)
				){
			last=index-1; maxf0range_index_=f[last][0]-last;
			if(index>=2 and a[index-1]+a[index-2]>=minAverage*2){
				--last;
				maxf0range_index_=std::max(maxf0range_index_, f[last][0]-last);
			}
		}

		f[index][0]=maxf1prev;
		f[index][1]=maxf0range_index_+index;

		maxf1prev=std::max(maxf1prev, f[index][1]);
		maxf0range_index_=std::max(maxf0range_index_, f[index][0]-index);
	}


	std::cout<<std::max(f.back()[0], f.back()[1])<<'\n';
}