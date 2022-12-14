// :(((
// I did consider this case in the solution! Just "forgot" to implement it.
#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int const debug=
#if LOCAL
1
#else
0
#endif
;

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	struct T{int value; bool flipped;};
	std::vector<T> pairs(number);

	std::vector<std::pair<int, int>> data;

	for(int _=0; _<number; ++_){
		int a, b; std::cin>>a>>b;
		
		--a;--b;

		if(debug) data.push_back({a, b});

		if((a<number)==(b<number)){
			std::cout<<"-1\n"; return 0; // pretty sure...
		}
		if(a<number){ pairs[a]={b-number, false}; }
		else{ pairs[b]={a-number, true}; }
	}

	struct U{
		int value;
		std::array<int, 2> count;
	};
	std::vector<U> queue;

	auto const naive=[&]{
		for(int count=0; count<=number; ++count){
			for(int mask=0; mask<(1<<number); ++mask) if(__builtin_popcount(mask)==count){
				auto tmp=data;
				for(int i=0; i<number; ++i)
					if(mask>>i&1) std::swap(tmp[i].first, tmp[i].second);
				std::sort(begin(tmp), end(tmp), [&](auto const& first, auto const& sec){
					return first.first<sec.first;
				});
				if(std::is_sorted(begin(tmp), end(tmp),
							[&](auto const& first, auto const& sec){
								return first.second>sec.second;
							}))
					return count;
			}
		}
		return -1;
	};

	int failHeight=INT_MAX;
	for(auto [value, flipped]: pairs){
		if(queue.empty() or value<queue.back().value){
			queue.push_back({value, {}});
			queue.back().count[flipped]++;
		}else if(value>failHeight){
			assert(naive()==-1);
			std::cout<<"-1\n"; return 0;
		}else{
			auto const newValue=queue.back().value;

			std::array<int, 2> cur{};
			while(not queue.empty() and queue.back().value<value){
				cur[0]+=queue.back().count[0];
				cur[1]+=queue.back().count[1];
				queue.pop_back();
			}
			cur[not flipped]++;

			queue.push_back({newValue, cur});
			assert(value<failHeight); failHeight=value;
		}
	}

	int result{};
	for(auto [value, count]: queue)
		result+=std::min(count[0], count[1]);
	assert(naive()==result);
	std::cout<<result<<'\n';

}