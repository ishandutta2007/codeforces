#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	std::vector<std::pair<int, int>> changes; changes.reserve(number*2);
	int64_t result{};
	for(int _=0; _<number; ++_){
		int a, c; std::cin>>a>>c;
		changes.push_back({a, 1}); changes.push_back({a+c, -1});
		result+=c;
	}
	std::sort(begin(changes), end(changes));
	int degree{};
	int last=changes[0].first;
	for(auto [a, b]: changes){
		if(degree==0){
			assert(b==1);
			result+=a-last;
		}
		degree+=b;
		last=a;
	}
	std::cout<<result<<'\n';

}