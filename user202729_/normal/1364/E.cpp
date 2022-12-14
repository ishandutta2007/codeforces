#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>


#define let auto const


std::mt19937 engine(
#if LOCAL
		123456
#else
		std::chrono::duration_cast<std::chrono::nanoseconds>(
			std::chrono::steady_clock::now().time_since_epoch()).count()
#endif
		);

int ask(int first, int sec){
	std::cout<<"? "<<first+1<<' '<<sec+1<<std::endl;
	int result; std::cin>>result;
	assert(std::cin);
	return result;
}

int number;

std::vector<int> value;

int solve(std::vector<int> indices, unsigned mask){
	// indices: indices with value being a strict subset of mask
	assert(mask!=0);
	if(indices.size()==1){
		value[indices[0]]=0;
		return indices[0];
	}
	assert(__builtin_popcount(mask)!=1);
	assert(indices.size()==[&]{
		unsigned result{};
		for(unsigned i=0; i<(unsigned)number; ++i)
			result+=(i&mask)==i and i!=mask;
		return result;
	}());

	int item;
	if(mask==~(unsigned)0 and number>=20){
		assert((int)indices.size()==number);
		std::vector<std::pair<int, int>> items;
		for(int _=0; _<16; ++_){
			do{
				item=std::uniform_int_distribution(0, number-1)(engine);
			}while(value[item]>=0);

			unsigned valueItemApproximate=~(unsigned)0;
			for(int _=0; _<8; ++_){
				int other=std::uniform_int_distribution(0, number-2)(engine);
				if(other>=item) ++other;
				valueItemApproximate&=ask(item, other);
			}

			items.push_back({valueItemApproximate, item});
		}
		item=std::min_element(begin(items), end(items),[&](auto first, auto sec){
			return __builtin_popcount(first.first)<__builtin_popcount(sec.first);
		})->second;
	}else{
		item=indices[std::uniform_int_distribution(0, (int)indices.size()-1)(engine)];
	}


	std::vector<std::pair<int, int>> results; // list of {value[item]|value[index], index}
	results.reserve(indices.size()-1);
	for(let other: indices) if(other!=item)
		results.push_back({ask(other, item), other});
	assert(results.size()==indices.size()-1);

	assert(results.size()>=2);

	//std::sort(begin(results), end(results));
	std::nth_element(begin(results), results.begin()+1, end(results));

	if((results[0].first&results[1].first)==0){
		value[item]=0;
		return item; // found position of 0
	}else{
		let valueItem=results[0].first;

		value[item]=valueItem;

		indices.clear();
		for(let [value, index]: results){
			if(value==valueItem)
				indices.push_back(index);
		}
		return solve(std::move(indices), valueItem);
	}
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::cin>>number;
	std::vector<int> indices(number);
	std::iota(begin(indices), end(indices), 0);

	value.assign(number, -1);

	let index0=solve(indices, ~(unsigned)0);
	assert(value[index0]==0);

	for(int index=0; index<number; ++index){
		if(value[index]<0) value[index]=ask(index0, index);
	}

	std::cout<<'!';
	for(let it: value) std::cout<<' '<<it;
	std::cout<<'\n';
}