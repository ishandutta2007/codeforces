#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

template<class F>
struct RangeMinimum{
	std::vector<std::vector<int>> table;
	F f;
	RangeMinimum(std::vector<int> data, F _f): table{std::move(data)}, f(std::move(_f)){
		for(unsigned step=1; step<table.back().size(); step<<=1){
			table.emplace_back();
			auto const& a=table.end()[-2];
			table.back().assign(a.begin(), a.end()-step);
			std::transform(a.begin()+step, a.end(), table.back().begin(), table.back().begin(), f);
		}
	}
};

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::istream_iterator<int> iter(std::cin);
	std::vector<int> data(2+*iter++);
	std::copy_n(iter, data.size(), data.begin());

	auto minimum=RangeMinimum{data, [&](auto first, auto sec){return std::min(first, sec);}};
	auto maximum=RangeMinimum{data, [&](auto first, auto sec){return std::max(first, sec);}};

	auto const possible=[&](int value)->bool{
		assert(value>=std::abs(data[0]-data[1]));
		int last=0;
		for(int index=0; index<(int)data.size()-1; ++index){
			if(index<=last and std::abs(data[index]-data[index+1])<=value){
				auto right=index+1;
				auto const cur=data[index];
				int min=data[right], max=data[right];
				assert(minimum.table.size()==maximum.table.size());
				for(auto layer=minimum.table.size(); layer-->0;) if(right+1<(int)minimum.table[layer].size()){
					auto const minNext=std::min(min, minimum.table[layer][right+1]);
					auto const maxNext=std::max(max, maximum.table[layer][right+1]);
					if(std::max(std::abs(cur-minNext), std::abs(cur-maxNext))<=value){
						std::tie(right, min, max)=std::tuple(right+(1<<layer), minNext, maxNext);
					}
				} // find maximum right such that maximum(abs(cur-data[index+1... right+1[))<=value

				for(int j=index+1; j<=right; ++j)
					assert(std::abs(cur-data[j])<=value);
				assert(right==(int)data.size()-1 or std::abs(cur-data[right+1])>value);
				last=std::max(last, right);
			}
		}
		return last==(int)data.size()-1;
	};

	auto result=*std::max_element(begin(data), end(data))-*std::min_element(begin(data), end(data));
	for(auto step=1<<30; step; step>>=1)
		if(result-step>=std::abs(data[0]-data[1]) and possible(result-step))
			result-=step;
	std::cout<<result<<'\n';
}