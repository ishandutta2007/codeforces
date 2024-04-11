// Intended algorithm.
// I had to read the last line of the editorial	to verify the intended complexity.
// (although that is not too hard to guess, given the time limit)


#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;

	struct Item{
		int value, index, root; // if the split is right above this value
		bool operator<(Item other) const{ return value<other.value; }
		bool operator==(Item other) const{ return value==other.value; }
	};

	std::vector<Item> items(number);
	std::vector<int> values(number);
	for(int index=0;index<number;++index){
		int& value=values[index]; std::cin>>value;
		items[index]={value, index, -1};
	}
	if(number==1){
		std::cout<<"0\n"<<values[0]<<'\n';
		return 0;
	}
	std::sort(begin(items),end(items));

	int maximumNumAlignment=0;
	std::vector<int> finalValue(number);
	std::set<int> pending;
	std::vector<char> compressed(number, 1);
	std::set<int> fixed;
	std::multiset<int> delta; // set of consecutive differences of elements in the set fixed
	for(int it=0;it<number;++it) {
		fixed.insert(end(fixed), it);
		pending.insert(end(pending), it);
	}
	for(int _=0;_<number-1;++_) delta.insert(1);

	int lastValue=-1; 
	for(auto &[value, index, root]: items){

		auto const updateFinalValue=[&](int first, int sec){
			// first and sec are two consecutive fixed elements
			auto const setFinalValue=[&](int first, int last){
				auto iterator=pending.lower_bound(first);
				while(iterator!=end(pending) and *iterator<=last){
					finalValue[*iterator]=value;
					iterator=pending.erase(iterator);
				}

			};

			if(compressed[first]){
				if(compressed[sec]) return;
				else setFinalValue((first+sec)/2+1, sec);
			}else{
				if(compressed[sec]) setFinalValue(first, (first+sec)/2);
				else setFinalValue(first, sec);
			}

		};

		if(value!=lastValue){
			// for split position right below (value)
			// maximumNumAlignment should only be updated when value changes.
			maximumNumAlignment=std::max(maximumNumAlignment, *delta.rbegin()/2);
			lastValue=value;
		}

		// consider the split position right above (value). Change the value at [index] from 1 to 0.
		assert(compressed[index]==1);
		compressed[index]=0;

		for(int updateIndex=std::max(index-1, 1);
				updateIndex<=std::min(index+1, number-2);
				++updateIndex) {
			if(compressed[updateIndex-1]==compressed[updateIndex] or
					compressed[updateIndex+1]==compressed[updateIndex]){
				auto [iterator, inserted]=fixed.insert(updateIndex);
				if(inserted){
					auto const previous=*std::prev(iterator);
					auto const cur=*iterator;
					auto const next=*std::next(iterator);

					delta.insert(cur-previous);
					delta.insert(next-cur);
					delta.erase(delta.find(next-previous));
				}
			}else{
				auto iterator=fixed.find(updateIndex);
				if(iterator!=end(fixed)){
					auto const previous=*std::prev(iterator);
					auto const cur=*iterator;
					auto const next=*fixed.erase(iterator);

					delta.erase(delta.find(cur-previous));
					delta.erase(delta.find(next-cur));
					delta.insert(next-previous);
				}
			}
		}

		for(int segment=std::max(index-2, 0);
				segment<=std::min(index+1, number-2);
				++segment) {
			auto iterator=fixed.upper_bound(segment);
			updateFinalValue(*std::prev(iterator), *iterator);
		}
	}

	//for(auto it: pending) finalValue[it]=items.back().value;
	assert(pending.empty());

/*
	items.erase(begin(items), std::unique(items.rbegin(), items.rend()).base());
	// so that it's faster and maximumNumAlignment is not updated with wrong values

	for(int index=0;index<number;++index) {
		if(index==0 or index==number-1 or
				(values[index-1]<=values[index] and values[index]<=values[index+1]) or
				(values[index+1]<=values[index] and values[index]<=values[index-1])){
			finalValue[index]=values[index];
			continue;
		}

		finalValue[index]=std::partition_point(begin(items),end(items),
			[&](Item item){
				auto [value, numAlignment]=tree.get(index, item.root);
				maximumNumAlignment=std::max(maximumNumAlignment, numAlignment);
				return value==1;
			})->value;
	}
	*/

	std::cout<<maximumNumAlignment<<'\n';
	for(auto item: finalValue) std::cout<<item<<' ';
	std::cout<<'\n';
}