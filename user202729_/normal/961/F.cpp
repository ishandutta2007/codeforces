// ~
#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	std::string string; string.reserve(number); std::cin>>string;

	std::vector<std::vector<int>> segmentHash;
	segmentHash.emplace_back(begin(string), end(string));
	{
		std::vector<int> tmp, tmp2;
		std::vector<int> count; // use in counting sort

		for(int step=1;; step<<=1){
			auto const sort=[&](auto key){
				count.assign(step==1 ? 127: number, 0);
				for(auto it: tmp) ++count[key(it)];
				for(int index=1; index<(int)count.size();++index) count[index]+=count[index-1];

				std::swap(tmp, tmp2); tmp.resize(tmp2.size());
				std::for_each(tmp2.rbegin(), tmp2.rend(),[&](auto it){
					tmp[--count[key(it)]]=it;
				});
			};

			auto const& a=segmentHash.back();
			// a=hash of length step
			if(step>=(int)a.size()) break;

			std::vector<int> b(a.size()-step); // hash of length step*2
			tmp.resize(b.size()); std::iota(begin(tmp), end(tmp), 0);
			
			sort([&](auto it){return a[it+step];});
			sort([&](auto it){return a[it];});

			int last=-1; auto lastValue=std::pair(-1, -1);
			for(auto index: tmp){
				auto curValue=std::pair(a[index], a[index+step]);
				if(curValue!=lastValue){ lastValue=curValue; ++last; }
				b[index]=last;
			}
			segmentHash.push_back(std::move(b));
		}
	}

	auto const equal=[&](int left1, int left2, int len){
		auto const layer=31^__builtin_clz(len);
		auto const delta=len-(1<<layer); assert(delta>=0 and delta<len);
		return segmentHash[layer][left1]==segmentHash[layer][left2] and
			segmentHash[layer][left1+delta]==segmentHash[layer][left2+delta];
	};

	std::vector<int> result((number+1)/2);
	int last=-1;
	for(auto k=(int)result.size(); k--;){
		last+=2;
		if(last>=number-k*2) last-=2;
		while(last>=0 and not equal(k, number-k-last, last))
			last-=2;
		result[k]=last;
	}
	for(auto it: result) std::cout<<it<<' ';
	std::cout<<'\n';
}