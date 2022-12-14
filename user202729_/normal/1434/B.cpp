// Someone solved E already...
// that would be a weird strategy.
// or is that because it took me too much time to solve A?
#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	std::map<int, std::vector<int>> sets;
	// least (1-indexing, strictly greater, 0->None) -> positions (0..number)

	int position=0;
	std::vector<int> result(number);
	for(int _=0; _<number*2; ++_){
		char type; std::cin>>type;
		if(type=='+'){
			sets[0].push_back(position);
			position++;
		}else{
			assert(type=='-');
			int value; std::cin>>value;
			// should force remove the largest possible, to be the least strict (loosest?) to the future conditions
			// but still, to be valid, it must be strictly smaller than value
			//
			// after that, the remaining must be all greater than value
			//
			// in retrospect a vector is enough (instead of a map)
			assert(not sets.count(value));
			if(sets.empty() or sets.begin()->first>value){
				std::cout<<"NO\n";
				return 0;
			}

			std::vector<int> accumulated;
			while(not sets.empty() and sets.begin()->first<value){
				std::vector<int> tmp=std::move(sets.begin()->second);
				assert(not tmp.empty());
				sets.erase(sets.begin());

				// merge
				if(accumulated.size()<tmp.size()) std::swap(accumulated, tmp);
				for(auto it: tmp) accumulated.push_back(it);
			}

			// pick out one element
			assert(not accumulated.empty());
			auto const position=accumulated.back(); accumulated.pop_back();
			assert(result[position]==0);
			result[position]=value;

			// put back
			if(not accumulated.empty()){ // almost forgot this line.
				sets[value]=std::move(accumulated);
			}
		}
	}

	std::cout<<"YES\n";
	for(auto it: result){
		assert(it!=0);
		std::cout<<it<<'\n';
	}
}