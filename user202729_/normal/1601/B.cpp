// time-limit: 2000
// problem-url: https://codeforces.com/contest/1601/problem/B
#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n; std::cin>>n;
	std::vector<int> a(n);
	for(auto& it: a) {
		std::cin>>it;
	}
	
	std::vector<int> b(n);
	for(auto& it: b) {
		std::cin>>it;
	}

	struct T{int trace, distance;};
	std::vector<T> data(n, {INT_MAX, INT_MAX}); // [jumped] = {last jumped, curDistance}
	std::vector<int> queue;
	queue.push_back(n-1); data[n-1]={.trace=-1, .distance=0};

	for(int queueIndex=0; queueIndex<(int)queue.size(); ++queueIndex){ // ...
		auto const pos=queue[queueIndex];
		auto const curDistance=data[pos].distance;
		auto slipped=pos+b[pos];
		if(slipped-a[slipped]<0){
			assert(slipped-a[slipped]==-1);
			
			std::vector<int> trace{-1, pos};
			while(trace.back()!=n-1)
				trace.push_back(data[trace.back()].trace);

			trace.pop_back();

			std::cout<<trace.size()<<'\n';
			for(auto index=trace.size(); index--;)
				std::cout<<trace[index]+1<<' ';
			std::cout<<'\n';

			return 0;
		}

		for(int jumped=slipped-a[slipped]; data[jumped].distance==INT_MAX; jumped++){
			data[jumped]={.trace=pos, .distance=curDistance+1}; // this is GCC extension but it's convenient...
			queue.push_back(jumped);
		}
	}

	std::cout<<"-1\n";

}