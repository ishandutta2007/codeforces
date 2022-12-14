// it feels like a long time since I last submitted here...
// I still frequently solve problems on PE however.
#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::vector<int> a(6); for(auto& it: a) std::cin>>it;
	std::sort(begin(a), end(a)); // oh nice, the statement contains unsorted examples, but I didn't forget it this time
	int n; std::cin>>n;
	
	struct T{
		int delta, pos;
		bool operator<(T other) const{return delta>other.delta;}
	};
	std::priority_queue<T> data; // top=minimum
	int maxDelta=INT_MIN;
	for(int _=0; _<n; ++_){
		int value; std::cin>>value;
		int const pos=(int)a.size()-1;
		auto const delta=value-a[pos];
		data.push({delta, pos});
		maxDelta=std::max(maxDelta, delta);
	}
	int result=INT_MAX;
	while(true){
		auto const [delta, pos]=data.top(); data.pop();
		if(delta>=0){
			assert(maxDelta>=delta);
			result=std::min(result, maxDelta-delta);
		}
		if(pos>0){
			auto const pos1=pos-1;
			auto const delta1=delta+a[pos]-a[pos1];
			data.push({delta1, pos1});
			maxDelta=std::max(maxDelta, delta1);
		}else break;
	}
	std::cout<<result<<'\n';
}