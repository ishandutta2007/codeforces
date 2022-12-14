// ...

#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numArray, numOperation; std::cin>>numArray>>numOperation;
	struct Array{
		std::vector<int> values;
		int64_t sum;
	};
	std::vector<Array> arrays(numArray);
	for(auto& [values, sum]: arrays){
		int number; std::cin>>number;
		values.resize(number);
		for(auto& values: values) std::cin>>values;
		if((int)values.size()>numOperation)
			values.erase(values.begin()+numOperation, values.end());
		sum=std::accumulate(begin(values), end(values), (int64_t)0);
	}

	// data: (maximum sum with length)
	auto const addData=[&](std::vector<int64_t> data, int left, int right){
		assert(left<right);
		for(int index=left; index<right; ++index){
			auto const& [values, sum]=arrays[index];
			auto const l=(int)values.size();
			for(int i=(int)data.size()-l; i--;)
				if(data[i]>=0)
					data[i+l]=std::max(data[i+l], data[i]+sum);
		}
		return data;
	};
	int64_t result{};
	auto const work=[&](auto work, int left, int right, std::vector<int64_t> data){
		if(left+1==right){
			int64_t curTotal{};
			for(int curLength=0;;){
				if(data[numOperation-curLength]>=0)
					result=std::max(result, data[numOperation-curLength]+curTotal);

				if(curLength==(int)arrays[left].values.size()) break;
				curTotal+=arrays[left].values[curLength];
				++curLength;
			}
			assert(curTotal==arrays[left].sum);
			return;
		}
		int const middle=(left+right)>>1;
		work(work, left, middle, addData(data, middle, right));
		work(work, middle, right, addData(std::move(data), left, middle));
	};

	std::vector<int64_t> tmp(numOperation+1, -1);
	tmp[0]=0;
	work(work, 0, numArray, std::move(tmp));
	std::cout<<result<<'\n';
}