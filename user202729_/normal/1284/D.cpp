// :(
#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>


struct interval{
	int first,last; // moment endpoint
};


int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numLecture;
	std::cin>>numLecture;
	std::vector<interval> a(numLecture),b(numLecture);
	for(int i=0;i<numLecture;++i){
		std::cin>>a[i].first>>a[i].last>>b[i].first>>b[i].last;
		--a[i].first;
		--b[i].first;
	}

	for(int _=0;_<2;++_) {
		std::swap(a, b);
		struct event{
			bool open;
			int y, left, right;
		};
		std::vector<event> events;
		events.reserve(numLecture*2);
		for(int i=0;i<numLecture;++i) {
			events.push_back({true, a[i].first, b[i].first, b[i].last});
			events.push_back({false, a[i].last, b[i].first, b[i].last});
		}
		assert(events.size()==numLecture*2u);
		std::sort(begin(events),end(events),[](auto one, auto two){
			return one.y<two.y;
		});

		std::multiset<int> lefts, rights;
		for(int last=0,i=1;i<=(int)events.size();++i) if(i==(int)events.size() or events[i].y!=events[i-1].y){
			for(int index=last;index<i;++index) {
				auto [open,_, left, right]=events[index];
				if(open){
					lefts.insert(left); rights.insert(right);
				}else{
					lefts.erase(lefts.find(left)); rights.erase(rights.find(right));
				}
			}
			if(not lefts.empty() and not rights.empty() and *lefts.rbegin()>=*rights.begin()){
				std::cout<<"NO\n";
				return 0;
			}
			last=i;
		}
		assert(lefts.empty() and rights.empty());
	}
	std::cout<<"YES\n";
}