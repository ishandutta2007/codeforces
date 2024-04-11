#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

void up();
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTest; std::cin>>numTest;
	while(numTest--) up();
}

void up(){
	int number, numMatch, numPartial; std::cin>>number>>numMatch>>numPartial;
	std::vector<int> guess(number);
	std::vector<int> count(number+1);
	for(auto& it: guess){
		std::cin>>it;
		--it;
		++count[it];
	}
	auto const missing=int(std::find(begin(count), end(count), 0)-count.begin());

	auto const k=number-numMatch; // some variable used in the proof~
	auto const miss=number-numPartial;

	std::vector<int*> rest; rest.reserve(number);
	int numMatchLeft=numMatch;
	for(auto& it: guess) if(count[it]>(k+miss)/2){
		// put it in matching group
		if(numMatchLeft==0){
			std::cout<<"NO\n";
			return;
		}
		numMatchLeft--;
		--count[it];
	}else{
		rest.push_back(&it);
	}
	for(auto it: count) assert(it<=(k+miss)/2);

	while(numMatchLeft--){
		--count[*rest.back()];
		rest.pop_back();
	}

	std::sort(begin(rest), end(rest),[&](auto first, auto sec){return*first<*sec;});
	std::vector<int> values; values.reserve(rest.size());
	int numMissingLeft=miss;
	for(auto& it: rest) if(count[*it]>(k-miss+1)/2){
		values.push_back(missing);
		--count[*it];
		--numMissingLeft;
	}else{
		values.push_back(*it);
	}
	assert(values.size()==rest.size());
	for(auto it: count) assert(it<=(k-miss+1)/2);

	count.clear();
	for(int index=0; index<(int)rest.size(); ++index) if(values[index]!=missing){
		if(numMissingLeft==0) break;
		numMissingLeft--;
		values[index]=missing;
	}

	std::rotate(values.begin(), values.end()-(k-miss+1)/2, values.end());
	for(int index=0; index<(int)rest.size(); ++index) *rest[index]=values[index];

	std::cout<<"YES\n";
	for(auto it: guess) std::cout<<it+1<<' ';
	std::cout<<'\n';
}